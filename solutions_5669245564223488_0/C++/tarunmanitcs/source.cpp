#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;
string s[105];
long long n,ans;

int fn(int a,string x,int xxx[105])
{
	int i,j;
	if(a==n)
	{
		int c[26]={0};
		for(i=0;i<x.size();i++)
		{
			if(c[x[i]-'a']==1)
				break;
			else
			{
				c[x[i]-'a']=1;
				for(j=i+1;j<x.size();j++)
				{
					if(x[j]!=x[i])
						break;
				}
				i=j-1;
			}
		}
		if(i==x.size())
			ans++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<a;j++)
		{
			if(xxx[j]==i)
				break;
		}
		if(j==a)
		{
			xxx[a]=i;
			fn(a+1,x+s[i],xxx);
		}
	}
}
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int t,i,j,k,l,m;
	cin>>t;
	for(l=1;l<=t;l++)
	{
		long long x[26]={0},st[26]={0},en[26]={0};
		ans=0;
		cout<<"Case #"<<l<<": ";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s[i];			
		}
		int xxx[105];
		fn(0,"",xxx);
		cout<<ans<<endl;
	}
	return 0;
}