#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 3000

int X,Y,N;
int T;
int C;

double F[MAXN][MAXN];

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	F[0][0] = 1.;
	for (i=0;i<MAXN-1;i++)
	{
		for (j=0;j<MAXN-1;j++)
		{
			F[i+1][j] += 0.5 * F[i][j];
			F[i][j+1] += 0.5 * F[i][j];
		}
	}
	for (int cases=1;cases<=T;cases++)
	{
		printf("Case #%d: ",cases);
		scanf("%d%d%d",&N,&X,&Y);
		C =( abs(X) + abs(Y)) / 2;
		for (i=0;i<C && N > 0;i++)
			N -= 4*i+1;
		if (N <= 0)
		{
			printf("0.0\n");
			continue;
		}
		if (N >= 4*C + 1 || Y+1 + 2*C <= N)
		{
			printf("1.0\n");
			continue;
		}
		if (Y == 2*C)
		{
			printf("0.0\n");
			continue;
		}

		double ans=0.;
		
		for (i=Y+1;i<=N;i++)
			ans += F[i][min(N,2*C)-i];

		printf("%.8f\n",ans);
	}
	return 0;
}
