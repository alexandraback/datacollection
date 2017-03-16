//Problem: GCJ 2012 Round 1A A
//Name: Password Problem
//Author: Bruce K. B. Tong

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define SMALL
//#define LARGE

#define SIZE 99999

#define array1d(a, n) for(int i=0; i<(int)(n); i++) {cout << a[i]; cout << endl;} cout << endl;
#define array2d(a, h, w) for(int i=0; i<(int)(h); i++) {for(int j=0; j<(int)(w); j++) cout << a[i][j]; cout << endl;}
#define mem(a,b) memset(a,b,sizeof(a))

double p[SIZE];	//0 <= p[i] <= 1

void read(int &A, int &B, double p[SIZE]) {
	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> p[i];
}

//the probability that the k-th index character was typed wrongly first
double prob_type_wrong(int k, int n, double p[SIZE]) {
	double pr = 1.0;
	for (int i = 0; i < k; i++)
		pr *= p[i];
	if (k < n)
		pr *= (1.0 - p[k]);	//the wrong character
	return pr;
}

double compute(int A, int B, double p[SIZE]) {
	int retype = B + 1;
	int remain = B - A;
	int enter = 1;
	int backspace = 1;

	double prob[SIZE+1];
	for (int i = 0; i <= A; i++)	//i: the index of the first wrong character
		prob[i] = prob_type_wrong(i, A, p);	//prob[A]: perfect typing, prob[0 .. (A-1)]: imperfect typing

	double min;

	//case 4: press enter right away
	double exp4 = (double)(enter + retype);

	//case 1: keep typing
	double exp1 = 0.0;
	for (int i = 0; i <= A; i++)
		exp1 += ((double)remain + enter + retype * (i < A)) * prob[i];
	min = exp1 < exp4? exp1: exp4;

	//case 2: press backspace k times
	for (int k = 1; k <= A; k++) {
		double exp2 = 0.0;
		for (int i = 0; i <= A; i++)
			exp2 += ((double)backspace * k + remain + k + enter + retype *(A - k > i)) * prob[i];
		if (exp2 < min) min = exp2;
	}
	return min;
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt1.in", "rt", stdin);
		freopen("A-small-attempt1.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large-practice.in", "rt", stdin);
		freopen("A-large-practice.out", "wt", stdout);
	#endif

	int T;			//1 <= T <= 20
	int A;			//1 <= A <= 3 (or 99,999)
	int B;			//A < B <= 100 (or 100,000)
	//double p[SIZE];	//0 <= p[i] <= 1
	
	cin >> T;

	for (int i = 1; i <= T; i++) {
		read(A, B, p);
		cout << "Case #" << i << ": ";
		printf("%f", compute(A, B, p));
		cout << endl;
	}
	
	return 0;
}