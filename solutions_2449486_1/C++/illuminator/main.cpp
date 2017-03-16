#include <iostream>
#include <stdio.h>

using namespace std;

int lawn[100][100];

int x[100],y[100];

bool check(int N,int M)
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			x[j] = max(x[j],lawn[i][j]);
			y[i] = max(y[i],lawn[i][j]);
		}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if( lawn[i][j] != min(x[j],y[i]) )
				return false;

	return true;
}

int main()
{
	int T,N,M,c = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				scanf("%d",&lawn[i][j]);

		printf("Case #%d: ",c++);
		if(check(N,M)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}