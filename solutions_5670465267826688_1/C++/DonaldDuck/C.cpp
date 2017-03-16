#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <string.h>

#define MAXL 10010

using namespace std;

const int i = 2;
const int j = 3;
const int k = 4;
const int I = -2;
const int J = -3;
const int K = -4;

int molt(int a, int b) {
	if (a == 1) return b;
	if (b == 1) return a;
	if (a == -1) return -b;
	if (b == -1) return -a;
	
	if (a == i) {
		switch (b) {
			case (i): return -1;
			case (j): return k;
			case (k): return J;
			case (I): return 1;
			case (J): return K;
			case (K): return j;
		}
	}
	
	if (a == I) {
		switch (b) {
			case (i): return 1;
			case (j): return K;
			case (k): return j;
			case (I): return -1;
			case (J): return k;
			case (K): return J;
		}
	}
	
	if (a == j) {
		switch (b) {
			case (i): return K;
			case (j): return -1;
			case (k): return i;
			case (I): return k;
			case (J): return 1;
			case (K): return I;
		}
	}
	
	if (a == J) {
		switch (b) {
			case (i): return k;
			case (j): return 1;
			case (k): return I;
			case (I): return K;
			case (J): return -1;
			case (K): return i;
		}
	}
	
	if (a == k) {
		switch (b) {
			case (i): return j;
			case (j): return I;
			case (k): return -1;
			case (I): return J;
			case (J): return i;
			case (K): return 1;
		}
	}
	
	if (a == K) {
		switch (b) {
			case (i): return J;
			case (j): return i;
			case (k): return 1;
			case (I): return j;
			case (J): return I;
			case (K): return -1;
		}
	}
	
	assert(false);
}

int f(char c) {
	if (c == 'i') return i;
	if (c == 'j') return j;
	if (c == 'k') return k;
	
	assert(false);
}

bool solve() {
	long long int L, X;
	cin >> L >> X;
	char str[MAXL];
	cin >> str;
	//cout << str << endl;
	
	int A[4*MAXL];
	int B[4*MAXL];
	
	for (int h=0; h<L; h++) {
		A[h] = f(str[h]);
		A[h+L] = f(str[h]);
		A[h+L*2] = f(str[h]);
		A[h+L*3] = f(str[h]);
		B[h] = f(str[L-1-h]);
		B[h+L] = f(str[L-1-h]);
		B[h+L*2] = f(str[L-1-h]);
		B[h+L*3] = f(str[L-1-h]);
	}
	
	for (int h=1; h<4*L; h++) {
		A[h] = molt(A[h-1], A[h]);
		B[h] = molt(B[h], B[h-1]);
	}
	
	for (int h=0; h<4*L; h++) {
		//cout << A[h] << "  " << B[h] << endl;
	}
	
	long long int a = -1;
	long long int b = -1;
	for (int h=0; h<4*L; h++)
		if (A[h] == i) {
			a = h;
			break;
		}
	for (int h=0; h<4*L; h++)
		if (B[h] == k) {
			b = h;
			break;
		}
		
	//cout << "a " << a << "    b " << b << endl;	
	
	if (a == -1 || b == -1) return false;
	b = X*L - b - 1;
	if (b-a <= 1) return false;
	
	assert(a>=0);
	assert(b>=0);
	assert(a<L*X);
	assert(b<L*X);
	
	int tot = 1;
	X = X%4;
	while (X > 0) {
		tot = molt(tot, A[L-1]);
		X--;
	}
	
	if (tot != -1) return false;
	
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		if (solve()) cout << "Case #" << t << ": YES\n";
		else cout << "Case #" << t << ": NO\n";
	}
	return 0;
}

