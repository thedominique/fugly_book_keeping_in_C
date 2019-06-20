#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HANDELSER 100
#define WORDLENGTH 40

typedef struct handelse {
	int v_nummer;
	int datum;
	float summa;
	char kassa_handelse[WORDLENGTH];
	bool debet;
	
} handelse_t;

handelse_t create_event(int v, int d, float sum, char k_h[], bool deb){
	handelse_t input;
	input.v_nummer = v;
	input.datum = d;
	input.summa = sum;
	strcpy(input.kassa_handelse, k_h);
	input.debet = deb;
	
	return input;
}

void add_event_to_book(int *nr_of_events, handelse_t kassa_bok[], handelse_t event){
	int i = *nr_of_events;
	kassa_bok[i] = event;
	(*nr_of_events)++;
}

void get_user_input(int *nr_of_events, handelse_t kassa_bok[]){
	handelse_t ev;
	int v,d,t;
	float s;
	char h[40];
	bool b;
	printf("Add verification numer: ");
	scanf("%d", &v);
	printf("Add date : ");
	scanf("%d", &d);
	printf("Add sum : ");
	scanf("%f", &s);
	printf("Add event type : ");
	gets(h);
	printf("Debet or credet (1 = debet /0 = credit): ");
	scanf("%d", &t);
	if (t==1) {
		b = true;
	} else if (t == 0) {
		b = false;
	} else {
		printf("Error\n");
		return;
	}
	ev = create_event(v, d, s, h, b);
	add_event_to_book(nr_of_events, kassa_bok, ev);
	
}

void print_book(int nr_of_events, handelse_t kassa_bok[]){
	for(int i=0; i < nr_of_events; i++){
		printf("Verification number : %d \n", kassa_bok[i].v_nummer);
		printf("Date : %d \n", kassa_bok[i].datum);
		printf("Summa : %f \n", kassa_bok[i].summa);
		printf("Event type : %s", kassa_bok[i].kassa_handelse);
		if(kassa_bok[i].debet == true) printf("Debet\n\n");
		else printf("Kredet\n\n");
	}
}


int main(int argc, char **argv){
	int nr_of_events = 0;
	char menu_choice='i';
	handelse_t kassa_bok[MAX_HANDELSER];
	
	while(menu_choice != 'x'){
		printf("Menu\nTo enter event press e\nWant to print your book, press p\nTo exit press x\nInput : ");
		scanf(" %c", &menu_choice);
		if(menu_choice == 'e'){
			get_user_input(&nr_of_events, kassa_bok);
		} else if(menu_choice == 'p'){
			print_book(nr_of_events, kassa_bok);
		} else {
			printf("Invalid input. Try again\n");
		}
	}
	return 0;
}
