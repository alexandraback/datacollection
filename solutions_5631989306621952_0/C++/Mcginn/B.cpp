#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long UL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define sz(x) ((int)(x.size()))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = 1e3 + 7;
const int P = 1e7 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e7;
const double EPS = 1e-10;
char s[N], b[N << 1];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int _c = 1; _c <= T; ++_c) {
		scanf(" %s", s);
		int l, r;
		l = strlen(s);
		r = l + 1;
		b[l] = s[0];
		for (int i = 1; s[i]; ++i)
			if (s[i] >= b[l]) {
				b[--l] = s[i];
			} else {
				b[r++] = s[i];
			}
		printf("Case #%d: ", _c);
		for (int i = l; i < r; ++i)
			putchar(b[i]);
		puts("");
	}
	return 0;
}
