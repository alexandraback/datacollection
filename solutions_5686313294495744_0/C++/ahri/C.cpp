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

struct topic {
	string A, B;
	const bool operator<(const topic &other) {
		if (A != other.A) return A < other.A;
		return B < other.B;
	}
};

void solve(){
	int N;
	cin >> N;
	vector<topic> V(N);
	for(int i = 0; i < N; ++i){
		cin >> V[i].A >> V[i].B;
	}
	int count = 0;
	int triplets = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			for(int k = 0; k < N; ++k){
				if (i == k || j == k) continue;
				if (V[i].A == V[k].A && V[j].B == V[k].B) {
					count++;
				}
			}
		}
	}
	cout << count << endl;

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
