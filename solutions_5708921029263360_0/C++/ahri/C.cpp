/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
#define EXISTS(x, s) ( (s).find((x)) != (s).end() ) 
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }

struct outfit {
	int a, b, c;
	outfit(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
	const bool match(const outfit &other) const {
		return ((a == other.a ? 1 : 0) + (b == other.b ? 1 : 0) + (c == other.c ? 1 : 0) > 1);
	}
};

int A[3];

int match(int X, int Y) {
	int a = ((X % A[2]) == (Y % A[2])) ? 1 : 0;
	int b = ((X / A[2] % A[1]) == (Y / A[2] % A[1])) ? 2 : 0;
	int c = ((X / A[2] / A[1]) == (Y / A[2] / A[1])) ? 4 : 0;
	return a | b | c;
}

#define MAXN 27

int sol[MAXN];
int sol_save[MAXN];
int box[8];
int ret = 0;
int all;

template<typename T, typename U> inline void relaxmax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}

int reduce_k(int K) {
	for(int i = 0;; ++i){
		if ((i * (i + 1) / 2) >= K)
			return i - 1;		
	}
}


void rek(int x, int N, const int K) {
	// if (N) {
		// cerr << " ::: ";
		// for(int i = 0; i < N; ++i){
			// cerr << sol[i] << " ";
		// }
		// cerr << endl;
	// }
	if (N > ret) {
		ret = N;
		for(int i = 0; i < N; ++i){
			sol_save[i] = sol[i];
		}
	}
	relaxmax(ret, N);
	if (x >= all)
		return;
	rek(x + 1, N, K);	
	memset(box, 0, sizeof(box));
	for(int i = 0; i < N; ++i) {
		int m = match(sol[i], x);
		// cerr << sol[i] << " " << x << " " << m << endl;
		box[m]++;
	}
	// cerr << x << " BOX: " << box[3] << " " << box[5] << " " << box[6] << endl;
	if (box[3] >= K || box[5] >= K || box[6] >= K)
		return;
	sol[N] = x;
	rek(x + 1, N + 1, K);	
}

void solve() {
	int K;
	cin >> A[0] >> A[1] >> A[2] >> K;
	vector<outfit> V;
	all = A[0] * A[1] * A[2];
	cerr << "ZADATAK: " << all << " " << K << endl;
	ret = 0;
	// int limit = reduce_k(K);
	// cerr << limit << endl;
	rek(0, 0, K);	
	cout << ret << endl;
	for(int i = 0; i < ret; ++i){
		// cerr << sol_save[i] << " " << (sol_save[i] / A[0] / A[1]) << endl;
		cout << ((sol_save[i] / A[2] / A[1]) + 1) << " " << (sol_save[i] / A[2] % A[1] + 1) << " " << sol_save[i] % A[2] + 1 << endl;
	}
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
