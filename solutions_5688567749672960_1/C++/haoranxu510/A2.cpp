#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

int dp[100000010];

LL toInteger(string s)
{
	int flag=1, beg=0; 
	if (s[0]=='-') flag=-1, beg=1;
	LL val=0;
	rep(i,beg,int(s.size())-1)
	{
		if (s[i]<'0' || s[i]>'9') break;
		val=val*10+s[i]-48;
	}
	return val*flag;
}

string toString(LL x)
{
	string ret=""; int flag=0;
	if (x==0) ret="0";
	if (x<0) flag=1, x=-x;
	while (x) ret=char(x%10+48)+ret, x/=10;
	if (flag) ret="-"+ret;
	return ret;
}

LL go(LL s, LL t)
{
	if (s==t) return 0;
	string z=toString(t);
	int n=z.length();
	if (n==1) return t-s;
	string zz=z.substr(0,n/2);
	reverse(zz.begin(),zz.end());
	LL k1=toInteger(zz), k2=toInteger(z.substr(n/2,n-n/2));
	return min(k1+k2,t-s);
}

LL run(LL goal)
{
	LL c=1, ret=1;
	if (goal%10==0) goal--, ret++;
	while (goal>=c*10) 
	{
		ret+=go(c,c*10-1)+1;
		c*=10;
	}
	ret+=go(c,goal);
	return ret;
}

void lemon()
{
	LL x; scanf("%lld",&x);
	printf("%lld\n",run(x));
}

int rev(int x)
{
	int y=0;
	while (x) y=y*10+x%10, x/=10;
	return y;
}

void su(int &a, int b)
{
	a=min(a,b);
}

#define INF 1000000000

void prework()
{
	dp[1]=1; rep(i,2,100000000) dp[i]=INF;
	rep(i,1,100000000)
	{
		su(dp[i+1],dp[i]+1);
		su(dp[rev(i)],dp[i]+1);
	}
	rep(i,1,100000000)
	{
		if (run(i)!=dp[i]) 
			printf("fail %d\n",i);
	
		if (i%1000000==0) printf("ok %d\n",i);
	}
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	//prework();
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) 
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

