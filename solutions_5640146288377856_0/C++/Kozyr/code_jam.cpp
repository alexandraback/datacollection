#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define TRACE(fmt,x) {fprintf(stderr,fmt,x);fprintf(stderr,"\n");}
#define CASE(a,b) fprintf(stderr, "%d / %d = %.2f | %.2f\n", a, b, (double)clock()/CLOCKS_PER_SEC, ((double)clock()/a*b)/CLOCKS_PER_SEC);

template <class type> type nod(type a, type b) { return a ? nod(b % a,a) : b; }
template <class type> type nok(type a, type b) { return a / nod(a,b) * b; }
template <class type> type reverse(type n) { type r=0; while(n>0) { r=r*10+n%10; n/=10; } return r; }
template <class type> int digits(type n) { int d=0; while(n>0) { n/=10; ++d; } return d; }
template <class type> int bits(type n) { int b=0; while(n>0) { n>>=1; ++b; } return b; }
//while(next_permutation(data.begin(), data.end())) {}

/*

5
1 4 2
1 7 7
2 5 1
1 4 3
1 5 4

*/

int R, C, W;

//int m[21][21];

int z[21];
int row(int col) {
	if (z[col] != -1) return z[col];
	int c = 0;
	if (col == W) c = 1;
	else if (col > W) c = 1 + row(col - W);
	z[col] = c;
	return c;
}
int kill(int col) {
	if (col < W) return 0;
	if (col == W) return W;
	return W+1;
}
int solve() {
	int n = R * row(C) - 1 + kill(C - W * (C/W - 1));
	return n;
}

int main() {
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> R >> C >> W;

		for(int i=0;i<21;++i) z[i] = -1;

		cout << "Case #" << t << ": " << solve() << endl;
		//CASE(t,T);
	}
	return 0;
}

