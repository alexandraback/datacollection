#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#define RD(x)      scanf("%d", &x)
#define REP(i, n)  for (int i=0; i<(n); i++)
#define REP1(i, n) for (int i=1; i<=(n); i++)
#define pii        pair<int, int>
#define mp         make_pair

using namespace std;
#define  N   111
#define  M   22222
#define  eps 1e-9
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long

bool check(string s) {
	static bool flag[30];
	memset(flag, false, sizeof flag);
	flag[s[0] - 'a'] = true;
	REP1(i, s.length() - 1) {
		if (s[i] != s[i-1] && flag[s[i] - 'a'] == true)
			return true;
		flag[s[i] - 'a'] = true;
	}
	return false;
}
int son[30];
int fa[30];
int num[30];
bool appear[30];
LL A[200];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	A[0] = 1;
	REP1(i, 111) {
		A[i] = A[i-1] * i % mod;
	}
	int T; cin >> T;
	REP1(TT, T) {
		memset(son, -1, sizeof son);
		memset(fa, -1, sizeof fa);
		memset(num, 0, sizeof num);
		memset(appear, false, sizeof appear);
		int n; cin >> n;
		int has = 0;
		bool ans0 = false;
		REP(j, n) {
			string t; cin >> t;
			ans0 = ans0 || check(t);
			int l, r;
			for (l=0; l<t.length(); l++) {
				if (t[l] != t[0])
					break;
			}
			for (r=t.length()-1; r>=0; r--) {
				if (t[r] != t[t.length() - 1])
					break;
			}
			for (int i=l; i<=r; i++) {
				int c = t[i] - 'a';
				if ((has >> c) & 1) {
					ans0 = true;
					break;
				}
			}
			REP(i, t.length()) {
				int c = t[i] - 'a';
				has |= (1 << c);
			}
			int v = t[0] - 'a';
			int u = t[t.length()-1] - 'a';
			appear[u] = true;
			appear[v] = true;
			if (u == v) {
				num[u]++;
				continue;
			}
			if (son[u] != -1 || fa[v] != -1) {
				ans0 = true;
			}
			son[u] = v;
			fa[v] = u;
		}
		LL ans = 1;
		LL cnt = 0;
		if (ans0 == false) {
			REP(i, 26) {
				if (fa[i] == -1 && appear[i] == true) {
					cnt++;
					int u = i;
					while (u != -1) {
						appear[u] = false;
						ans = ans * A[num[u]] % mod;
						u = son[u];
					}
				}
			}
		}
		ans = ans * A[cnt] % mod;
		REP(i, 26) ans0 = ans0 || appear[i];
		if (ans0) ans = 0;
		cout << "Case #" << TT << ": " << ans << endl;
	}

	return 0;
}
