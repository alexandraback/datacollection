/*
  Google Code Jam 2013
  Round 1A, Problem B
  Coded by Michael Oliver
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

int solve(int E_s, int E_c, int R, int N, int v[]) {
	int max_gain = 0;
	if (N > 0) {
		// For each possible energy you can spend
		for (int i=0; i<=E_c; i++) {
			int gain = i*v[0];
			int recurse;
			if (E_c+R-i <= E_s) {
				recurse = solve(E_s,E_c-i+R,R,N-1,v+1);
			} else {
				recurse = solve(E_s,E_s,R,N-1,v+1);
			}
			if (gain + recurse > max_gain) {
				max_gain = gain+recurse;
			}
		}
	}
	return max_gain;
}

int main() {
	int num_cases;
	cin >> num_cases;
	for (int i=1; i <= num_cases; i++) {
		int E, R, N;
		int v[10];
		cin >> E >> R >> N;
		for (int j=0; j<N;j++){
			cin >> v[j];
		}
		// Input complete
		cout << "Case #" << i << ": " << solve(E,E,R,N,v) << endl;
	}
	return 0;
}
