#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
using namespace std;

double cal(int a, int b)
{
	double ans = 1;
	for(int i = 1; i <= a; ++i)
	{
		ans *= ((double)(b-i+1)/(double)i);
	}
	
	for(int i = 1; i <= b; ++i)
	    ans /= 2;
	return ans;
}

int main()
{
	
	freopen("c:\\2.in","r",stdin);
    freopen("c:\\2-out.txt","w",stdout);
    
	int total, x, y;
	int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
    	double ans = 0;
    	cin>>total>>x>>y;
    	int cycle = (abs(x) + abs(y))/2+1;
    	int need = (cycle*2-1)*cycle;
    	
    	int last = (cycle*2-3)*(cycle-1);
    	int require = need - last;
    	int has = total - last;
    	
    	if(need <= total)
    	{
    		ans = 1;
    		goto print;
    	}
    	
    	if(x == 0 && total < need)
    	{
    		ans = 0;
    		goto print;
    	}
    	
    	
    	if(has <= y)
    	{
    		goto print;
    	}
    	
    	if(has >= cycle*2+y-1)
    	{
    		ans = 1;
    		goto print;
    	}
    	
    	for(int i = y+1; i <= has; ++i)
    	    ans += cal(i, has);
/*    	
    	double dp[20][10];
    	memset(dp, 0, sizeof(dp));
    	dp[0][0] = 1;
    	for(int i = 0; i < has; ++i)
    	{
    		for(int j = 0; j <= cycle*2-2; ++j)
    		{
    			if(i - j <= cycle*2-2)
    			{
    				dp[i+1][j] += (dp[i][j-1]+dp[i][j-1]) * 0.5;
    			}
    			else
    			{
    				dp[i+1][j] += dp[i][j-1];
    			}
    		}
    	}
    	
    	for(int i = y+1; i <= cycle*2-2; ++i)
    	    ans += dp[has][i];
*/    	    
    print:
	    cout<<"Case #"<<caseIndex<<": "<<fixed<<setprecision(8)<<ans<<endl;
    }
    return 0;
} 
