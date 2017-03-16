#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
int64 ca, n, m, k;
int64 f1[40], f2[40], f3[40], f4[40];

int64 get(int64 x, int64 t)
{
	return (x >> t) & 1;
}

int64 put(int64 x, int64 t)
{
	return (x << t) >> t;
}

void work(int ca)
{
	int64 ans = int64(n) * m;
	int64 a, b;
	--k;

	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	memset(f3, 0, sizeof(f3));
	memset(f4, 0, sizeof(f4));
	
	f1[31] = f2[31] = f3[31] = 0;
	f4[31] = 1;
	
	for (int i = 30; i >= 0; --i)
	{
		if (get(k, i) == 1)
		{
			f1[i] += f1[i + 1];
			
			if (get(n, i) == 1)
				f2[i] += f2[i + 1];

			if (get(m, i) == 1)
				f3[i] += f3[i + 1];

			if (get(n, i) == 1 && get(m, i) == 1)
				f4[i] += f4[i + 1];
		}
		else
		{
			f1[i] += f1[i + 1] * 3;

			if (get(n, i) == 1)
			{
				f2[i] += f2[i + 1];
				f1[i] += f2[i + 1] * 2;
			}
			else
				f2[i] += f2[i + 1] * 2;

			if (get(m, i) == 1)
			{
				f3[i] += f3[i + 1];
				f1[i] += f3[i + 1] * 2;
			}
			else
				f3[i] += f3[i + 1] * 2;

			if (get(n, i) == 0)
			{
				if (get(m, i) == 0)
					f4[i] += f4[i + 1];
				else
				{
					f2[i] += f4[i + 1];
					f4[i] += f4[i + 1];
				}
			}
			else
			{
				if (get(m, i) == 0)
				{
					f3[i] += f4[i + 1];
					f4[i] += f4[i + 1];
				}
				else
				{
					f1[i] += f4[i + 1];
					f2[i] += f4[i + 1];
					f3[i] += f4[i + 1];
				}
			}
		}

		if (get(k, i) == 0)
		{
			ans -= f1[i + 1] * (1LL << i) * (1LL << i);

			if (get(n, i) == 1 && i != 0)
				ans -= f2[i + 1] * (n & ((1 << i) - 1)) * (1LL << i);

			if (get(m, i) == 1 && i != 0)
				ans -= f3[i + 1] * (m & ((1 << i) - 1)) * (1LL << i);

			if (get(n, i) == 1 && get(m, i) == 1 && i != 0)
				ans -= f4[i + 1] * (n & ((1 << i) - 1)) * (m & ((1 << i) - 1));
		}

	}

	printf("Case #%d: ", ca);
	cout << ans << endl;
}

int main()
{
	cin >> ca;
	rep(t, ca)
	{
		cin >> n >> m >> k;
		//scanf("%d%d%d", &n, &m, &k);
		work(t);
	}
	return 0;
}
