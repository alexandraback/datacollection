#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int x[7][7];
int mic[7];
int n,m;
bool chk = false;

void check()
{
	int i,j;
	int cnt = 0;
	memset(mic,0,sizeof(mic));
	mic[1] = 1;
	for(i=2;i<=n;i++)
	{
		for(j=i-1;j>=1;j--)
		{
			if(x[j][i])
			{
				mic[i] += mic[j];
			}
		}
	}
	if(mic[n] == m)
	{
		// for(i=1;i<=n;i++)
		// {
		// 	for(j=1;j<=n;j++)
		// 	{
		// 		printf("%d",x[i][j]);
		// 	}
		// 	printf("\n");
		// }
		chk = true;
	}
	return ;
}

void play(int ii,int jj)
{
	if(ii >= n || jj > n || ii >= jj)
		return;
	// printf("%d %d\n",ii,jj);
	x[ii][jj] = 1;
	check();
	if(chk)
		return;
	if(jj == n)
	{
		if(ii+1 < n)
			play(ii+1,ii+2);
	}
	else
		play(ii,jj+1);
	if(chk)
		return;
	x[ii][jj] = 0;
	check();
	if(chk)
		return;
	if(jj == n)
		if(ii+1 < n)
			play(ii+1,ii+2);
	else
		play(ii,jj+1);
	if(chk)
		return;
}

void solution()
{
	int i,j;
	chk = false;
	memset(x,0,sizeof(x));
	play(1,2);
	if(chk)
	{
		printf("POSSIBLE\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d",x[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("IMPOSSIBLE\n");
	}
}

int main()
{
	int t,loop,i,j;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	for(loop = 1;loop <= t;loop++)
	{
		scanf("%d %d",&n,&m);
		printf("Case #%d: ",loop);
		solution();
	}
	return 0;
}