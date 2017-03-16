

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;

#define MAX 10000050
#define ll long long

vector<ll> pal;

int check(ll x)
{
	ll y=0;
	ll a=x;
	while(x)
	{
		y=y*10+x%10;
		x/=10;
	}
	if(y==a)
		return 1;
	else
		return 0;
}

void generate()
{
	for(int i=1;i<MAX;i++)
		if(check(i))
			pal.push_back(i);
}

int main()
{
//	freopen("C-small-attempt0.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	generate();
	ll a,b;
	int ans;
	for(int cas=0;cas<t;cas++)
	{
		cin>>a>>b;
		ans=0;
		for(int i=0;i<pal.size()&&pal[i]*pal[i]<=b;i++)
		{
			if(pal[i]*pal[i]<a)
				continue;
			if(check(pal[i]*pal[i]))
			{
				ans++;
			}
		}
		printf("Case #%d: %d\n",cas+1,ans);
	}
    return 0;
}
