#include <cmath> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

bool cmp(const int a, const int b)
{
	return a > b;
}

ll getNum(string s, int l, int r)
{
	ll ret=0;
	while(l<=r)
	{
		ret=ret*10LL;
		ret=ret+(s[l]-'0');
		l++;
	}
	return ret;
}

ll getReverseNum(string s, int l, int r)
{
	ll ret=0;
	while(r>=l)
	{
		ret=ret*10LL;
		ret=ret+(s[r]-'0');
		r--;
	}
	return ret;
}

ll change(string dist)
{
	ll ret=0;
	int len=dist.length();
	int mid=dist.length()/2;
	ll a=0,b=0;
	if(mid<=len-1)
	{
		b=getNum(dist,mid,len-1);
	}
	if(0<=mid-1)
	{
		a=getReverseNum(dist,0,mid-1);	//start from 1
	} 	
	if(a==1) a--;
	else if(b==0)
	{
		int pos=0;
		for(pos=len-1;pos>=0 &&  dist[pos]=='0';pos--)
		{
			dist[pos]='9';
		}	dist[pos]=dist[pos]-1;
		return (change(dist)+1);		
	} 
	//cout<<dist<<":"<<a<<":"<<b<<endl;
	return ret+a+b;
}

ll pls(int n)
{
	ll ret=0;
	string t="";
	for(int i=1;i<n;i++)
	{
		t=t+"9";
		ret+=change(t)+1;
	}
	return ret;
}

ll solve(string n)
{
	ll ret=0;
	ret+=pls(n.length());
	ret+=change(n);
	return ret; 
} 

int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
	int cases=0;
	scanf("%d",&cases);
	for(int _case=1;_case<=cases;_case++)
	{
		ll ans=0;
		string n;	
		cin>>n; 
		ans=solve(n);
		printf("Case #%d: %I64d\n",_case,ans);
	}
	return 0;
}
