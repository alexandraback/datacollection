#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define mod1 1000000007ll
#define mod2 1000000009ll
int k,l,s;
char key[10];
char str[10];
char target[10];
long long h1,h2;
long long ans,c,pow1,pow2,maxx;
void go(int pos)
{
	int i,ans1=0;
	long long g1=0,g2=0;
	if(pos==s)
	{
		c++;
		if(l<=s)
		{
			for(i=0;i<l;++i)
			{
				g1=(g1*29+str[i])%mod1;
				g2=(g2*29+str[i])%mod2;
			}
			if(g1==h1&&g2==h2)
				ans1++;
			for(i=l;i<s;++i)
			{
				g1=(g1-(str[i-l]*pow1)%mod1+mod1)%mod1;
				g2=(g2-(str[i-l]*pow2)%mod2+mod2)%mod2;
				g1=(g1*29+str[i])%mod1;
				g2=(g2*29+str[i])%mod2;
				if(g1==h1&&g2==h2)
					ans1++;
			}
			maxx=max(maxx,(long long)ans1);
			ans+=ans1;
		}
	}
	else
	{
		for(i=0;i<k;++i)
		{
			str[pos]=key[i];
			go(pos+1);
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i,j;
	sd(t);
	for(j=1;j<=t;++j)
	{
		sd(k);
		sd(l);
		sd(s);
		scanf("%s",&key);
		scanf("%s",&target);
		h1=h2=0;
		ans=c=0;
		maxx=0;
		for(i=0;i<l;++i)
		{
			h1=(h1*29+target[i])%mod1;
			h2=(h2*29+target[i])%mod2;
		}
		pow1=pow2=1;
		for(i=1;i<l;++i)
		{
			pow1=(pow1*29)%mod1;
			pow2=(pow2*29)%mod2;
		}
		go(0);
		printf("Case #%d: %.7lf\n",j,maxx-((double)ans)/((double)c));

	}
}