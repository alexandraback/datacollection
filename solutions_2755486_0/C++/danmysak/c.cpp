#define maxp 10000000
#define maxn 11
#define maxday 676061

#include <stdio.h>

long long wall[2 * maxp + 1];
long long d[maxn], n[maxn], w[maxn], e[maxn], s[maxn], delta_d[maxn], delta_p[maxn], delta_s[maxn];

inline bool doWall1(int pos, long long s)
{
	return wall[pos + maxp] < s;
}

inline void doWall2(int pos, long long s)
{
	if (wall[pos + maxp] < s)
		wall[pos + maxp] = s;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int test = 0; test < t; test++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%llu %llu %llu %llu %llu %llu %llu %llu", &d[i], &n[i], &w[i], &e[i], &s[i], &delta_d[i], &delta_p[i], &delta_s[i]);
		}
		for (int i = -maxp; i <= maxp; i++)
			wall[i + maxp] = 0;
		int ans = 0;
		for (int day = 0; day <= maxday; day++)
		{
			for (int i = 0; i < N; i++)			
			{
				int attack;
				if (day >= d[i] && (day - d[i]) % delta_d[i] == 0 && (attack = (day - d[i]) / delta_d[i]) < n[i])
				{
					int W = w[i] + delta_p[i] * attack;
					int E = e[i] + delta_p[i] * attack;
					long long S = s[i] + delta_s[i] * attack;
					bool b = false;
					for (int pos = W; pos < E; pos++)
						if (doWall1(pos, S))
							b = true;
					if (b)
						ans++;
				}
			}

			for (int i = 0; i < N; i++)			
			{
				int attack;
				if (day >= d[i] && (day - d[i]) % delta_d[i] == 0 && (attack = (day - d[i]) / delta_d[i]) < n[i])
				{
					int W = w[i] + delta_p[i] * attack;
					int E = e[i] + delta_p[i] * attack;
					long long S = s[i] + delta_s[i] * attack;					
					for (int pos = W; pos < E; pos++)
						doWall2(pos, S);
				}
			}

		}
		printf("Case #%d: %d\n", test + 1, ans);
	}

	return 0;
}