#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 500
struct ATK
{
	int d, s, l, r;
} atk[200], atk2[200];
bool cmp(ATK arg1, ATK arg2) { return arg1.d < arg2.d; }
bool cmp2(ATK arg1, ATK arg2) { return arg1.r < arg2.r; }

int wall[1005];

int main()
{
	int t, c = 1;
	int n, d, dd, s, ds, l, r, dp, m;
	int i, j, k, idx, ans, ed, flag;

	scanf("%d", &t);
	while (t--)
	{
		memset(wall, 0, sizeof(wall));
		ans = idx = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d %d %d %d %d %d %d", &d, &m, &l, &r, &s, &dd, &dp, &ds);
			l += M;
			r += M;
			for (j = 0; j < m; j++)
			{
				atk[idx].d = d;
				atk[idx].l = l;
				atk[idx].r = r;
				atk[idx].s = s;
				atk2[idx] = atk[idx];
				idx++;

				d += dd;
				l += dp;
				r += dp;
				s += ds;
			}
		}
		std::sort(atk, atk+idx, cmp);
		std::sort(atk2, atk2+idx, cmp2);

		for (i = 0; i < idx; i++)
		{
			ed = atk[i].l;

			for (j = 0; j < idx; j++)
			{
				if (atk2[j].d < atk[i].d && atk2[j].s >= atk[i].s && atk2[j].l <= ed)
					ed = std::max(ed, atk2[j].r);
			}
			if (ed < atk[i].r) ans++;
//			printf("[%d, %d] %d %d\n", atk[i].l, atk[i].r, atk[i].s, ans);
		}
		printf("Case #%d: %d\n", c++, ans);
	}
	
	return 0;
}
