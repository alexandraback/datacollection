#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>
#include<sstream>

using namespace std;
typedef long long ll;

const int max_n=15;

int T,n,E,R;
int dp[max_n][max_n];
int v[max_n];

int main()
{
    scanf("%d",&T);
	for(int z=1; z<=T; z++)
	{
		scanf("%d%d%d",&E,&R,&n);
		for(int i=0; i<n; i++)
			scanf("%d",&v[i]);
			
		for(int i=1; i<=n; i++)
			for(int x=R; x<=E; x++)
			{
				dp[i][x]=0;
				for(int y=0; y<=E; y++)
					for(int z=0; z<=E; z++)
						if(min(y-z+R,E)==x)
						{
							//cout<<x<<endl;
							dp[i][x]=max(dp[i][x],dp[i-1][y]+z*v[i-1]);
						}
				//cout<<i<<" "<<x<<" "<<dp[i][x]<<endl;
			}
			
		int res=0;
		for(int i=R; i<=E; i++)
			res=max(res,dp[n][i]);
			
		printf("Case #%d: ",z);
		printf("%d\n",res);
    }
	
    return 0;
}
