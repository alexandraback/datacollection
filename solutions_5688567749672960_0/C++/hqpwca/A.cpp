#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<functional>
#include<string>
#define INF 1000000007
#define ll long long
#define rep(i,k) for(int i=G.start[k];i!=INF;i=G.next[i])

using namespace std;

ll z9[100]={0},inp[100]={0};

ll reverse(ll k)
{
	ll res=0;
	while(k)
	{
		res*=10;
		res+=k%10;
		k/=10;
	}
	return res;
}

int main()
{
freopen("t.in","r",stdin);
freopen("t.out","w",stdout);
	for(int i=1;i<15;i++)
		z9[i]=z9[i-1]*10+9;
	inp[0]=1,inp[1]=9;
	for(int i=2;i<15;i++)
	{
		int s1=i/2;
		int s2=i-s1;
		inp[i]=z9[s1]+z9[s2]+1;
	}
	int T;
    cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		ll n,ans=0;
		ll L=0,R=0;
		cin>>n;
		int digit[100]={0},p=0;
		while(n)
		{
			digit[p++]=n%10;
			n/=10;
		}
		for(int i=(p-1)/2;i>=0;i--)
			R*=10,R+=digit[i];
		for(int i=p-1;i>(p-1)/2;i--)
			L*=10,L+=digit[i];
		ll revL=reverse(L);
		for(int i=0;i<p;i++)ans+=inp[i];
		if(R==0)
		{
			ll revL1,add;
			if(revL!=1)
			{
				revL1=reverse(L-1);
				add=revL1+z9[(p+1)/2]+(revL1!=1);
			}
			else
			{
				add=0;
			}
			ans+=add;
		}
		else
		{
			ll add;
			if(revL!=1)
			{
				add=revL+R;
			}
			else
			{
				add=R;
			}
			ans+=add;
		}
		if(L==0)ans--;
		
		printf("Case #%d: %lld\n",cas,ans);
	}
	
	return 0;
}
