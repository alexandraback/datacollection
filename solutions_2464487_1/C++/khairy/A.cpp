#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define M 1001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	freopen("test.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int T;
	scanf ("%d", &T);
	FOR (cs, 1 , T + 1) {
		ll t, r;
		scanf ("%lld%lld", &r, &t);
		ll st = 0, end = (ll)1e18 + 1, mid, res;
		while (st <= end) {
			mid = st + (end - st) / 2;
			if ((2 * mid + 2 * r + 1) <= t / (mid + 1))
				res = mid, st = mid + 1;
			else
				end = mid - 1;
		}
		printf ("Case #%d: %lld\n", cs, res + 1);
	}
	return 0;
}
