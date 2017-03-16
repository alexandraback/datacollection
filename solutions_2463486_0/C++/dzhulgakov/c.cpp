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

#define FN "C-small-attempt0"

bool ispal(LL x) {
	if (x<=0) return false;
	char buf[25];
	sprintf(buf,"%lld",x);
	int n = strlen(buf);
	REP(i,n)
		if (buf[i]!=buf[n-1-i])
			return false;
	return true;
}

vector<LL> ps;
void gen_pal_stupid(int mx) {
	FOR(i,1,mx)
		if (ispal(i))
			ps.pb(i);
}

vector<LL> a;
void gen_pal(int len) {
	int k = (len+1)/2;
	LL pw10 = 1;
	REP(i,k) pw10*=10;
	for (LL t = pw10/10; t < pw10; t++)
	{
		LL q = t, x = t;
		if (len%2) q/=10;
		REP(step,len-k) {
			x = x*10+q%10;
			q/=10;
		}
		a.pb(x);
	}
}

vector<LL> b;

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	//gen_pal_stupid(100000);
	FOR(len,1,7) gen_pal(len);
	SORT(a);
	REP(i,SZ(a))
	{
		LL t= a[i]*a[i];
		if (ispal(t))
			b.pb(t);
	}
	SORT(b);
	//cerr << (a==ps) << endl;

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		printf("Case #%d: ",test);
		LL x,y;
		scanf("%lld%lld",&x,&y);
		int xx = lower_bound(ALL(b),x)-b.begin();
		int yy = lower_bound(ALL(b),y+1)-b.begin();
		printf("%d\n",yy-xx);
	}
	return 0;
}