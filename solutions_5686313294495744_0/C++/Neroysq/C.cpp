#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;
const int nmax = 2000 + 18, mmax = 1000 * 1000 + 18;

map<string, int> l, r;
int match[nmax], fst[nmax], nxt[mmax], pnt[mmax], tot;
int n, ltot, rtot;
bool ed[nmax];

void addedge(int s, int t)
{
	pnt[++tot] = t;
	nxt[tot] = fst[s];
	fst[s] = tot;
}

bool dfs(int x)
{
	for (int i = fst[x]; i; i = nxt[i]) {
		int y = pnt[i];
		if (!ed[y]) {
			ed[y] = 1;
			if (match[y] == -1 || dfs(match[y])) {
				match[y] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases) {
		l.clear();
		r.clear();
		memset(fst, 0, sizeof(fst));
		tot = ltot = rtot = 0;
		scanf("%d", &n);
//		printf("%d\n", n);
		for (int i = 1; i <= n; ++i) {
			string a, b;
			cin >> a >> b;
			int p, q;
			if (l.find(a) != l.end())
				p = l[a];
			else
				p = l[a] = ++ltot;
			if (r.find(b) != r.end())
				q = r[b];
			else
				q = r[b] = ++rtot;
			addedge(p, q);
//			printf("%d %d\n", p, q);
		}
		int ans = 0;
		memset(match, -1, sizeof(match));
		for (int i = 1; i <= ltot; ++i)
			if (match[i] == -1) {
				memset(ed, 0, sizeof(ed));
				if (dfs(i))
					++ans;
			}
		printf("Case #%d: ", cases);
//		printf("%d %d %d\n", ltot, rtot, ans);
		printf("%d", n - (ltot + rtot - ans));
		printf("\n");
	}
	return 0;
}

