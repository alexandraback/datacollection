#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fs first
#define sc second
#define sz(x) (int((x).size()))
#define all(x) ((x).begin()),((x).end())
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define fab(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fba(i,b,a) for(int (i)=(b);(i)>=(a);(i)--)
#define MAX(a,x) a=max(a,x)
#define MIN(a,x) a=min(a,x)

using namespace std;

const double eps = 1e-10, inf = 1e10;
typedef long long ll;

#define MAXN 110

int n, m;
pair<ll,int> a[MAXN], b[MAXN];
map< pair<ll,ll>, ll > dp[MAXN][MAXN];

ll best(int i, ll iused, int j, ll jused)
{
	if (i == n || j == m) return 0;
	if (dp[i][j].count(mp(iused, jused))) {
		//cerr << "cached\n";
		return dp[i][j][mp(iused, jused)];
	}
	
	ll idisp = a[i].fs - iused;
	ll jdisp = b[j].fs - jused;
	
	ll ret = 0;
	MAX(ret, best(i+1, 0, j, jused));
	MAX(ret, best(i, iused, j+1, 0));
	
	if (a[i].sc == b[j].sc) {
		if (idisp == jdisp) MAX(ret, idisp + best(i+1, 0, j+1, 0));
		else {
			ll mm = min(idisp, jdisp);
			if (idisp == mm) MAX(ret, mm + best(i+1, 0, j, /*jused +*/ mm));
			else MAX(ret, mm + best(i, /*iused +*/ mm, j+1, 0));
		}
	}
	
	return dp[i][j][mp(iused, jused)] = ret;
}

void solve(int test)
{
	cerr << "Case #" << test << "\n";
	printf("Case #%d: ", test);

	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%lld%d", &a[i].fs, &a[i].sc);
	rep(i, m) scanf("%lld%d", &b[i].fs, &b[i].sc);
	
	rep(i, n) rep(j, m) dp[i][j].clear();
	ll xx;
	printf("%lld\n", xx=best(0,0,0,0));
	//cerr << ": " << xx << "\n";
}

int main()
{	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d", &t);
	rep(i,t) solve(i+1);
	return 0;
}
