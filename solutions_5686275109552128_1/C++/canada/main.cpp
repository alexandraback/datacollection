#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int divup(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		int s = 1001, n; cin >> n;
		vector<int> ns(n); for (int &i : ns) cin >> i;
		sort(rbegin(ns), rend(ns));
		for (int g = 1; g <= ns.front(); ++g) {
			int t = g;
			for (int i = 0; i < ns.size() && ns[i] > g; ++i) {
				t += divup(ns[i], g) - 1;
			}
			s = min(s, t);
		}
out:	cout << "Case #" << cas << ": " << s << endl;
	}
}
