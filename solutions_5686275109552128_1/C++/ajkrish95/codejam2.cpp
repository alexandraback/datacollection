#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)

long long MOD = int(1e9) + 7;

const int N = 1000*100+5;
int debug = 1;
const int M = 1005;
int dp[2000][2000];
int a[2000];

int main()
{
      int i,j,n,t,k, ans;
    	
    	cin>> t;
    	
      for(i=1;i<=1000;i++)
      {
      	for(j=1;j<1001;j++)
      	{
      		dp[i][j] = (j-1)/i;
      	}
      }

      int t1;
      
	f(t1,1,t+1)
	{
		cin>>n;
		
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		ans = M;
		
		for(int k = 1; k < M; k++)
		{
			int cur = 0;
			
			for(i=0;i<n;i++)
			{
				cur = cur + dp[k][a[i]];
			}
			
			cur = cur + k;
			
			ans = min(ans,cur);
		}
		
		cout<<"Case #"<<t1<<": "<<ans<<endl;
      }      
}
