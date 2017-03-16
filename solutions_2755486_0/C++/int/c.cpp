#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define P(x) (x + 500)

struct Attack{
	int l, r, d, hei;
} at[105];

int hei[1005];

bool cmp(Attack a, Attack b){return a.d < b.d;}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		int N, ret = 0, tot = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i ++){
			int d0, s0, w0, e0, dd, dp, ds, t;
			scanf("%d%d%d%d%d%d%d%d", &d0, &t, &w0, &e0, &s0, &dd, &dp, &ds);
			w0 *= 2; e0 *= 2; dp *= 2;
			for (int j = 0; j < t; j ++){
				at[tot ++] = (Attack){w0, e0, d0, s0};
				d0 += dd; w0 += dp; e0 += dp; s0 += ds;
			}
		}
		memset(hei, 0, sizeof(hei));
		sort(at, at + tot, cmp);
		for (int l = 0; l < tot; l ++){
			int r = l;
			while (r + 1 < tot && at[r + 1].d == at[l].d) r ++;
			for (int i = l; i <= r; i ++){
				bool flag = 0;
				for (int x = at[i].l; x <= at[i].r && !flag; x ++)
					if (hei[P(x)] < at[i].hei) flag = true;
				if (flag) ret ++;
			}
			for (int i = l; i <= r; i ++){
				for (int x = at[i].l; x <= at[i].r; x ++)
					if (hei[P(x)] < at[i].hei)
						hei[P(x)] = at[i].hei;
			}
			l = r;
		}
		printf("Case #%d: %d\n", t + 1, ret);
	}
	return 0;
}
