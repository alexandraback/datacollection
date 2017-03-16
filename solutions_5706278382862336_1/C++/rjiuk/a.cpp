#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

string l;
LL a=0,b=0;

LL gcd(LL x,LL y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

void zamien()
{
	a=0;b=0;
	LL razy = 1;
	bool zm =0;
	for(int i = l.size()-1;i>=0;i--)
	{
		if(l[i]=='/')
		{
			zm=1;
			razy=1;
			continue;	
		}

		if(zm == 0)
		{
			b=b+(l[i]-'0')*razy;
			razy*=10;
		}
		else
		{
			a=a+(l[i]-'0')*razy;
			razy*=10;
		}
	}
}

int spr()
{
	LL r = 1;
	int p = 0;
	while(r<b)
	{
		r*=2;
		p++;
	}
	if(b==r)
		return p;
	else
		return 0;
}

int licz()
{
	return log2(a);
}

void dane()
{
	int t;
	cin>>t;
	FOR(przy,0,t)
	{
		cin>>l;
		zamien();		
		LL d = gcd(a,b);
		a/=d;
		b/=d;
		int odp = spr();
		if(!odp)
			printf("Case #%d: impossible\n",przy+1);
		else
		{
			int szukane = licz();
			printf("Case #%d: %d\n",przy+1,odp - szukane);
		}
	}
}

int main()
{
	dane();
	return 0;
}
