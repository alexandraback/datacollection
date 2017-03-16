#include <cstdio>
#include <cstring>

const int MAXN=20, MAXS=100000;
int S[MAXN], last[MAXN*MAXS+1][2];
int main()
{
	int T, t, n, i, j, ts, ts1;
	freopen("C-small-attempt0 (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d", &n);
		memset(last, -1, sizeof(last));
		for(i=0; i<n; ++i)
		{
			scanf("%d", S+i);
			for(j=0; j<=MAXN*MAXS; ++j)
			{
				ts=S[i]+j;
				if((!j || (last[j][0]!=-1 && last[j][0]!=S[i])) && ts<=MAXN*MAXS)
					if(last[ts][0]==-1)
						last[ts][0]=S[i];
					else if(last[ts][1]==-1 && S[i]!=last[ts][0])
						last[ts][1]=S[i];
			}
		}
		for(ts=1; ts<=MAXN*MAXS; ++ts)
			if(last[ts][0]!=-1 && last[ts][1]!=-1)
			{
				printf("Case #%d:\n", t);
				printf("%d", last[ts][0]);
				ts1=ts;
				for(ts1-=last[ts1][0]; ts1; ts1-=last[ts1][0])
					printf(" %d", last[ts1][0]);
				printf("\n%d", last[ts][1]);
				ts1=ts;
				for(ts1-=last[ts1][1]; ts1; ts1-=last[ts1][0])
					printf(" %d", last[ts1][0]);
				printf("\n");
				break;
			}
		if(ts>MAXN*MAXS)
			printf("Case #%d:\nImpossible\n", t);
	}
	return 0;
}
