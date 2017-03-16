#pragma comment(linker, "/STACK:16777216")
#pragma warning(default :4)
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <sstream>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
//#include <unordered_set>
//#include <unordered_map>
#include <cassert>
#include <iomanip>
#define mp make_pair
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x))
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]))
#define FIN freopen("in.txt", "r", stdin);
#define FINOUT freopen("in.txt", "w", stdout);
#define FOUT freopen("out.txt", "w", stdout);
#define y1 ____y1
using namespace std;
typedef const int CI;
typedef long long ll;
typedef unsigned long long ull;
//typedef __float128 ld;
//typedef long double ld;
typedef double ld;
typedef vector<int> VINT;
typedef vector<ld> VLD;
typedef vector<ll> VLL;
typedef vector<vector<int> > VVINT;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ld, ld> PDD;
typedef pair<ld, ld> ptp;
typedef complex<ld> Cn;
typedef vector<PII> VPII;
typedef unsigned int uint;
const ld eps = 1e-9;
//const int INF = 1000000001;
const int oo = 0x3F3F3F3F;
const ll ooLL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1000000007;
void deb() { std::cerr << '\n'; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T1> void deb(T1 x1) { std::cerr << x1 << '\n'; }
template<typename T1, typename T2> void deb(T1 x1, T2 x2) { std::cerr << x1 << " " << x2 << '\n'; }
template<typename T1, typename T2, typename T3> void deb(T1 x1, T2 x2, T3 x3) { std::cerr << x1 << " " << x2 << " " << x3 << '\n'; }
const ld PI=acos(-1.);
ll Round(double x) { return x<0 ? x-.5 : x+.5; }

int r, n, m, k;
int bu[14], se[1<<20][14], ss;
map<ll, double> pr[1<<17];
inline void go(int v, int g)
{
	if (v==m+1)
	{
		if (g==n)
		{
			REP(i, n) se[ss][i]=bu[i];
			++ss;
		}
		return;
	}
	while (g<=k)
	{
		go(v+1, g);
		bu[g]=v; ++g;
	}
}
void ass(int *s, map<ll, double> &m)
{
	m.clear();
	int mx=1<<n;
	double p=1./mx;
	REP(ms, mx)
	{
		ll w=1; REP(i, n) if (ms&(1<<i)) w*=s[i];
		m[w]+=p;
	}
}
double gp(const map<ll, double> &m, ll x)
{
	auto i=m.find(x);
	return i==m.end() ? 0 : i->second;
}
ll w[20];
int main()
{
	int tsts;
	scanf("%d", &tsts);
	REP(TST, tsts)
	{
		printf("Case #%d:\n", TST+1);
		scanf("%d %d %d %d", &r, &n, &m, &k);
		ss=0; go(2, 0);
		REP(i, ss) ass(se[i], pr[i]);
		REP(i, r)
		{
			REP(j, k) scanf("%lld", &w[j]);
			int mj=-1;
			double mx=0;
			REP(j, ss)
			{
				double p=1;
				REP(t, k) p*=gp(pr[j], w[t]);
				if (p>mx) mx=p, mj=j;
			}
			REP(j, n) printf("%d", se[mj][j]); puts("");
		}
	}
	return 0;
}
