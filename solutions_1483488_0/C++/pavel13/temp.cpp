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
set<pair<int,int> > S;
int move(int n,int a,int b)
{

	sprintf (P,"%d",n);
	
	string h=P;
	string ori=h;
	REP(i,SZ(h)-1)
	{
		h=h.substr(1)+h.substr(0,1);
//		DEB(h);
		if (h[0]!='0')
		{
			int q;
			sscanf(h.c_str(),"%d",&q);
			if(q>=a&&q<=b&&q!=n)
			if(q>n)
				S.insert(make_pair(n,q));
			else
					S.insert(make_pair(q,n));
		}
	}
	
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

		S.clear();
		FOR(i,a,b)
		{
			move(i,a,b);
			
		}
		printf ("Case #%d: %d",cas,SZ(S));

		printf ("\n");
	}
	return 0;
}

