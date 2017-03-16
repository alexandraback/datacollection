#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define Ari using
#define ganteng namespace
#define banget std

#define ll long long
#define ul unsigned long long
#define pb push_back
#define mp make_pair
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))
#define ft first
#define sc second
#define inf 10000000

#define STRtoINT(a,b) istringstream(a)>>b
#define INTtoSTR(a,b) b=static_cast<ostringstream*>(&(ostringstream()<<a))->str()

//set -> pair <set<int>::iterator,bool> pa; pa=set.insert(x); pa.second return bool;

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

Ari ganteng banget;

double C,F,X;
double memo[100005];
double rate[100005];
double buy[100005];

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		memset(memo,0,sizeof memo);
		memset(rate,0,sizeof rate);
		memset(buy,0,sizeof buy);
		scanf("%lf%lf%lf",&C,&F,&X);
		rate[0]=2;
		memo[0]=X/rate[0];
		for(int x=1;x<=X;x++)
		{
			rate[x]=rate[x-1]+F;
			buy[x]=C/rate[x-1];
			buy[x]+=buy[x-1];
			memo[x]=buy[x];
			memo[x]+=X/rate[x];
		}
		double ans=200000;
		for(int x=0;x<=X;x++)ans=min(ans,memo[x]);
		printf("Case #%d: %.7lf\n",tc,ans);
	}

  return 0;
}

