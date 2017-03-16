#include <bits/stdc++.h>

using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
//#define fout cout
//#define fin cin
int main()
{
	ifstream fin("input.in");
	ofstream fout("output.out");
	int test;
	fin>>test;
	FOR(t,1,test+1)
	{
		fout<<"Case #"<<t<<": ";
		double r,c,w;
		fin>>r>>c>>w;
		int ans=floor(c/w);
		ans=(((int)(r))-1)*ans;
		ans+=ceil(c/w);
		ans+=w-1;

		fout<<ans<<endl;
	}
	return 0;
}


