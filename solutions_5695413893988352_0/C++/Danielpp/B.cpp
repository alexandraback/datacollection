#include <bits/stdc++.h>
using namespace std;

#define DEBUG_ON 1 // 0 = off, 1 = on

namespace {
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define LEN(x) (int)((x).size())
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define OP minmax

#define FOR(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif // ONLINE_JUDGE

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

}

const int MAX_N = 200000;
const ll MODD = 1000000009LL;
const ld EPS = 1e-9;

pair<vi, vi> best_answer;
vi unknowns;
int n;
int num_digits;

pii assemble(vi& digits) {
	int score1 = 0;
	int base = 1;
	for (int i = num_digits * 2 - 1; i >= num_digits; i--) {
		score1 += digits[i] * base;
		base *= 10;
	}
	
	int score2 = 0;
	base = 1;
	for (int i = num_digits - 1; i >= 0; i--) {
		score2 += digits[i] * base;
		base *= 10;
	}
	
	return {score2, score1};
}

void backtrack(vi& digits, int pos) {
	// Done
	if (pos == n) {
		pii scores = assemble(digits);
		int c = scores.first;
		int j = scores.second;
		int difference = abs(c - j);
		vi sol = {difference, c, j};
		if (sol < best_answer.second) {
			best_answer = {digits, sol};
		}
	}
	else {
		FOR(d,0,10) {
			digits[unknowns[pos]] = d;
			backtrack(digits, pos+1);
		}
	}
}

void clear() {
	unknowns.clear();
	vi bad{-1,-1};
	vi bad2{INT_MAX,INT_MAX,INT_MAX};
	best_answer = MP(bad, bad2);
}

void solve_small() {
	string C, J;
	cin >> C >> J;
	clear();
	
	vi temp;
	num_digits = LEN(C);
	
	FOR(i,0,LEN(C)) {
		if (C[i] == '?') {
			unknowns.PB(i);
			temp.PB(-1);
		}
		else temp.PB(C[i] - '0');
	}
	FOR(i,0,LEN(J)) {
		if (J[i] == '?') {
			unknowns.PB(LEN(C)+i);
			temp.PB(-1);
		}
		else temp.PB(J[i] - '0');
		
	}
	
	n = LEN(unknowns);
	
	backtrack(temp, 0);
	
	pii scores = assemble(best_answer.first);
	string format = " %0" + to_string(num_digits) + "d %0" + to_string(num_digits) + "d\n";
	printf(format.c_str(), scores.first, scores.second);
}

int main() {



  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ":";
    solve_small();
  }
  
}
