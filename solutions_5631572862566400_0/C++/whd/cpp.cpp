//author: whd

#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;
typedef long long big;

typedef pair<int, int> pii;
const int N = 100020;
int n;
int vis[2000];
int ans;
int nxt[N];
int q[N], ind[N];
bool del[N];
int f[N];
void del_cir() {
	int i, j, k;
	int s, h = 1, tail = 0;
	memset(ind, 0, sizeof(ind));
	memset(del, false, sizeof(del));
	for (i = 1; i <= n; i++)
		ind[nxt[i]]++;
	for (i = 1; i <= n; i++)
		if (!ind[i])
			q[++tail] = i;
	while (h <= tail) {
		s = q[h++];
		if (!(--ind[nxt[s]]))
			q[++tail] = nxt[s];
	}
	for (i = 1; i <= n; i++) {
		if (ind[i] && i != nxt[nxt[i]]) {
			del[i] = true;
//			cerr << i << " ";
		}
	}
//	cerr << endl;
}
void dp() {
	int res = 0;
	int i, j, k;
	int s, h = 1, tail = 0;
	memset(f, 0, sizeof(f));
	memset(ind, 0, sizeof(ind));
	for (i = 1; i <= n; i++)
		ind[nxt[i]]++, f[i] = 1;
	for (i = 1; i <= n; i++)
		if (!ind[i])
			q[++tail] = i;
	while (h <= tail) {
		s = q[h++];
		--ind[nxt[s]];
		f[nxt[s]] = max(f[s] + 1, f[nxt[s]]);
		if (!ind[nxt[s]])
			q[++tail] = nxt[s];
	}
	for (i = 1; i <= n; i++)
		if (!del[i] && ind[i]) {
			del[i] = del[nxt[i]] = true;
			res += f[i] + f[nxt[i]];
//			res += max(1 + f[i], 1 + f[nxt[i]]);
//			printf("%d\n", f[i]);
		}
	ans = max(ans, res);
}
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas, cass;
	int i, j, k, x, y, z;
	scanf("%d", &cas);
	for (cass = 1; cass <= cas; cass++) {
		printf("Case #%d: ", cass);
		scanf("%d", &n);
		memset(nxt, 0, sizeof(nxt));
		for (i = 1; i <= n; i++) {
			scanf("%d", &x);
			nxt[i] = x;
		}
		ans = -1;
		for (i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			int idx = 0;
			for (j = i; j; j = nxt[j]) {
				++idx;
				if (!vis[j]) {
					vis[j] = idx;
				} else {
					ans = max(ans, idx - vis[j]);
					break;
				}
			}
		}
		del_cir();
		dp();
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
}

