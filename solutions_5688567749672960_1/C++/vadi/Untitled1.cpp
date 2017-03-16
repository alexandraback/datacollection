#include <bits/stdc++.h>
using namespace std;

long long rev(long long int j)
{
	long long int i=0;
	int dig=0;
	
	if(j%10==0)
		return j;
	long long temp=j;
	while(temp)
	{
		dig++;
		temp/=10;
	}
	while(j)
	{
		i+=j%10*pow(10,dig-1);
		dig--;
		j/=10;
	}
	return i;
}
long long dp[1000002];
long long  solve1(long long n)
{
//cout<<n<<" "<<rev(n)<<endl;
	
	if(n==1)
		return 1;
	if(dp[n]!=-1)
		return dp[n];
	else
	{

		if(rev(n)<n)
		{
			
			int ans1=n,idx;
			for(int i=0;i<10;i++)
				if(rev(n-i)<ans1)
				{
					idx=i;
					ans1=rev(n-i);
				}
			
			dp[n]=idx+1+solve1(ans1);
		
		}
		else
			dp[n]=1+solve1(n-1);
		return dp[n];
	}
}
long long solve(long long n,int f,int k)
{
	if(k>10)
		return pow(10,14);
	long long ans=0;
	if(n<=1000000)
		return solve1(n);
	
			
		long long temp=n,c=0;
		while(temp)
		{
			c++;
			temp/=10;
		}
		int k1;
		
	//	cout<<(n-n%(long long)(pow(10,(c-1))))<<endl;
		if(rev(n)>n&&n-n%(long long)(pow(10,(c-1)))==pow(10,(c-1))&&n!=pow(10,(c-1))&&f==0)
		{
			int h=c-1;
			c-=2;
					
			int kk=0;
			while(n-n%(long long)pow(10,(c--))==pow(10,(h)))
				kk++;
			
			if(kk!=0)
			{
				ans+=n%(long long)pow(10,kk+1)-1;
				n-=n%(long long)pow(10,kk+1);
				n++;
			}
			f=1;
		}
		else
			f=0;
	//	cout<<n<<" "<<rev(n)<<endl;
		long long ans1=n,idx;
		if(rev(n)<n)
		{
			for(int i=0;i<10;i++)
				if(rev(n-i)<ans1)
				{
					idx=i;
					ans1=rev(n-i);
				}
			
			return 1+idx+ans+solve(ans1,f,0);
		}
		else
	{		return 1+solve(n-1,f,0);
	//		cout<<"HAHA";
	}
			
		
	
}
int main() {
	int t;
	cin>>t;
		for(int tt=1;tt<=1000001;tt++)
		dp[tt]=-1;
	for(int tt=1;tt<=t;tt++)
	{
		long long n;
		cin>>n;
		long long ans=0;
		long long int i=1;
		int f=0;
			
		
		cout<<"Case #"<<tt<<": "<<solve(n,0,0)<<endl;
			
	}
	
	return 0;
}
