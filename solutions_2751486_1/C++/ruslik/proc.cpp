#include <stdlib.h>
#include <stdio.h>

int n;
char* name = (char*)malloc(6<<20);
int* counts = (int*)malloc(6<<22);	// positive: wovels, negative: consonants
int counts_cnt;

int* c2 = (int*)malloc(6<<22);	// positive: wovels, negative: consonants, optimized for N
int c2_cnt;



int gen_counts() {
	counts_cnt = 0;
	c2_cnt = 0;
	int c = 0;
	for (char* s = name; *s; s++) {
		switch (*s) { 
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' : 
				if (c < 0) {
					counts[counts_cnt++] = c;
					c = 1;
				} else
					c++;
				break;
			default:
				if (c > 0) {
					counts[counts_cnt++] = c;
					c = -1;
				} else
					c--;
		};
	};
	if (c)
		counts[counts_cnt++] = c;

	c = 0;
	for (int i = 0; i < counts_cnt; i++) {
		int v = counts[i];
		if (v < 0 && -v < n)
			v = -v;
		if (v > 0) {
			if (c < 0) { 
				c2[c2_cnt++] = c;
				c = 0;
			}; 
		} else {
			if (c > 0) {
				c2[c2_cnt++] = c;
				c = 0;
			};
		};
		c += v;
	};
	if (c)
		c2[c2_cnt++] = c;
				
/*	printf("c2: ");
	for (int i = 0; i < c2_cnt; i++)	
		printf("%d ", c2[i]);
	printf("\n");*/
		
	return c2_cnt;
};


static inline long long int c_same(int len, int n) {
	if (len < n) return 0;
	long long int a = len + 1 - n;
	return a * (a + 1) / 2;
};

static inline long long int coeff(int v, int n) {
	if (v > 0) return v;
	return -v + 1 - n;
};

    
long long int solve_bf() {
	long long int rez = 0;
	for (int i = 0; i < c2_cnt; i++) {
		for (int j = i; j < c2_cnt; j++) {
			if (i == j) {
				rez += c_same(-c2[i], n);
				continue;
			};
			if (c2[i] < 0 && c2[j] < 0) {
				rez += (long long int)c2[i] * c2[j];	
				rez -= (long long int)(n-1)*(n-1);
			} else {
				rez += coeff(c2[i], n) * coeff(c2[j], n);
			};
				
			if (c2[j] < 0) {	// the rest is surely ok
				long long int s =0;
				for (int t = j + 1; t < c2_cnt; t++)
					s += (long long int)abs(c2[t]);
				rez += abs(c2[i]) * s;
				break;	// from inner for
			};
		};
	};
	return rez;
};


int solve(int ctry){
	long long int rez;
	scanf("%s %u", name, &n);
	gen_counts();
	rez = solve_bf();

	printf("Case #%d: %I64d\n", ctry, rez);
};


int main(){

	if (freopen("test.in", "rt", stdin)){
//		freopen("A-large-practice.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-small-attempt0.in", "rt", stdin)){
		freopen("A-small-attempt0.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-large.in", "rt", stdin)){
		freopen("A-large.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	return 0;
};