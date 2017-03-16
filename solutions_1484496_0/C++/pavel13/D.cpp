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
vector<int> S;
int r[12222];
int res;
vector<vector<int> > V[1000000];
bool  go (int n,int s)
{
	res=-1;
	REP(i,1<<n)
	{
		int s=0;
		vector<int> g;
		REP(j,n)
		{
			if (i&(1<<j))
			{
				s+=r[j];
				g.PB(r[j]);;
			}
		}
		V[s].PB(g);
		if (SZ(V[s])>=2)
		{
			res=s;

			return true;
		}
	}
	return false;
}

int main ()
{
	int c,n,k;

	scanf ("%d",&c);
	FOR(cas,1,c)
	{


	
		scanf("%d",&n);
		REP(i,n)
		{
			scanf ("%d",&r[i]);
		}
		REP(i,1000000)
			V[i].clear();
		res=-1;
		go(n-1,0);

		printf ("Case #%d: ",cas);
		
		if(res==-1)
			printf ("Impossible\n");
		else
		{
			printf ("\n");
			REP(i,2)
			{
				REP(j,SZ(V[res][i]))
				{
					
					printf ("%d",V[res][i][j]);
					if (j<SZ(V[res][i])-1)
						printf (" ");
				}
				printf ("\n");
			}
//			printf ("\n");
		}

	}
	return 0;
}

