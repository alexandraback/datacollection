#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int M = 1050;
int best[M+1][M];

int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		int D;
		cin >> D;
		for(int i=0;i<M;i++) best[0][i] = 0;
		for(int j=1;j<=M;j++)
			for(int i=0;i<M;i++) 
				best[j][i] = 100*M;

		for(int i=0;i<D;i++)
		{
			int x;
			scanf("%d", &x);
			for(int k=min(x, M-1);k>=0;k--)
			{
				int l = x/(k+1)+((x%(k+1)) > 0);
				for(int j=k;j<M;j++)
					best[i+1][j] = min(best[i+1][j], max(l, best[i][j-k]));
			}	
		}
		int ans = M;
		for(int i=0;i<M;i++) ans = min(ans, i+best[D][i]);
		
		printf("Case #%d: %d\n", test_num, ans);	
	}
	
	return 0;
}
