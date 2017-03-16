#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

long long tmp;
long long x[100];
int chk[100][100];

void solution()
{
	int i,j,n,cnt;
	memset(chk,0,sizeof(chk));
	long long m;
	scanf("%d %lld",&n,&m);
	for(i=1;;i++)
	{
		if(x[i] > m)
			break;
	}
	cnt = i-1;
	if(cnt > n)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	for(i=1;i<=cnt;i++)
	{
		for(j=i+1;j<=cnt;j++)
		{
			chk[i][j] = 1;
		}
	}
	m -= x[cnt];
	while(m > 0)
	{
		for(i=1;;i++)
		{
			if(x[i] > m)
				break;
		}
		if(chk[i-1][n] == 1)
			break;
		chk[i-1][n] = 1;
		m -= x[i-1];
	}
	if(m > 0)
		printf("IMPOSSIBLE\n");
	else
	{
		printf("POSSIBLE\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d",chk[i][j]);
			}
			printf("\n");
		}
	}
}

int main()
{
	int i,j,t;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	x[1] = 1;
	x[2] = 1;
   	for(i=3;i<=62;i++)
   	{
   		x[i] = x[i-1] * 2;
   	}
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solution();
	}
	return 0;
}
