#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a[111][111];
int now[111][111];

int main(void)
{
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
	int T = 0;
	scanf("%d",&T);
	int TK = 0;
	while(T--)
	{
		printf("Case #%d: ",++TK);
		int N = 0;
		int M = 0;
		scanf("%d %d",&N,&M);
		for(int i = 0;i < N;i++)
		{
			for(int j = 0;j < M;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i = 0;i < N;i++)
		{
			for(int j = 0;j < M;j++)
			{
				now[i][j] = 100;
			}
		}
		for(int i = 0;i < N;i++)
		{
			int tmax = a[i][0];
			for(int j = 0;j < M;j++) tmax = max(tmax,a[i][j]);
			for(int j = 0;j < M;j++) now[i][j] = min(now[i][j],tmax);
		}
		for(int j = 0;j < M;j++)
		{
			int tmax = a[0][j];
			for(int i = 0;i < N;i++) tmax = max(tmax,a[i][j]);
			for(int i = 0;i < N;i++) now[i][j] = min(now[i][j],tmax);
		}
		/*puts("------");
		for(int i = 0;i < N;i++)
		{
			for(int j = 0;j < M;j++) printf("%d ",now[i][j]);
			puts("");
		}
		puts("------");*/
		bool eq = true;
		for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) eq &= a[i][j] == now[i][j];
		puts(eq ? "YES" : "NO");
	}
	return 0;
}
