#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<iostream>
#include<cmath>
using namespace std;
long long mod = 1000000007;
int ar[51][51];
long long way[51];
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int B; long long M; cin>>B>>M;
		int N = B; way[1] = 1;
		for(int i=0;i<51;i++) for(int j=0;j<51;j++) ar[i][j] = 0;
	//	cout<< "M = "<<M<<endl;
		for(int i=2;i<51;i++) 
		{
			long long t = 0;
			for(int j = 1;j<i;j++) 
			{
				t+= way[j]; if(t>=M) break;
			}
			way[i] = t;
		}
		way[1] = 1;
		//for(int i=1;i<=50;i++) printf("way(%d)  = %lld\n",i,way[i]);
		for(int i=1;i<N;i++)
		for(int j=i+1;j<N;j++) ar[i][j] = 1;
		
		//printf("here\n");
		for(int j=N-1;j>0;j--)
		{
		//	printf("here j = %d\n",j);
			if(M>=way[j]) 
			{
	//			printf("here %lld\n",M);
				M-=way[j]; ar[j][N] = 1;
			}
		}
		
		if(M==0)
		{
			printf("POSSIBLE\n");

		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++) printf("%d",ar[i][j]);
			printf("\n");
		}
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
} 

