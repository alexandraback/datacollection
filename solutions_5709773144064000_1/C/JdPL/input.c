#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/* Reads a number until Not a Digit appears*/
uint16_t getNumber(FILE *input, uint16_t NaD) {
	uint16_t num;
	char c;
	
	num=0;
	
	c=getc(input);
	while(c!=NaD) {
		num = 10*num+c-48;
		c=getc(input);
	}
	return num;
}

/* Reads a real until Not a Digit appears*/
long double getReal(FILE *input, uint16_t NaD) {
	uint16_t count;
	long double pre, post;
	char c;
	
	pre=0;
	post=0;
	count=1;
	
	c=getc(input);
	while(c!=NaD && c!=46) {
		pre = 10*pre+c-48;
		c=getc(input);
	}
	if(c==46) c=getc(input);
	while(c!=NaD) {
		post = post+(double)(c-48)/pow(10,count);
		c=getc(input);
		count++;
	}
	
	return pre + post;
}


int main() {
	FILE *input, *output;
	uint16_t cases, count;
	long double C,F,X;
	long double time, speed;
	
	input = fopen ("input.in", "r");
	output = fopen ("output.out", "w");
	
	count = 1;
	cases = getNumber(input, 10);
	printf("%d\n",cases);
	
	while(cases>0) {
		C = getReal(input, 32);
		F = getReal(input, 32);
		X = getReal(input, 10);
		time = 0.0;
		speed = 2.0;
		printf("%Lf,%Lf,%Lf\n",C,F,X);
		
		fprintf (output, "Case #%d: ", count);
		if(C>=X) {
			fprintf (output, "%.10Lf", X/2);
		} else {
			while(X/speed > C/speed + X/(speed + F)) {
				time = time + C/speed;
				speed = speed + F;
			}
			time = time + X/speed;
			fprintf (output, "%.10Lf", time);
		}
		
		
		fprintf (output, "\n");
		count++;
		cases--;
	}
	
	return 0;
}
