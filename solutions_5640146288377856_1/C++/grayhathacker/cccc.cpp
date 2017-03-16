/*
jai shree ram _/\_
A hacker from NITP
*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int,char> msi;
typedef pair<int,int> pa;
typedef long long int ll;

ll ans,r,w,c;
int main()
{
	freopen("cl.in", "r", stdin);
  	freopen("bl.out", "w", stdout);
  	int t,p=1;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>r>>c>>w;
		ans=r*(c/w);
		if(c%w==0)
		ans+=w-1;
		else
		ans+=w;
		cout<<"Case #"<<p++<<": "<<ans<<"\n";
	}
	return 0;
}


