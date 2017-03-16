#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int cmp(const void *x, const void *y)
{
  long double xx = *(long double*)x, yy = *(long double*)y;
  if (xx < yy) return -1;
  if (xx > yy) return  1;
  return 0;
}

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
	long double Naomi[1001],Ken[1001];
	uint16_t l, N, minNao, maxNao, minKen, maxKen, score;
	
	input = fopen ("input.in", "r");
	output = fopen ("output.out", "w");
	
	count = 1;
	cases = getNumber(input, 10);
	printf("%d\n",cases);
	
	
	
	while(cases>0) {
		N = getNumber(input, 10);
		minNao = N-1;
		minKen = N-1;
		maxNao = N-1;
		maxKen = N-1;
		while(minNao>0) {
			Naomi[minNao] = getReal(input, 32);
			minNao--;
		}
		Naomi[0] = getReal(input, 10);
		while(minKen>0) {
			Ken[minKen] = getReal(input, 32);
			minKen--;
		}
		Ken[0] = getReal(input, 10);
		
		qsort (Naomi, maxNao+1, sizeof (long double), cmp);
		qsort (Ken, maxKen+1, sizeof (long double), cmp);
		
		fprintf (output, "Case #%d: ", count);
		score = 0;
		l = 0;
		while(l<N) {
			if(Naomi[minNao]>Ken[minKen]) {
				score++;
				minNao++;
				minKen++;
			} else {
				minNao++;
				maxKen--;
			}
			l++;
		}
		
		fprintf (output, "%d ", score);
		
		minNao = 0;
		minKen = 0;
		maxNao = N-1;
		maxKen = N-1;
		
		score = 0;
		l = 0;
		while(l<N) {
			if(Naomi[maxNao]>Ken[maxKen]) {
				score++;
				maxNao--;
				minKen++;
			} else {
				maxNao--;
				maxKen--;
			}
			l++;
		}
		
		fprintf (output, "%d\n", score);
		count++;
		cases--;
	}
	
	return 0;
}
