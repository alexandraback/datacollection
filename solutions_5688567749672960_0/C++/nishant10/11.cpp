#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back
#define MAX 1000000
using namespace std;

typedef pair<int,int> pr;
typedef long long ll;
int dp[1000001];
int R[1000001];

int reverse(int val)
{
	int ans,rem;
	
	ans = 0;
	while(val)
	{
		rem = val%10;
		ans = ans*10 + rem;	
		val = val/10;
	}	
	return ans;
}

int main()
{

	int t,i,n,z,ind;
	
	ind = 1;
	scanf("%d",&t);

	for(i  = 1;i <= 1000000;i++)
	{
		z = reverse(i);
		R[i] = z;
	}
	while(t--)
	{
		scanf("%d",&n);
		dp[n] = 1;
		//cout<<R[12]<<" "; 
		for(i = n-1;i >= 1;i--)
		{
			if((R[i] > i) && (R[i] <= n))
			{
				dp[i] = min(dp[i+1] + 1,dp[R[i]]+1);
			}
			else
				dp[i] = dp[i+1] + 1;
					
		}		
		printf("Case #%d: %d\n",ind,dp[1]);
		//printf("%d\n",dp[12]);
		ind++;
		
	}

	return 0;
}
