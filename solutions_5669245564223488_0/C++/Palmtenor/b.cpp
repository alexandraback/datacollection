#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <iostream>
using namespace std;
typedef int64_t i64;

const int maxn = 200;
const i64 mod = 1000000007LL;

char str[maxn][maxn];
int n;
int nxt[maxn];
int cnt[maxn];
int ind[maxn];
int inmid[maxn];
bool v[maxn];

void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	return;
}

i64 fact(int k) {
	if (k == 0) {
		return 1LL;
	}
	return (fact(k - 1) * ((i64)k)) % mod;
}

i64 go(int c) {
	v[c] = true;
	if (nxt[c] == -1) {
		return fact(cnt[c]) % mod;
	}
	return (go(nxt[c]) * fact(cnt[c])) % mod;
}

int calc() {
	i64 ans = 1LL;

	memset(nxt, -1, sizeof(nxt));
	memset(cnt, 0, sizeof(cnt));
	memset(ind, 0, sizeof(ind));
	memset(inmid, -1, sizeof(inmid));
	memset(v, false, sizeof(v));

	for (int i = 0; i < n; i++) {
		int len = strlen(str[i]);
		if (str[i][0] == str[i][len - 1]) {
			for (int j = 0; j < len; j++) {
				if (str[i][j] != str[i][0]) {
					return 0;
				}
			}
			cnt[str[i][0] - 'a']++;
			continue;
		}
		if (nxt[str[i][0] - 'a'] != -1) {
			return 0;
		}
		nxt[str[i][0] - 'a'] = str[i][len - 1] - 'a';
		ind[str[i][len - 1] - 'a']++;
		int posst = -1;
		int posen = -1;
		for (int j = 0; j < len; j++) {
			if (str[i][j] != str[i][0]) {
				posst = j - 1;
				break;
			}
		}
		if (posst == -1) {
			posst = 0;
		}
		for (int j = len - 1; j >= 0; j--) {
			if (str[i][j] != str[i][len - 1]) {
				posen = j + 1;
				break;
			}
		}
		if (posen == -1) {
			posen = len - 1;
		}
		for (int j = posst + 1; j < posen; j++) {
			if ((inmid[str[i][j] - 'a'] != -1) && (inmid[str[i][j] - 'a'] != i)) {
				return 0;
			}
			inmid[str[i][j] - 'a'] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (inmid[str[i][0] - 'a'] != -1) {
			return 0;
		}
		if (inmid[str[i][strlen(str[i]) - 1] - 'a'] != -1) {
			return 0;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (ind[i] > 1) {
			return 0;
		}
	}

	int grpcnt = 0;
	for (int i = 0; i < 26; i++) {
		if (ind[i] > 0) {
			continue;
		}
		if (nxt[i] == -1) {
			v[i] = true;
			if (cnt[i] == 0) {
				continue;
			}
			grpcnt++;
			ans *= fact(cnt[i]);
			ans %= mod;
			continue;
		}
		grpcnt++;
		ans *= go(i);
		ans %= mod;
	}

	for (int i = 0; i < 26; i++) {
		if (v[i]) {
			continue;
		}
		return 0;
	}

	ans *= fact(grpcnt);
	ans %= mod;

	return (int)(ans % mod);
}

int main() {
	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; i++) {
		init();
		printf("Case #%d: %d\n", i, calc());
	}
	return 0;
}