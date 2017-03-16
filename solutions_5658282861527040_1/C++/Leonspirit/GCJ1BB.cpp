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
#define ft first
#define sc second
#define inf 3000000
#define lcm(a,b) a*b/__gcd(a,b)
#define lsb(a) (a & (-a))

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

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		ll a=getnum<ll>();
		ll b=getnum<ll>();
		ll k=getnum<ll>();
		ll ans=0;
		
		ans+=(min(a,k)*b);
		ans+=(min(b,k)*a);
		ans-=(min(a,min(b,k))*min(a,min(b,k)));
		printf("Case #%d: %lld\n",tc,ans);
	}
  return 0;
}


