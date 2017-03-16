#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int VOWC = 5;
const char vow[VOWC] = {'a', 'e', 'i', 'o', 'u'};

bool iscons(char c) {
	for (int i = 0; i < VOWC; ++i) {
		if (vow[i] == c) {
			return false;
		}
	}
	return true;
}

void solve() {
	//fprintf(stderr, "new test\n");
	string s;
	int l;
	cin >> s >> l;
	int n = s.size();
	long long ans = 0;
	int curc = 0;
	for (int i = 0; i < l; ++i) {
		if (iscons(s[i])) {
			curc++;
		}
	}
	int lastl = 0;
	for (int i = l - 1; i < n; ++i) {
		//fprintf(stderr, "i = %d, curc = %d\n", i, curc);
		if (curc == l) {
			ans += 1LL * (i - l + 2 - lastl) * (n - i);
			lastl = i - l + 2;
		}
		if (iscons(s[i - l + 1])) {
			//fprintf(stderr, "dec i = %d\n", i);
			curc--;
		}
		if (i + 1 < n && iscons(s[i + 1])) {
			//fprintf(stderr, "inc i = %d\n", i);
			curc++;
		}
	}
	cout << ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}