#include <iostream>
using namespace std;

int dp[1001][1001];

int solve(int i,int j)//split i atleast till j
{
	if(i<=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	else
	{
		int ans=100000;
		for(int i1=1;i1<=i/2;i1++)
			ans=min(ans,solve(i1,j)+solve(i-i1,j)+1);
		dp[i][j]=ans;
		return ans;
	}
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<1001;i++)	
		for(int j=0;j<1001;j++)
			dp[i][j]=-1;
	for(int qq=1;qq<=t;qq++)
	{
		int n;
		cin>>n;
		int c[1001]={};
		int c1[1001]={};
		int a[1001];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			c[a[i]]++;
		}
		int ans=100000;
		int i;
		for(int h=1;h<=1000;h++)
		{
				int ans1=0;
				for(i=1000;i>h;i--)
					c1[i]=c[i];
				for(i=1000;i>h;i--)
				{
					if(c1[i]!=0)
						ans1+=solve(i,h)*c1[i];
				}
				
				ans=min(ans1+h,ans);
			//	cout<<ans<<" ";
			
		}
	//	for(int i=0;i<n;i++)
	//		cout<<a[i]<<" ";
		cout<<"Case #"<<qq<<": "<<ans<<endl;
	}
	return 0;
}
