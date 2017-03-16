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

set<ll>cek;

int find(ll a, ll b)
{
	if(a*2>=b)return 1;
	else return 1+find(a*2,b);
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	ll now=1;
	for(int x=1;x<=50;x++)
	{
		now*=2;
		//cout<<now<<endl;
		cek.insert(now);
	}
	
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		ll p,q;
		scanf("%lld/%lld",&p,&q);
		
		ll t=__gcd(p,q);
		p/=t; q/=t;
		int check=cek.size();
		cek.insert(q);
		if(cek.size()!=check)
		{
			cek.erase(q);
			printf("Case #%d: impossible\n",tc);
		}
		else
		{
			int ans=find(p,q);
			printf("Case #%d: %d\n",tc,ans);
		}
	}	

  return 0;
}

