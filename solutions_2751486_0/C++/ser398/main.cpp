#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
//char ss[2000000];
string s;
#define forn(i,n) for(int i=0;i<(int)n;i++)
void solve()
{
	int n;
	cin>>s;
	cin>>n;
	int l=0;
	int u=-1;
	long long ans=0;
	int N=s.size();
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		{
			if(l>=n)
				u=i+n;
			l=0;
		}
		else
		{
			l++;
		}
		if(l>=n)
		{
			ans+=N-i-n+1;
		}
		else
		{
			if(u==-1)
				continue;
			ans+=N-u;
		}

	}
	cout<<ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	forn(i,t)
	{
		printf("Case #%d: ",i+1);
		solve();
		puts("");
	}
	return 0;
}
