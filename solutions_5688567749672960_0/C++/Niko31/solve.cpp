#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

const int maxn = 1e6 + 10;

int ans[maxn + 10];

void precalc() {
	for (int i = 1; i < maxn; i++)
		ans[i] = i;
	for (int i = 1; i < maxn; i++) {
		stringstream ss;
		ss << i;
		string s;
		ss >> s;
		reverse(s.begin(), s.end());
		stringstream tt;

		tt << s;
		int k;
		tt >> k;
		if (k < maxn) ans[k] = min(ans[k], ans[i] + 1);
		ans[i + 1] = min(ans[i + 1], ans[i] + 1);
	}
}

int main()
{
	precalc();
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
}