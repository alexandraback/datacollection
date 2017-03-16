#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int reverse(int n)
{
	int rev =0 ;
	int max_x = n;
		 while (n != 0)
		   {
			  rev = rev * 10;
			  rev = rev + n%10;
			  n       = n/10;
			  
		   }
		
		if(rev < max_x && max_x%10)
		{
			return rev;
		}
		else return 0;
		
}
int main()
{
	int t,cas=0;
	scanf("%d",&t);
	int arr[15];
	int dp[1000005];
	dp[0]=1000000;dp[1] = 1;
	for(int i=2;i<=20;i++)
		dp[i]=i;
	for(int i=21;i<1000005;i++)
	{
		dp[i]= min (dp[reverse(i)]+1, dp[i-1]+1);
	}
	while(t--)
	{
		int max_x=0,N;
		
		scanf("%d",&N);
		
			printf("Case #%d: %d\n",++cas,dp[N]);
		
	}
	return 0;
}
