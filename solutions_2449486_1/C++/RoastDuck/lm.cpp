#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, N, M, map[200][200];

int main()
{
	freopen("lm.in","r",stdin);
	freopen("lm.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
				scanf("%d",&map[i][j]);
		bool OK(true);
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=M;j++)
			{
				bool ok(true);
				for (int k=1;k<=M;k++) if (map[i][k]>map[i][j])
				{
					ok=false;
					break;
				}
				if (ok) continue;
				ok=true;
				for (int k=1;k<=N;k++) if (map[k][j]>map[i][j])
				{
					ok=false;
					break;
				}
				if (!ok)
				{
					OK=false;
					break;
				}
			}
			if (!OK) break;
		}
		if (OK) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}

