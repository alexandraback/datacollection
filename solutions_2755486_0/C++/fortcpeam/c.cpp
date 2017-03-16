/*
Author: 67h2gak
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxP = 2005;

#define P(X) ((X) + 1000)

struct Tattack{
	int d, l, r, hei;
} all[maxP];

int H[maxP];
int N, ret, tot;

void init()
{
	scanf("%d", &N); tot = 0;
	for (int i = 0; i < N; i ++){
		int d0, t, s0, w0, e0, det, dp, ds;
		scanf("%d%d%d%d%d%d%d%d", &d0, &t, &w0, &e0, &s0, &det, &dp, &ds);
		w0 *= 2; e0 *= 2; dp *= 2;
		all[tot ++] = (Tattack){d0, w0, e0, s0};
		for (int j = 1; j < t; j ++){
			w0 += dp; e0 += dp; d0 += det; s0 += ds;
			all[tot ++] = (Tattack){d0, w0, e0, s0};
		}
	}
}

bool cmp(Tattack a, Tattack b)
{
	return a.d < b.d;
}

void work()
{
	memset(H, 0, sizeof(H));
	sort(all, all + tot, cmp); ret = 0;
	for (int l = 0; l < tot; l ++){
		int r = l;
		while (r + 1 < tot && all[r + 1].d == all[l].d) r ++;
		for (int i = l; i <= r; i ++){
			int cnt = 0;
			for (int x = all[i].l; x <= all[i].r && !cnt; x ++)
				if (H[P(x)] < all[i].hei) cnt = 1;
			ret += cnt;
		}
		for (int i = l; i <= r; i ++){
			for (int x = all[i].l; x <= all[i].r; x ++)
				if (H[P(x)] < all[i].hei)
					H[P(x)] = all[i].hei;
		}
		l = r;
	}
}

void print(int t)
{
	printf("Case #%d: %d\n", t + 1, ret);
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		init();
		work();
		print(t);
	}
	return 0;
}
