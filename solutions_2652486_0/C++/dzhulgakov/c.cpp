#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-small-1-attempt0"
int r,n,m,k;
int prod;
vector<string> a;
vector<int> w;
vector<vector<double>> b;
map<string,int> mapping;

void rec(string s)
{
	if (SZ(s) == n)
	{
		sort(ALL(s));
		if (!mapping.count(s))
		{
			a.pb(s);
			b.pb(vector<double>());
			w.pb(1);
			mapping[s] = SZ(a)-1;
			vector<double>& r = b.back();
			r.assign(prod+1,0);
			REP(mask,1<<n)
			{
				int x = 1;
				REP(i,mask) if (mask&(1<<i)) x *= s[i]-'0';
				r[x]+=1.0/(1<<m);
			}
		}
		else
			w[mapping[s]]++;
		return;
	}
	FOR(x,2,m)
	{
		rec(s + string(1,'0'+x));
	}
}
	
int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	scanf("%d%d%d%d",&r,&n,&m,&k);
	prod = 1;
	REP(i,n) prod*=m;
	rec("");

	printf("Case #1:\n");
	REP(step,r)
	{
		int obs[25];
		REP(i,k) scanf("%d",obs+i);
		double best = -1.0;
		string ans = "";
		REP(i,SZ(a))
		{
			double cur = w[i];
			REP(j,k)
				cur *= b[i][obs[j]];
			if (cur > best)
			{
				best = cur;
				ans = a[i];
			}
		}
		printf("%s\n",ans.data());
	}
	return 0;
}