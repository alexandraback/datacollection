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

int main(int argc, char *argv[]) {
	int cas, n;
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	memset (vis, 0, sizeof (vis));
	//a, e, i, o, and u
	vis['a'] = vis['e'] = vis['i'] = vis['o'] = vis['u'] = 1;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		scanf ("%s%d", str, &n);
		int len = strlen (str);
		int ans = 0;
		for (int i = n; i <= len; i ++) {
		//	cout << "i = " << i << "\n";
			for (int j = 0; j + i <= len; j ++) {
				if (check (j, j + i, n)) {
					ans ++;
				}
			}
		}
		printf ("Case #%d: %d\n", t, ans);
	}
	return 0;
}
