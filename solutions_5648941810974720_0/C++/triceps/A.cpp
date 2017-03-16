#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

string ss[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
vector < map < char, int >> D(10);
bool found = false;
int t;

void solve(int d, map < char, int > m, vector<int> r)
{
	if (found) return;
	if (d == 10) {
		for (auto p : m) {
			if (p.second) return;
		}
		cout << "Case #" << t + 1 << ": ";
		for (auto i : r)
			cout << i;
		cout << endl;
		found = true;
		return;
	}

	int mx = 10000;
	for (auto p : D[d]) {
		mx = min(m[p.first] / p.second, mx);
	}

	for (int i = 0; i <= mx; i++) {
		solve(d + 1, m, r);
		for (auto p : D[d]) {
			m[p.first] -= p.second;
		}
		r.push_back(d);
	}
}

int main()
{
	for (int i = 0; i < 10; i++ ) {
		for (auto c : ss[i]) D[i][c]++;
	}

	int T;
	cin >> T;

	for ( t = 0; t < T; t++) {
		found = false;
		string s;
		cin >> s;
		map < char, int > m;
		for (auto c : s) m[c]++;
		vector<int> r;
		solve(0, m, r);

	}

	return 0;
}
