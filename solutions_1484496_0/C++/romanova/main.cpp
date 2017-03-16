#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long par[2000005] = {0};
int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);

	//int up = 2000005;
	int n, t, cur;
	scanf("%d", &t);

	for(int tt = 0; tt < t; ++tt)
	{
		memset(par, -1, sizeof(par));
		par[0] = 0;
		scanf("%d", &n);
		bool ok = 0;
		printf("Case #%d:\n", tt+1);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &cur);
			if(!ok)
			{
				for(int j = 2000005-1-cur; j >= 0; j--)
				{
					if(par[j] != -1)
					{
						if(par[j + cur] != -1)
						{
							if(ok)
								continue;
							printf("%d ", cur);
							int st = j;
							//int k1 = cur; //
							while(par[st])
							{
								printf("%d ", par[st]);
								st -= par[st];
								//k1 += par[st]; //
							}
							printf("\n");
							st = j+cur;
							//int k2 = 0; //
							while(par[st])
							{
								printf("%d ", par[st]);
								st -= par[st];
								//k2 += par[st]; //
							}
							printf("\n");
							//printf("%d %d\n", k1, k2); //
							ok = 1; 
						}
						par[j+cur] = cur;
					}
				}
			}
			
		}
		if(!ok)
			printf("Impossible\n");
	}

	return 0;
}

/*
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int n, t, s[205];
	double x;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt)
	{
		scanf("%d", &n);
		x = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &s[i]);
			x += s[i];
		}
		printf("Case #%d: ", tt+1);
		for(int i = 0; i < n; ++i)
		{
			double l = 0, r = 1, m;
			while(fabs(r-l) > 1e-9)
			{
				m = (l+r) / 2;
				double xx = s[i] + x * m;
				double y = 1 - m, yy;
				bool ok = 1;
				for(int j = 0; j < n; ++j)
				{
					if(i == j || s[j] >= xx)
						continue;
					yy = (xx-s[j]) / x;
					if(yy > y)
					{
						ok = 0;
						break;
					}
					y -= yy;
				}
				if(ok)
					l = m;
				else
					r = m;
			}
			printf("%.7lf ", m*100);
		}
		printf("\n");
	}

	return 0;
}
*/


/*

int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);


	return 0;
}

*/