#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 534567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in1[20];
char in2[20];
ll mn1[20];
ll mn2[20];
ll mx1[20];
ll mx2[20];
ll po10[20];

vector <ll> V;
void print(ll a, int x) {
	int i;
	for (i = 0; i < x; i++) {
		V.push_back(a % 10);
		a /= 10;
	}
	reverse(V.begin(), V.end());
	for (auto it : V) printf("%lld", it);
	V.clear();
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s %s", in1, in2);
		int L = strlen(in1), i;
		po10[0] = 1;
		for (i = 1; i <= 18; i++) po10[i] = po10[i - 1] * 10;

		mn1[L] = mx1[L] = mn2[L] = mx2[L] = 0;
		for (i = L - 1; i >= 0; i--) {
			mn1[i] = mn1[i + 1];
			mx1[i] = mx1[i + 1];
			mn2[i] = mn2[i + 1];
			mx2[i] = mx2[i + 1];
			if (in1[i] == '?') mx1[i] += 9 * po10[L - 1 - i];
			else {
				mn1[i] += (in1[i] - '0') * po10[L - 1 - i];
				mx1[i] += (in1[i] - '0') * po10[L - 1 - i];
			}
			if (in2[i] == '?') mx2[i] += 9 * po10[L - 1 - i];
			else {
				mn2[i] += (in2[i] - '0') * po10[L - 1 - i];
				mx2[i] += (in2[i] - '0') * po10[L - 1 - i];
			}
		}

		pair<ll, pll> ans = mp(LL_INF, pll(-1, -1));

		ll t = 0, t1, t2;
		for (i = 0; i < L; i++) {
			if (in1[i] == '?' && in2[i] == '?') {
				ll t1 = t + po10[L - 1 - i] + mn1[i+1];
				ll t2 = t + mx2[i+1];
				ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));

				t1 = t + mx1[i+1];
				t2 = t + po10[L - 1 - i] + mn2[i+1];
				ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
			}

			else if (in1[i] == '?' && in2[i] != '?') {
				if (in2[i] != '0') {
					ll t1 = t + (in2[i] - '0' - 1) * po10[L - 1 - i] + mx1[i+1];
					ll t2 = t + (in2[i] - '0') * po10[L - 1 - i] + mn2[i+1];
					ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
				}
				if (in2[i] != '9') {
					ll t1 = t + (in2[i] - '0' + 1) * po10[L - 1 - i] + mn1[i + 1];
					ll t2 = t + (in2[i] - '0') * po10[L - 1 - i] + mx2[i + 1];
					ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
				}
				t += po10[L - 1 - i] * (in2[i] - '0');
			}
			
			else if (in1[i] != '?' && in2[i] == '?') {
				if (in1[i] != '0') {
					ll t1 = t + (in1[i] - '0') * po10[L - 1 - i] + mn1[i + 1];
					ll t2 = t + (in1[i] - '0' - 1) * po10[L - 1 - i] + mx2[i + 1];
					ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
				}
				if (in1[i] != '9') {
					ll t1 = t + (in1[i] - '0') * po10[L - 1 - i] + mx1[i + 1];
					ll t2 = t + (in1[i] - '0' + 1) * po10[L - 1 - i] + mn2[i + 1];
					ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
				}
				t += po10[L - 1 - i] * (in1[i] - '0');
			}
			else if (in1[i] > in2[i]) {
				ll t1 = t + (in1[i] - '0') * po10[L - 1 - i] + mn1[i + 1];
				ll t2 = t + (in2[i] - '0') * po10[L - 1 - i] + mx2[i + 1];
				ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
				break;
			}
			else if (in1[i] < in2[i]) {
				ll t1 = t + (in1[i] - '0') * po10[L - 1 - i] + mx1[i + 1];
				ll t2 = t + (in2[i] - '0') * po10[L - 1 - i] + mn2[i + 1];
				ans = min(ans, mp(abs(t1 - t2), pll(t1, t2)));
				break;
			}
			else t += (in1[i] - '0') * po10[L - 1 - i];
		}
		if (i == L) ans = min(ans, mp(0ll, pll(t, t)));

		printf("Case #%d: ", tc);
		print(ans.second.first, L);
		printf(" ");
		print(ans.second.second, L);
		printf("\n");
	}
	return 0;
}