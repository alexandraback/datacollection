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

4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100

*/

int C, D, V;
vector<int> d;
unsigned char m[1000000001];

int get(int i) {
	int r = 0;
	for(int k = 0; k<D; ++k) {
		if (i & (1<<k))
			r += d[k];
	}
	return r;
}

int calc() {
	for (int i=1; i<=V;++i) m[i] = 0;

	for (int i=0; i<(1<<D); ++i) {
		m[get(i)] = 1;
	}
	for (int i=1; i<=V; ++i) {
		if (m[i] == 0) return i;
	}
	return 0;
}

int solve() {
	int res = 0;

	int c = calc();

	while (c > 0) {
		//cout << c << endl;
		++res;
		d.push_back(c); ++D;
		c = calc();
	}

	return res;
}

int main() {
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> C >> D >> V;

		d.clear();
		for(int i=0;i<D;++i) { int z; cin >> z; d.push_back(z);}

		cout << "Case #" << t << ": " << solve() << endl;
		//CASE(t,T);
	}
	return 0;
}

