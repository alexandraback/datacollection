#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define EPS 1e-12

#define SZ 205
#define SZ2 2000005

using namespace std;

int scr[SZ];
int memo[2000005];

bool used[SZ];

getpath(int val, int st, int n, bool flag)
{
	if(flag)
		printf(" ");
	printf("%d", scr[st]);
	used[st] = true;
	val = val - scr[st];
	int i;
	if(val == 0)
		return;
	for(i = 0; i < n; i++)
	{
		if(val - scr[i] < 0 || used[i] == true)
			continue;
		if(memo[val - scr[i]] > 0)
		{
			st = i;
			break;
		}
	}
	getpath(val, st, n, true);
}


int main()
{
	int i, j, k, n, a, b, tot;
	freopen("c-small-attempt0.in", "rt", stdin);
	freopen("c-small.out", "wt", stdout);

	int inp, kase;
	scanf("%d", &inp);
	//long double pp = 0.1;

	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d", &n);
		tot = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &scr[i]);
			tot += scr[i];
		}
		
		sort(scr, scr + n);
		memset(memo, 0, sizeof(memo));
		memo[0] = 1;
		for(i = 0; i < n; i++)
		{
			for(j = tot; j >= 0; j--)
			{
				if(memo[j] > 0)
					memo[j + scr[i]] += memo[j];
			}
		}

		for(i = 0; i <= tot; i++)
		{
			if(memo[i] > 1)
				break;
		}
		
		if(i > tot)
		{
			printf("Case #%d: Impossible\n", kase);
			continue;
		}

		int val = i;
		int st1, st2;
		st1 = st2 = -1;

		for(i = 0; i < n; i++)
		{
			if(memo[val - scr[i]] > 0)
			{
				if(st1 == -1)
				{
					st1 = i;
					break;
				}
				
			}
		}

		
		printf("Case #%d:\n", kase);
		memset(used, false, sizeof(used));

		getpath(val, st1, n, false);
		printf("\n");


		for(i = 0; i < n; i++)
		{
			if(memo[val - scr[i]] > 0)
			{
				if(used[i] == false)
				{
					st2 = i;
					break;
				}
				
			}
		}
		memset(used, false, sizeof(used));
		getpath(val, st2, n, false);
		printf("\n");
		
		
	}
	return 0;
}
