#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
typedef vector<string> VS;

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(),x.end()
#define CLR(x, v) memset((x),v,sizeof (x))
#define gcd(a, b) __gcd(a, b)
#define PB push_back 
#define MP make_pair
#define INF 0x3f3f3f3f

int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }
template<class T> inline std::ostream& operator<<(ostream& os, const vector<T>& v) { FORE(it,v) os << *it << " "; return os; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

//#define DEBUG
#ifdef DEBUG
#define ASSERT(x) assert(x)
#else
#define ASSERT(x)
#endif

// -
int E, R, n;
int v[10010];
int dp[15][10];
int valid[15][10];
// -

// input
void init()
{
	int i;
	cin>>E>>R>>n;
	FOR(i,0,n) cin>>v[i];
	CLR(dp,0);
	CLR(valid,0);
}



void solve()
{
	init();
	int i, j, k;
	valid[0][E] = 1;
	FOR(i,0,n) {
		FOR(j,0,E+1) if(valid[i][j]) {
			FOR(k,0,j+1) {
				int ne = j - k + R;
				if(ne > E) ne = E;
				chmax(dp[i+1][ne], dp[i][j]+v[i]*k);
				valid[i+1][ne] = 1;
			}
		}
	//	FOR(j,0,E+1) cout<<i+1<<" "<<j<<" "<<dp[i+1][j]<<endl;
	}
	int ans = 0;
	FOR(i,0,E+1) chmax(ans, dp[n][i]);
	cout << ans << endl;
}

int main()
{
	int T;
	cin>>T;
	for(int cs = 1; cs <= T; cs++) {
		cout << "Case #" << cs << ": ";
		clock_t start, finish;
		start = clock();   
		solve();
		finish = clock();   
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;  
#ifdef DEBUG 
		cout << "Running time: " << duration << endl;
#endif
	}
	return 0;
}
