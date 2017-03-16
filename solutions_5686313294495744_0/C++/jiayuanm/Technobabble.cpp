#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

static const int INF = 999999999;

int n, sol;
string lhs[1005], rhs[1005];
map<string, int> first, second;

void read() {	
	cin >> n;
	first.clear();
	second.clear();
	for (int i = 0; i < n; ++i) {
		cin >> lhs[i] >> rhs[i];
		first[lhs[i]]++;
		second[rhs[i]]++;
	}
}

int solve() {
	read();
	sol = 0;
	for (int i = 0; i < n; ++i) {
		if (first[lhs[i]] > 1 && second[rhs[i]] > 1)
			++sol;
	}
	return sol;
}

int main() {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
	return 0;
}