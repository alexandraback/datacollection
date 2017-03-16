/*
  Google Code Jam 2013
  Round 1C, Problem B
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

void solve(int x, int y) {
	for (int i=0; i < abs(x); i++) {
		if (x < 0) cout << "EW";
		else cout << "WE";
	}
	for (int i=0; i < abs(y); i++) {
		if (y < 0) cout << "NS";
		else cout << "SN";
	}
}

int main() {
	int num_cases;
	cin >> num_cases;
	for (int i=1; i <= num_cases; i++) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << i << ": ";
		solve(x, y);
		cout << endl;
	}
	return 0;
}
