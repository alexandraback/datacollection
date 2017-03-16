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

int main(void)
{
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int N; cin>>N;
		vector<int> data(N);
		vector<double> ans(N);
		int max_v = 0, sum = 0;
		REP(i,N) {
			cin>>data[i];
			sum += data[i];
			chmax(max_v, data[i]);
		}
		int all = sum;
		REP(i,N) sum -= (max_v - data[i]);
		//cout << sum << endl;
		double ave = (double) sum / N;
		//cout << "Average = " << ave << endl;
		int plus = 0, minus = 0;
		double minus_sum = 0.0;
		REP(i,N) {
			ans[i] = (ave + (max_v - data[i])) / (double)all * 100.0;
			if(ans[i] < 0) { minus++; minus_sum += ans[i]; }
			else plus++;
		}
		REP(i,N) {
			if(ans[i] < 0) ans[i] = 0.0;
			else ans[i] += minus_sum / plus;
		}

		printf("Case #%d:", t);
		REP(i,N)		printf(" %0.6f", ans[i]);
		puts("");

	}
    return 0;
}
