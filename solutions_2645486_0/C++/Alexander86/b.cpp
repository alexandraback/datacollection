
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int dp[20][20];
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		int E, R, N;
		cin >> E >> R >> N;
		memset(dp,0,sizeof(dp));
		FOR(i,0,N){
			int v;
			cin >> v;
			FOR(e,0,E+1){
				FOR(t,0,e+1){
					dp[i+1][min(E,e-t+R)] = max(dp[i][e] + t * v, dp[i+1][min(E,e-t+R)]);
				}
			}
		}
		int res = 0;
		FOR(i,0,E+1)res = max(res, dp[N][i]);
		cout << "Case #" << tcc << ": " << res << endl;
	}
	return 0;
}
