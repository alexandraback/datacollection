#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define MOD 1000000007
string s,s2;
void cal(char c1,char c2,char& c3,int& flag)
{
	if(c1=='1')
	{
		c3=c2;flag=1;
	}
	else if(c1=='i')
	{
		if(c2=='1')c3='i',flag=1;
		else if(c2=='i')c3='1',flag=-1;
		else if(c2=='j')c3='k',flag=1;
		else if(c2=='k')c3='j',flag=-1;
	}
	else if(c1=='j')
	{
		if(c2=='1')c3='j',flag=1;
		else if(c2=='i')c3='k',flag=-1;
		else if(c2=='j')c3='1',flag=-1;
		else if(c2=='k')c3='i',flag=1;
	}
	else
	{
		if(c2=='1')c3='k',flag=1;
		else if(c2=='i')c3='j',flag=1;
		else if(c2=='j')c3='i',flag=-1;
		else if(c2=='k')c3='1',flag=-1;
	}
}
int main()
{
	int t,T;
	int i,n;
	long long x;
	bool flag;
	int fu,tfu;
	char c,tc;
	freopen("C-large.in","rt",stdin);
	freopen("C.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n>>x;
		cin>>s;
		flag=true;
		c='1';fu=1;
		for(i=0;i<n;i++)
		{
			cal(c,s[i],tc,tfu);
			c=tc;
			fu*=tfu;
		}
		if(c=='1')
		{
			if(fu==1||(x%2==0))
				flag=false;
		}
		else if(x%2==1)
		{
			flag=false;
		}
		else if(x%4==0)
			flag=false;
		if(flag)
		{
			s2="";
			for(i=0;i<x&&i<50;i++)
			{
				s2+=s;
			}
			n=s2.size();
			c='1';
			fu=1;
			for(i=0;i<n;i++)
			{
				cal(c,s2[i],tc,tfu);
				c=tc;
				fu*=tfu;
				if(fu==1&&c=='i')
					break;
			}
			if(i==n)
			{
				flag=false;
			}
			i++;
			c='1';
			fu=1;
			for(;i<n;i++)
			{
				cal(c,s2[i],tc,tfu);
				c=tc;
				fu*=tfu;
				if(fu==1&&c=='j')
					break;
			}
			if(i==n)
			{
				flag=false;
			}
		}
		if(flag)
			cout<<"Case #"<<t<<": "<<"YES"<<endl;
		else
			cout<<"Case #"<<t<<": "<<"NO"<<endl;
	}
    return 0;
}