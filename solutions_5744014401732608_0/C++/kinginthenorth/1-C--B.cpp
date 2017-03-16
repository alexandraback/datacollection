#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long power(long long a)
{
	long long ans=1;
	for(int i=1;i<=a;i++)
	{
		ans*=2;
	}
	return ans;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		long long b,m;
		cin>>b>>m;
		int a[b+1][b+1],i,j;
		for(i=1;i<=b;i++)
		{
			for(j=1;j<=b;j++)
			{
				a[i][j]=0;
			}
		}
		long long max=power(b-2);
		int r;
		bool flag=false;
		if(m==max)
		{
			m--;
			flag=true;
		}
		if(m<max)
		{
			cout<<"Case #"<<cno<<": POSSIBLE"<<endl;
			for(i=1;i<=b-2;i++)
			{
				for(j=i+1;j<b;j++)
				{
					a[i][j]=1;
				}
			}
			i=2;
			while(m)
			{
				if(m%2)
				{
					a[i][b]=1;
				}
				m/=2;
				i++;
			}
			if(flag)
				a[1][b]=true;
			for(i=1;i<=b;i++)
			{
				for(j=1;j<=b;j++)
				{
					printf("%d",a[i][j]);
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"Case #"<<cno<<": IMPOSSIBLE"<<endl;
		}
	}
	return 0;
}
