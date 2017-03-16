#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long t, k, l, s;
string sstr, lstr;
long long amount;
long long maximal;

long long brut(string str) {
	if ((long long)str.size() < s) {
		long long ans = 0;
		for (int i = 0; i < k; i ++) {
			ans += brut(sstr[i] + str);
		}
		return ans;
	} else {
		long long ans = 0;
		for (int i = 0; i + l <= s; i++) {
			bool f = false;
			for (int j = 0; j < l; j++) {
				if (str[i + j] != lstr[j])
					f = true;
			}
			if (!f) {
				ans++;
			}
		}
		amount++;
		maximal = max(maximal, ans);
		return ans;
	}
}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> l >> s;
		cin >> sstr;
		cin >> lstr;
		amount = 0;
		maximal = 0;
		double ans = brut("");
		ans /= amount;
		ans = (double)maximal - ans;
		printf("Case #%d: %.20lf\n", i +1, ans);
	}
	return 0;
}
