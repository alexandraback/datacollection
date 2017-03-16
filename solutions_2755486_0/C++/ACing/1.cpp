#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Event
{
	int t, w, e, s;
	bool operator < (const Event &a) const
	{
		return t < a.t;
	}
};


int val[600];
const int offset = 200;
int d[20], n[20], w[20], e[20], s[20], d_d[20], d_p[20], d_s[20];

Event evt[110];

bool ok(int p, int s)
{
	return val[p + offset] >= s;
}

void up(int p, int s)
{
	if (val[p + offset] < s)
		val[p + offset] = s;
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, N;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		for (int i = 0; i < 600; ++i)
		{
			val[i] = 0;
		}
		int cnt = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &d_d[i], &d_p[i], &d_s[i]);

			for (int j = 0; j < n[i]; ++j)
			{
				evt[cnt].t = d[i] + d_d[i] * j;
				evt[cnt].w = w[i] + d_p[i] * j;
				evt[cnt].e = e[i] + d_p[i] * j;
				evt[cnt].s = s[i] + d_s[i] * j;
				++cnt;
			}
		}
		sort(evt, evt + cnt);
		int ans = 0;
		for (int i = 0; i < cnt; )
		{
			int pre = i;
			while (i < cnt && evt[i].t == evt[pre].t) ++i;
			for (int j = pre; j < i; ++j)
			{
				for (int k = evt[j].w; k < evt[j].e; ++k)
				{
					if (!ok(k, evt[j].s))
					{
						//printf("%d : %d - %d, %d\n", evt[j].t, evt[j].w, evt[j].e, evt[j].s);
						++ans;
						break;
					}
				}
			}
			for (int j = pre; j < i; ++j)
			{
				for (int k = evt[j].w; k < evt[j].e; ++k)
				{
					up(k, evt[j].s);
				}
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}