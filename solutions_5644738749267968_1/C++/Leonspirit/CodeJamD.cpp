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

double naomi[1005],ken[1005];
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("outputD.txt","w",stdout);
	int testcase=getnum<int>();
	for(int tc=1;tc<=testcase;tc++)
	{
		int n=getnum<int>();
		for(int x=0;x<n;x++)scanf("%lf",&naomi[x]);
		for(int x=0;x<n;x++)scanf("%lf",&ken[x]);
		
		sort(naomi,naomi+n);
		sort(ken,ken+n);
		int ans1=0,ans2=0;
		
		int id=0;
		for(int x=0;x<n;x++)
		{
			if(naomi[x]>ken[id])
			{
				ans1++;
				id++;
			}
		}
		id=n-1;
		for(int x=n-1;x>=0;x--)
		{
			if(naomi[x]<ken[id])
			{
				id--;
			}
			else ans2++;
		}
		printf("Case #%d: %d %d\n",tc,ans1,ans2);
	}

  return 0;
}

