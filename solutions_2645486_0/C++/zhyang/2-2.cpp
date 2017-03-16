#include<iostream>
#include <math.h>
#include<string.h>
using namespace std;

int dp[15][15];
int v[15];

int main()
{
	freopen("c:\\2.in","r",stdin);
    freopen("c:\\2-out.txt","w",stdout);
    
    int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex<= T; ++caseIndex)
    {
    	int e, r, n;
    	cin>>e>>r>>n;
    	for(int i = 1; i <= n; ++i)
    	   cin>>v[i];
    	memset(dp, -1, sizeof(dp));
    	/*for(int i = 1; i <= n; ++i)
    	{
    		for(int j = r; j <= e; ++j)
    		    for(int k = 0; k <= e; ++k)
    		        dp[i][j] = max(dp[i][j], dp[i-1][k] + (r-j+k)*v[i]);
    	}*/
    	
    	for(int i = 0; i <= e; ++i)
    	    dp[0][i] = 0;
    	
    	for(int i = 1; i <= n; ++i)
    	{
    		for(int j = 0; j <= e; ++j)
    		{
    			if(dp[i-1][j] != -1)
    			{
    				for(int k = 0; k <= j; ++k)
    				{
    					int remain = j-k+r;
    					if(remain>e)
    					    remain = e;
    					dp[i][remain] = max(dp[i][remain], dp[i-1][j] + k*v[i]);
    				}
    			}
    		}
    	}
/*    	
    	for(int i = 1; i <= n; ++i)
    	{
    	    for(int j = 0; j <= e; ++j)
    	        cout<<dp[i][j]<<" ";
    	    cout<<endl;
    	}
  */  	
    	int ans = 0;
    	for(int i = 0; i <= e; ++i)
    	    ans = max(ans, dp[n][i]);
    	cout<<"Case #"<<caseIndex<<": "<<ans<<endl;
    }
    return 0;
}
