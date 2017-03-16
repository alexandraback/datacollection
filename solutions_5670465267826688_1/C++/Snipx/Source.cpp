#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int a[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };

int get(char ch) {
	switch (ch) {
	case 'i':
		return 2;
	case 'j':
		return 3;
	case 'k':
		return 4;
	}
}

int main() {
	//ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int l;
		long long x;
		cin >> l >> x;
		string t;
		cin >> t;

		long long delta = 1000 * 1000 * 1000;
		delta *= 1000 * 4;
		while (delta > 0) {
			while (x - delta > 11) {
				x -= delta;
			}

			delta /= 10;
		}

		vector<int> f(x * l);

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < t.length(); j++) {
				if (i == 0 && j == 0)
					f[0] = get(t[j]);
				else {
					int prev = f[l * i + j - 1];
					bool minus = prev < 0;
					prev = abs(prev);
					int cur = a[prev][get(t[j])];
					f[l * i + j] = minus ? -cur : cur;
				}
			}
		}

		bool ok = false;

		for (int i = 0; i < f.size(); i++) {
			if (f[i] == 2) {
				for (int j = i + 1; j < f.size() - 1; j++) {
					if (f[j] == 4) {
						if (f.back() == -1) {
							ok = true;
						}
						break;
					}
				}
				break;
			}
		}

		cout << "Case #" << test << ": " << (ok ? "YES" : "NO") << endl;

	}


	//system("pause");
	return 0;
}