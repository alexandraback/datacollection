#if 0==0

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int best;

int r, c, n, t, u;

int a[2000];
int d[2000];
int p[2000];
int ans;

void search(int k)
{
	for (int i = 1 ; i <= n ; i++)
		if (d[i] == 0)
		{
			p[k] = i;
			if (k > 2)
			{
				bool ok = true;
				for (int i = 2 ; i < k ; i++)
					if (a[p[i]] != p[(i+1) > k ? 1 : (i+1)] && a[p[i]] != p[(i-1) < 1 ? k : (i-1)])
					{
						ok = false;
						break;
					}
				if (ok)
				{
					d[i] = 1;
					if (k >= 2)
					{
						bool ok = true;
						for (int i = 1 ; i <= k ; i++)
							if (a[p[i]] != p[(i+1) > k ? 1 : (i+1)] && a[p[i]] != p[(i-1) < 1 ? k : (i-1)])
							{
								ok = false;
								break;
							}
						if (ok) 
							if (k > ans) ans = k;
					}
					search(k + 1);
					d[i] = 0;
				}
			} else
			{
				d[i] = 1;	 
				if (k >= 2)
				{
					bool ok = true;
					for (int i = 1 ; i <= k ; i++)
						if (a[p[i]] != p[(i+1) > k ? 1 : (i+1)] && a[p[i]] != p[(i-1) < 1 ? k : (i-1)])
						{
							ok = false;
							break;
						}
					if (ok) 
						if (k > ans) ans = k;
				}
				search(k + 1);
				d[i] = 0;
			}
		}
}

int main()
{
	#define SMALL 1

	#ifdef SMALL
		freopen("C-small.in", "r", stdin);
		freopen("C-small.out", "w", stdout);
	#else
		freopen("C-large.in", "r", stdin);
		freopen("C-large.out", "w", stdout);
	#endif


	
	int i_numCases;
	scanf("%d", &i_numCases);
	for (int i_case = 1 ; i_case <= i_numCases ; i_case++)
	{		
		n = 0;

		scanf("%d", &n);

		for (int i = 1 ; i <= n ; i++)
		{
			int k;
			scanf("%d", &k);
			a[i] = k;
			d[i] = 0;
		}

		ans = 0;

		search(1);
		
		printf("Case #%d: ", i_case);
		
		printf("%d\n", ans);
	}

	return 0;
}

#endif