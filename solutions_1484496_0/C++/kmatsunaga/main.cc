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
bool solve2(const vector<int> &masks, const vector<int> &data)
{
	int size = masks.size();
	REP(i,size) {
		REP(j,size) {
			if(i == j) continue;
			if(masks[i] & masks[j]) continue;
			REP(m, N) if(masks[i] & (1<<m)) {
				cout << data[m];
				cout << " ";
			}
			cout << endl;
			REP(m, N) if(masks[j] & (1<<m)) {
				cout << data[m];
				cout << " ";
			}
			cout << endl;
			return true;
		}
	}
	return false;
}
bool solve(const vector<int> &data)
{
	map<int, vector<int> > ans;
	for(int mask = 1; mask < (1<<N); mask++) {
		int one = 0;
		REP(i,N) {
			if(mask & (1<<i)) one += data[i];
		}
		ans[one].push_back(mask);
	}
	for(map<int, vector<int> >::iterator it = ans.begin();
			it != ans.end(); ++it) {
		if((it->second).size() >= 2) {
			bool ans = solve2(it->second, data);
			if(ans) return true;
		}
	}
	return false;
}

int main(void)
{
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		printf("Case #%d:", t);
		puts("");
		cin>>N;
		vector<int> data(N);
		REP(i,N) cin>>data[i];
		bool ans = solve(data);
		if(ans == false) cout << "Impossible" << endl;

	}
	return 0;
}
