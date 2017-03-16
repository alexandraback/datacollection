#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <typeinfo>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define CL(a,x)         memset(a,x,sizeof(a))
#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
#define asort(a,n)		sort(a,a+n)
#define vsort(v,n)		sort(v.begin(), v.begin()+n)
#define pb              push_back
#define X               first
#define Y               second
#define scan(i)			if (typeid(i)==typeid(int)) scanf("%d",&i);\
			else    if (typeid(i)==typeid(long long)) scanf("%lld",&i);\
			else    scanf("%s",&i);
#define print(i)		if (typeid(i)==typeid(int)) printf("%d",i);\
			else    if (typeid(i)==typeid(long long)) printf("%lld",i);\
			else    printf("%s",i);
#define nl		printf("\n");

struct node{
	int x,y,step;
	string dir;
	node(int xx,int yy,int ss, string d): x(xx), y(yy), step(ss), dir(d) {}
};

char sym[4] = {'N','E','S','W'};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

string solve(int xd, int yd)
{
	string s="";
	if (xd<0)
	{
		xd = -xd;
		REP(i, xd) s+="EW";
	}
	else
	{
		REP(i, xd) s+="WE";
	}
	if (yd<0)
	{
		yd = -yd;
		REP(i, yd) s+="NS";
	}
	else
	{
		REP(i, yd) s+="SN";
	}
	return s;
}

int main()
{
	int xd=-3,yd=4,t;
	cin >> t;
	REP(i, t)
	{
		cin >> xd >> yd;
		cout << "Case #"<<i+1<<": "<<solve(xd,yd)<<endl;
	}
	return 0;
}
