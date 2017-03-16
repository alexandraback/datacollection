#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int tc,i ,j, k, a, b, ar[40], test,n,nn, found;
vector<int> list;

int main()
{
	freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	scanf("%d", &test);
	for (tc = 1; tc <= test; tc++)
	{
		found = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &ar[i]);
		printf("Case #%d: \n", tc);
		for (i = 1; i < (1<<n); i++)
		{
			list.clear();
			for (j = 0; j < n; j++)
				if (i & (1<<j)) list.push_back(ar[j]);
				
			nn = list.size();
			for (j = 1; j < (1<<nn); j++)
			{
				a = 0; b = 0;
				
				for (k = 0; k < nn; k++)
					if (j & (1<<k)) a += list[k];
						else b += list[k];
						
				//printf("%d %d %d %d %d\n", a, b,i, j, nn);
				if ( a == b) 
				{
					for (k = 0; k < list.size(); k++)
						if (j & (1<<k)) printf("%d ", list[k]); puts("");
					for (k = 0; k < list.size(); k++)
						if (!(j & (1<<k))) printf("%d ", list[k]); puts("");
					found = 1;
				}
				if (found) break;
			}
			if (found) break;
		}
		if (!found) puts("Impossible");
	}
}