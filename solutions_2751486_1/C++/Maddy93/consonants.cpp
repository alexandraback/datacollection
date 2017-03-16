#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1000001
int main()
{
	int t,n,last[MAX];
	long long int ans;
	string s;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0;
		cin>>s;
		cin>>n;
		int l=s.length();
		if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u')last[0]=0;
		else last[0]=1;
		for(int i=1;i<l;i++)
		{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')last[i]=0;
			else last[i]=last[i-1]+1;
		}
		for(int i=0;i<l;i++)
		{
			if(last[i]>=n)last[i]=1;
			else last[i]=0;
		}
		int x=-1;
		for(int i=0;i<l;i++)
		{
			if(last[i]==1)
			{
				x=i;
				ans+=2+(i-n);
			}
			else
			{
				if(x!=-1)ans+=2+(x-n);
			}
		}
		cout<<"Case #"<<k<<": "<<ans<<"\n";
	}
	return 0;
}
