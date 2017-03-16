#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define FOREQ(i,a,b) for(int i = a; i <= (int)b; i++)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) (c).size()
template <class T> void pp(T v) { FOREACH(it, v) cout << *it << ' '; cout << endl ; }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef complex<double> P;
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
const int INF = 1<<28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
#undef MOD_CALC
#ifdef MOD_CALC
const ll MOD = 10000 * 10000 + 7 ;
inline void chadd(ll &a, const ll b) { a = (a + b) % MOD;}
inline ll add(const ll a, const ll b){ return (a + b) %  MOD;}
inline void chsub(ll &a, const ll b) { a = (a - b + MOD) % MOD;}
inline ll sub(const ll a, const ll b){ return (a - b + MOD) % MOD; }
inline void chmul(ll &a, const ll b) { a = (a * b) %  MOD;}
inline ll mul(const ll a, const ll b){ return (a * b) %  MOD;}
#endif
int N;
bool ans;
vector<set<int> > work;
vector<vint> parents, children;
void f(const int cur, const int par)
{
	if(work[cur].find(par) == work[cur].end()) {
		work[cur].insert(par);
		REP(j, children[cur].size()) {
			f(children[cur][j], par);
			if(ans == true) return ;
		}
	} else { // ‚·‚Å‚É‚ ‚é
		ans = true;
	}
}
void solve(void)
{
#ifdef DEBUG
	REP(i,N) {
		cout << i << "------" << endl;
		pp(parents[i]);
		pp(children[i]);
	}
#endif
	work = vector<set<int> > (N);
	REP(i,N) {
		REP(j, children[i].size()) {
			f(children[i][j], i);
			if(ans == true) return ;
		}
	}
}

int main(void)
{
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin>>N;
		parents = vector<vint> (N);
		children = vector<vint> (N);
		REP(i,N) {
			int n; cin>>n;
			REP(j,n) {
				int m; cin>>m; m--;
				parents[i].push_back(m);
				children[m].push_back(i);
			}
		}
		ans = false;
//		solve(parents, children);
		solve();
#ifdef DEBUG2
		REP(i,N) {cout << i << "->" ;pp(work[i]); }
#endif
		printf("Case #%d: %s", t, ans ? "Yes" : "No");
		puts("");

	}
    return 0;
}
