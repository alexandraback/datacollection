/*
LANG: C++
ID: he.andr1
PROG: C
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cassert>
#include<stack>
#include<list>
#include<cstdio>
#include<numeric>
#include<complex>
#include<string>
#include<map>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(v, i) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef pair<int, int> pii;
typedef complex<int> pt;
typedef long long ll;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }

template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }

template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXK = 20, MAXM = 5, MAXP = MAXM;

int T = 1, R = 100, N = 3, M = 5, K = 7, P = 3;

int primes[MAXP];

ll prod[MAXK];
int pexp[MAXK][MAXP];

bool isPrime(int n) {
	if(!(n%2)) return n == 2;
	for(int i = 3; i * i <= n; i+=2) {
		if(!(n%i)) return false;
	}
	return true;
}

void precomp() {
	P = 0;
	for(int i = 2; i <= M; i++) {
		if(isPrime(i)) primes[P++] = i;
	}
}

void comp() {
	for(int i = 0; i < K; i++){
		int v = prod[i];
		for(int j = 0; j < P; j++) {
			pexp[i][j] = 0;
			for(;!(v % primes[j]); v/=primes[j]) pexp[i][j]++;
		}
	}
}

string go() {
	comp();
	int n2 = 0, n3 = 0, n5 = 0, nj2 = 0;
	for(int i = 0; i < K; i++) setmax(n2, pexp[i][0]);
	for(int i = 0; i < K; i++) setmax(nj2, pexp[i][0] % 2);
	for(int i = 0; i < K; i++) setmax(n3, pexp[i][1]);
	for(int i = 0; i < K; i++) setmax(n5, pexp[i][2]);
	int l = N;
	string out;
	for(int i = 0; i < n3; i++) out += '3';
	l -= n3;
	for(int i = 0; i < n5; i++) out += '5';
	l -= n5;
	int t3 = 0, t5 = 0;
	for(int i = 0; i < K; i++) t3 += pexp[i][1];
	for(int i = 0; i < K; i++) t5 += pexp[i][2];
	if(n2/2 + nj2 == l) {
		if(nj2 == 1 && n2 == 2) {
			out += "22";
		} else if(nj2 == 1 && n2 == 4) {
			out += "224";
		} else {
			for(int i = 0; i < n2 / 2; i++) out += '4';
			if(nj2) out += '2';
		}
	} else if(l == 1) {
		if(t3 > t5) out += '3';
		else out += '5';
	} else if(l == 2) {
		if(nj2) out += "22";
		else out += "24";
	} else if(l == 3) {
		if(nj2) {
			out += "222";
		} else {
			out += "242";
		}
	}
	return out;
}

void io(istream &in, ostream &out) {
	in >> T >> R >> N >> M >> K;
	precomp();
	out << "Case #1:\n";
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < K; j++) {
			in >> prod[j];
		}
		out << go() << '\n';
	}
}

int main() {
	ifstream fin ("C-small-1-attempt0.in");
	if(fin.good()) {
		ofstream fout ("C-small-1-attempt0.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}
