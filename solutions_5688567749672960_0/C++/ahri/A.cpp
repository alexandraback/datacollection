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


template<typename T, typename U> inline void relaxmin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template<typename T, typename U> inline void relaxmax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}


typedef pair<int64, int> par;

set<int64> S;

int64 swap_digits(int64 x) {
	int64 ret = 0;
	while (x) {		
		ret = ret * 10 + x % 10;		
		x /= 10;
	}
	return ret;
}

int f(int n) {
	int ret = 0;
	int k[2];
	k[0] = k[1] = 0;
	for (int i = 1; i < n; ++i) {
		int b = i % 2;
		k[b] = k[b] * 10 + 9;
		ret += k[0] + k[1] + 1;
	}
	return ret;
	
}

int64 calc(int N) {	
	if (N < 10) return N;
	int64 x = N;
	int digits = 0;
	int start = 1;
	while (x) {
		digits ++;
		x /= 10;
		start *= 10;
	}
	start /= 10;
	int64 p1 = f(digits);
	int64 ret = N - start;
	// cerr << N << " " << p1 << " " << start << endl;
	// cerr << "1: " << ret << endl;
	if (N % 10) {
		int64 z = start;	
		while (z) {
			int offset = swap_digits(N / z);
			int64 p2 = offset + 1 + N - swap_digits(start + offset);
			// cerr << "2: " << z << " " << offset << " " << p2 << endl;
			if (p2 > 0) {
				relaxmin(ret, p2);
			}
			z /= 10;
		}		
	}
	return ret + p1;	
}

void solve(){
	S.clear();
	int64 N;
	cin >> N;
	cout << min(calc(N), calc(N-1) + 1) << endl;
	
}

int main() {

	// for (int i = 1; i < 10; i++) {
		// cerr << "::: " << f(i) << endl;
	// }

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
