#define DEBUG 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=n-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

void Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if (c=='-')
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
}

vector <LL> V;

bool pal(string s)
{
	int i;
		Fox(i,Sz(s))
			if (s[i]!=s[Sz(s)-i-1])
				return(0);
	return(1);
}

string toS(LL v)
{
	string s="";
		while (v)
			s=char(v%10+'0')+s,v/=10;
	return(s);
}

int toI(string s)
{
	int v=0,i;
		Fox(i,Sz(s))
			v=v*10+s[i]-'0';
	return(v);
}

void rec(string s)
{
	int i;
		if (Sz(s)>7)
			return;
	i=toI(s);
		if (i)
			if (pal(toS((LL)i*i)))
				V.pb((LL)i*i);
		Fox(i,10)
			rec(char(i+'0')+s+char(i+'0'));
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	LL A,B;
	int i,c;
	string s;
	rec("");
		Fox(i,10)
		{
			s="";
			rec(s+char(i+'0'));
		}
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d: ",t);
			scanf("%lld%lld",&A,&B);
			c=0;
				Fox(i,Sz(V))
					if ((V[i]>=A) && (V[i]<=B))
						c++;
			printf("%d\n",c);
		}
	return(0);
}