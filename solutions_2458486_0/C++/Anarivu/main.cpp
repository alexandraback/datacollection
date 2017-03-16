#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int n, k;
bool u[(1<<20)];
int p[(1<<20)];

int ks[205];
int nk[25];
int ss[25];
int s[25][45];

bool dfs(int msk)
{
	if(msk == 0)
		return 1;
	u[msk] = 1;
	for(int i = 0; i < n; i++)
	{
		if(msk & (1<<i))
		{
			if(ks[nk[i]] > 0 && !u[msk ^ (1<<i)])
			{
				ks[nk[i]]--;
				for(int j = 0; j < ss[i]; j++)
					ks[s[i][j]]++;

				if(dfs(msk ^ (1<<i)))
				{
					p[msk] = i;
					return 1;
				}
				
				for(int j = 0; j < ss[i]; j++)
					ks[s[i][j]]--;
				ks[nk[i]]++;
			}
		}
	}
	return 0;
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);

	int T, tc = 1;
	scanf("%d", &T);

	while(T > 0)
	{
		printf("Case #%d: ", tc);

		memset(ks, 0, sizeof(ks));
		memset(u, 0, sizeof(u));
		memset(p, -1, sizeof(p));

		scanf("%d%d", &k, &n);
		for(int i = 0; i < k; i++)
		{
			int key;
			scanf("%d", &key);
			ks[key]++;
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &nk[i], &ss[i]);
			for(int j = 0; j < ss[i]; j++)
				scanf("%d", &s[i][j]);
		}
		
		if(!dfs((1<<n)-1))
			printf("IMPOSSIBLE\n");
		else
		{
			int msk = (1<<n)-1;
			while(msk != 0)
			{
				printf("%d ", p[msk] + 1);
				msk ^= (1<<p[msk]);
			}
			printf("\n");
		}

		tc++;
		T--;
	}
	

	return 0;
}