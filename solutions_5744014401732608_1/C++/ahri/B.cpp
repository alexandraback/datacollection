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

const string OK = "POSSIBLE";
const string BAD = "IMPOSSIBLE";

#define MAXN 50

int table[MAXN][MAXN];

int found_solution = false;
int64 M;
int B;

int64 dfs(int i) {
	if (i == B - 1)
		return 1;
	int64 ret = 0;
	for(int j = i + 1; j < B; ++j){
		if (table[i][j])
			ret += dfs(j);
	}
	return ret;
}

bool calc() {
	int64 count = dfs(0);
	return M == count;
}

void gen(int i, int j) {
	if (found_solution)
		return;
	if (i == B) {
		found_solution |= calc();
		return;
	}
	if (j == B)
		gen(i + 1, i + 2);
	else {
		gen(i, j + 1);
		if (found_solution) return;
		table[i][j] = 1;
		gen(i, j + 1);
		if (found_solution) return;
		table[i][j] = 0;
	}
}

void do_it() {
	found_solution = false;
	memset(table, 0, sizeof(table));
	gen(0, 1);
	if (found_solution) {
		cout << OK << endl;
		cerr << OK << " " << B << " " << M << endl;
		for(int i = 0; i < B; ++i){
			for(int j = 0; j < B; ++j){
				cerr << table[i][j];
			}
			cerr << endl;
		}
	} else {
		
		// cerr << BAD << " " << B << " " << M << endl;
	}	
}

bool do_it_smart() {
	if (1LL << (B - 2) < M) {
		cout << BAD << endl;
		return false;
	}
	cout << OK << endl;
	int64 count = 1;
	vector<int64> solution;	
	while (count * 2 < M) {
		solution.push_back(count * 2 - 1);
		count *= 2;
	}
	// solution.push_back(M - count);
	solution.push_back(count * 2 + (M - count - 1) * 2 + 1);
	reverse(solution.begin(), solution.end());
	while (sz(solution) < B)
		solution.push_back(0);
	for(int i = 0; i < sz(solution); ++i){
		for(int j = B - 1; j >= 0; --j){
			cout << ((solution[i] & (1LL << j)) ? 1 : 0);
		}
		cout << endl;
	}
	return true;
}

void solve() {
	cin >> B >> M;
	do_it_smart();
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
