#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int next() {int x; cin >> x; return x;}

int main() {
	cout.precision(10);

	int tests = next();
	for (int test = 1; test <= tests; test++) {
		int k = next(), wl = next(), tl = next();
		string letters;
		cin >> letters;
		int cnt[26];
		fill(cnt, cnt + 26, 0);
		for (char c : letters) cnt[c - 'A']++;
		string word;
		cin >> word;
		bool cantype = true;
		for (char c : word) cantype &= cnt[c - 'A'] > 0;
		if (!cantype) {
			//printf("Case #%d: %.7f\n", test, 0);
			cout << "Case #" << test << ": " << 0 << "\n";
			continue;
		}
		int start = wl;
		for (int i = wl - 1; i > 0; i--) {
			bool can = true;
			for (int j = 0; j + i < wl; j++) can &= word[j] == word[j + i];
			if (can) start = i;
		}
		double answ = 1 + (tl - wl) / start;
		double p = 1;
		for (char c : word) p *= 1.0 * cnt[c - 'A'] / k;
		p *= tl - wl + 1;
		answ -= p;
		cout.precision(10);
		cout << "Case #" << test << ": " << answ << "\n";
		//printf("Case #%d: %.7f\n", test, answ);
	}
}