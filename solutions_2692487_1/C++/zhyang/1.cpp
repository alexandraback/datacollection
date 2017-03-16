#include<iostream>
#include <math.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[105][105];
int num[105];
int initial, n;

int main()
{
    freopen("c:\\1.in","r",stdin);
    freopen("c:\\1-out.txt","w",stdout);
    
    int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
    	cin>>initial>>n;
    	for(int i = 1; i <= n; ++i)
    	    cin>>num[i];
    	memset(dp, -1, sizeof(dp));
    	dp[0][0] = initial;
    	for(int i = 1; i <= n; ++i)
    	{
    		dp[0][i] = max(dp[0][i], dp[0][i-1]*2-1);
    	}
    	
    	sort(num+1, num+n+1);
    	
    	for(int i = 1; i <= n; ++i)
    	{
    		for(int j = 0; j <= n; ++j)
    		{
    			if(num[i] < dp[i-1][j])
    			{
    				dp[i][j] = max(dp[i][j], dp[i-1][j] + num[i]);
    			}
    			else if(j != 0)
    			{
    				dp[i][j] =max(dp[i][j], dp[i-1][j-1]); 
    			}
    		}
    		
    		for(int j = 1; j < n; ++j)
    		{
    			dp[i][j] = max(dp[i][j], dp[i][j-1]*2-1);
    		}
    	}
    	
    	int ans = 0;
    	for(int i = 0; i <= n; ++i)
    	{
    		if(dp[n][i] != -1)
    		{
    			ans = i;
    			break;
    		}
    	}
    	
    	cout<<"Case #"<<caseIndex<<": "<<ans<<endl;
    }
    
    return 0;
}
