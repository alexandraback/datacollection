#if 0==0

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	//#define SMALL 1

	#ifdef SMALL
		freopen("C-small4.in", "r", stdin);
		freopen("C-small5.out", "w", stdout);
	#else
		freopen("C-large.in", "r", stdin);
		freopen("C-large.out", "w", stdout);
	#endif

	int a[2000];
	int d[2000];
	int p[2000];
	
	int i_numCases;
	scanf("%d", &i_numCases);
	for (int i_case = 1 ; i_case <= i_numCases ; i_case++)
	{		
		int n = 0;

		scanf("%d", &n);

		for (int i = 1 ; i <= n ; i++)
		{
			int k;
			scanf("%d", &k);
			a[i] = k;
		}

		for (int i = 1 ; i <= n ; i++) d[i] = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			p[i] = (a[a[i]] == i) ? a[i] : 0;
		}

		int ans = 0;

		for (int i = 1 ; i <= n ; i++)
		{
			int k = i;
			int c = 1;
			bool ok = false;
			bool cycle = false;

			if (p[i])
			{
				ok = true;
				cycle = true;
				c = 2;
			} else
			{
				while (true) 
				{
					if (p[k]) 
					{
						c++;
						ok = true;
						break;
					} else
					{
						k = a[k];
						
						if (k == i)
						{
							cycle = true;
							break;
						}						
						c++;
					}

					if (c > n) { ok = false; break; }
				}
			}

			if (ok) 
			{
				if (c > d[k]) d[k] = c;
			} else
			{
				if (cycle) 
				{
					if (c > ans) ans = c;
				}
			}
		}

		int t = 0;


		//case 1
		for (int i = 1 ; i <= n ; i++) 
		{
			if (p[i] > i)
			{
				int q = d[i] + d[p[i]] - 2;
				t += q;
			}
		}

		if (t > ans) ans = t;

		//case 2
		/*
		for (int i = 1 ; i <= n ; i++) 
		{
			if (p[i])
			{
				t = d[i] + d[p[i]] - 2;
				if (t > ans) ans = t;
			}
		}*/
		
		printf("Case #%d: ", i_case);
		
		printf("%d\n", ans);
	}

	return 0;
}

#endif