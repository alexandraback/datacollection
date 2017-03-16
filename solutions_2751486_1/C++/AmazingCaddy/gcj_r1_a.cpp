#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
const int INF = 0x3f3f3f3f;
const double pi = acos (-1.0);
const double eps = 1e-8;

char str[maxn];
int vis [128];
/*
int check (int st, int ed, int n) {
	for (int i = st; i + n <= ed; i ++) {
		int flag = 1;
		for (int j = 0; j < n; j ++) {
			if (vis[str[j + i]]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	return 0;
}
*/
int main(int argc, char *argv[]) {
	int cas, n;
	freopen ("A-large.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	memset (vis, 0, sizeof (vis));
	//a, e, i, o, and u
	vis['a'] = vis['e'] = vis['i'] = vis['o'] = vis['u'] = 1;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		scanf ("%s%d", str + 1, &n);
		int len = strlen (str + 1);
		ll ans = 0;
		int last_ok = -1;
		int con = 0;
		for (int i = 1; i <= len; i ++) {
			if (vis[str[i]]) {
				// ิชา๔
				con = 0;
				if (last_ok != -1) {
					ans += (last_ok - n + 1);
				}
			} else {
				con ++;
				if (con >= n) {
					last_ok = i;
					ans += (last_ok - n + 1);
				} else {
					if (last_ok != -1) {
						ans += (last_ok - n + 1);
					}
				}
			}
		}
		cout << "Case #" << t << ": " << ans << "\n";
	//	printf ("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
