#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
using namespace std;
#define REP(i,n) for(int i=0,n_=(n);i<n_;i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOR(i,a,b) for (int i=a,b_=b;i<=(b);i++)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)(a).size()
#define SORT(a) sort(ALL(a))
#define INF 1073741823
#define DEB(x) cerr<<#x<<":"<<x<<"\n"
#define PB(b) push_back(b)
#define i64 long long
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

vector<int> SplitInt(string &s)
{
	vector<int>Res;int tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

vector<string> SplitStr(string &s)
{
	vector<string>Res;string tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

//////////////////////////////////////////////////////////////

struct T
{
	long long nt,nb;
	int t,b;
};
bool operator <(const T&a,const T&b)
{
	if (a.t==b.t)
	{
	if (a.b==b.b)
	{
		if(a.nt==b.nt)
		return a.nb<b.nb;
		else
		return a.nt<b.nt;
	}
	else
		return a.b<b.b;
	}
//	else
		return a.t<b.t;
}

map<T,long long> DP[3][100];
int Type[1231];
long long Tn[100],Bn[100];
int Tt[100],Bt[100];
int n,m;

long long go (T s,int a,int b)
{
	if (a==n||b==m)
	{
		return 0;
	}
	if (DP[a][b].find(s)!=DP[a][b].end())
		return DP[a][b][s];
	long long &res=DP[a][b][s];
	res=0;
	if (s.t==s.b)
	{
		T tmp=s;
		long long use=min (s.nt,s.nb);
		if(s.nt-use==0)
//		if (use==s.nt)
		{
			if(a+1<n)
			{
			tmp.nt=Tn[a+1];
			tmp.t=Tt[a+1];
			tmp.nb-=use;
			res=max(res,go(tmp,a+1,b)+use);
			}
			else
				res=max(res,use);
		}
		if (s.nb-use==0)
		//else
		{
			tmp=s;
			if (b+1<m)
			{
			tmp.nb=Bn[b+1];
			tmp.b=Bt[b+1];
			tmp.nt-=use;
			res=max(res,go(tmp,a,b+1)+use);
			}
			else
				res=max(res,use);
		}
		
	}
	
	
	if (a+1<n)
	{
	T tmp=s;
	tmp.nt=Tn[a+1];
	tmp.t=Tt[a+1];
	res=max(res,go(tmp,a+1,b));
	}
	if (b+1<m)
	{
	T tmp=s;
	tmp.nb=Bn[b+1];
	tmp.b=Bt[b+1];
	res=max(res,go(tmp,a,b+1));
	}
	return res;
}

//long long DP[a][b];
//long long go (int a,int b)
//{
//	if (a==n||b==m)
//	{
//		return 0;
//	}
//	long long res=0;
//	long long rem=T[a].c;
//	long long t=0;
//	while (rem>0&&b<m)
//	{
//		if (B[b].type==T[a].type)
//		{
//			long long use=min (rem,T[a].c);
//			t+=use;
//			res=max (res,t+go(a+1,b))
//		}
//		b++;
//	}
//}
int main ()
{
	int c,k;

	scanf ("%d",&c);

	FOR(cas,1,c)
	{

		memset(Type,0,sizeof Type);
		scanf("%d%d",&n,&m);
		REP(i,n)
		{
			scanf("%lld%d",&Tn[i],&Tt[i]);
			Type[Tt[i]]++;
		}
		int h=0;
		REP(i,m)
		{
			scanf("%lld%d",&Bn[h],&Bt[h]);
			if (Type[Bt[i]])
			{
				if(h&&Bt[h]==Bt[h-1])
				{
					Bn[h-1]+=Bn[h];
				}
				else
				h++;
			}
		}
		REP(i,3)
			REP(j,100)
				DP[i][j].clear();
		T s;
		s.nt=Tn[0];
		s.nb=Bn[0];
		
		s.t=Tt[0];
		s.b=Bt[0];
		m=h;
		DEB(m);
		long long res=go(s,0,0);
		printf ("Case #%d: %lld",cas,res);

		printf ("\n");
		DEB(cas);
	}
	return 0;
}

