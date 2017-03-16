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
	char P[123];
int pws[]={1,10,100,1000,10000,100000,1000000,10000000};
int moveINT(int n,int a,int b)
{
	int c=0;
	int w=n;
	int ds=0;
	set<int>S;
	while (w)
	{
		w/=10;
		ds++;
	}
	w=n;
//	DEB(ds);
	REP(i,ds)
	{
		w=w/pws[ds-1]+(w*10)%pws[ds];
//		DEB(w);
		int q=w;
		if (S.find(q)==S.end())
		{
			if(q>=a&&q<=b&&n<q)
			{
				c++;
				S.insert(q);
			}
		}
	}
//	DEB(c);
	return c;
}
int main ()
{
	int c,n,k;

	scanf ("%d",&c);
	FOR(cas,1,c)
	{
		int res=0;

		int a,b;
		scanf("%d%d",&a,&b);
		FOR(i,a,b)
		{
				int y=moveINT(i,a,b);
				res+=y;
		}
		
		printf ("Case #%d: %d",cas,res);

		printf ("\n");
	}
	return 0;
}

