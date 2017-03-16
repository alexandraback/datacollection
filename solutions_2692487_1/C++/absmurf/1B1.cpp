#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	int T,i,j;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		int A,N;
		scanf("%d", &A);
		scanf("%d", &N);
		int mote[N];
		for(i=0;i<N;i++)
			scanf("%d", &mote[i]);
		sort(mote,mote+N);
		long long D[N+1][N+1]; //max size reachable in i-mote no. j-no of moves
		for(i=0;i<=N;i++)
					for(j=0;j<=N;j++) D[i][j]=-1;
		D[0][0]=A;
		for(j=1;j<=N;j++)
		{
			D[0][j]=2*D[0][j-1]-1;
		}
		for(i=1;i<=N;i++)
		{
			for(j=0;j<=N;j++)
			{
				if(j>0&&D[i][j-1]>=0) D[i][j]=2*D[i][j-1]-1;
				if(D[i-1][j]>mote[i-1]) D[i][j]=max(D[i][j],D[i-1][j]+mote[i-1]);
				if(j>0) D[i][j]=max(D[i][j],D[i-1][j-1]);
				//cout<<D[i][j]<<" ";
			}
			//cout<<endl;
		}for(j=0;j<=N;j++) if(D[N][j]>=0) break;
		//cout<<D[0][N-1]<<endl;
		printf("Case #%d: %d\n",c,j);
	}
	return 0;
}
