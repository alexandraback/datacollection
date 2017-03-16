#include <bits/stdc++.h>
    using namespace std;
    
    #define pb push_back
    typedef pair<int,int> P;
    typedef long long ll;
    #define mp make_pair
    #define fi first
    #define sc second
    #define INF 100000000
     
    int main()
    {
    freopen ("input1.txt","r",stdin);
	freopen ("output1.txt","w",stdout);
    	int T; 
    	cin >> T;
     
    	for(int i=0;i<T;i++)
    	{
    		printf("Case #%d: ",i+1);
    		string x[16],y[16];
    		int a[16],b[16];
    		int n; 
    		cin >> n;
    		map<string,int>M,N;
    		for(int i=0;i<n;i++)
    		{
    			cin >> x[i] >> y[i];
    			M[x[i]] = 0;
    			N[y[i]] = 0;
    		}
    		int nx = 1;
    		for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
    		{
    			it->sc = nx++;
    		}
    		nx = 1;
    		for(map<string,int>::iterator it=N.begin();it!=N.end();it++)
    		{
    		
    			it->sc = nx++;
    		}
    		for(int i=0;i<n;i++)
    		{
     
    			a[i] = M[x[i]];
    			b[i] = N[y[i]];
    		}
    		int dp[(1<<16)+5]={}; fill(dp,dp+(1<<n),-100000);
    		dp[0] = 0;
    		for(int i=0;i<(1<<n);i++)
    		{
    			int L=0,R=0;
    			for(int j=0;j<n;j++)
    			{
    				if(((i>>j)&1))
    				{
    					L |= (1<<a[j]);
    					R |= (1<<b[j]);
    				}
    			}
    			for(int j=0;j<n;j++)
    			{
    				if(!((i>>j)&1))
    				{
    					int ad = ( (L|(1<<a[j]))==L && (R|(1<<b[j]))==R );
    					dp[i+(1<<j)] = max(dp[i+(1<<j)],dp[i]+ad);
    				}
    			}
    		}
     
    		cout << dp[(1<<n)-1] << endl;
    	}
    }
