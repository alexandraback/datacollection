#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <climits>
#include <bitset>

using namespace std;

vector<char> v;

int t, r, c, w, k, l, s, x, kol, p[1001], sum, m;
string a, b;

void gen(int n) {
	string tmps = b;
	int tk = 0;
	if (n == s) {
		tmps += '#';
		for (int i = 0; i < v.size(); i++) {
			tmps += v[i];
		}
		for (int i = 0; i < tmps.length(); i++)
			p[i] = 0;
		int k = 0;
		for (int i = 1; i < tmps.length(); i++) {
			while (k > 0 && tmps[i] != tmps[k]) {
				k = p[k - 1];
			}
			if (tmps[i] == tmps[k])
				k++;
			p[i] = k;
			if (p[i] == b.length()) {
				tk++;
			}
		}
		sum += tk;
		m = max(m, tk);
		kol++;
		return;
	}
	for (int i = 0; i < a.length(); i++) {
		v.push_back(a[i]);
		gen(n + 1);
		v.pop_back();
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int jj = 1; jj <= t; jj++) {
		kol = sum = m = 0;
		cin >> k >> l >> s >> a >> b;
		gen(0);
		cout << "Case #" << jj << ": ";
		printf("%.6f", (double)m - (double)sum / (double)kol);
		cout << endl;
	}

	return 0;
}