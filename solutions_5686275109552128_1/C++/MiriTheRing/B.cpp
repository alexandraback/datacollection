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
#include <iomanip>
#include <cassert>
#include <unordered_set> // C++11
#include <unordered_map> // C++11
#include <tuple>         // C++11
#include <bitset>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
 
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }
 
#define N (1024)
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin >> TC;
  FOR(tc, 1, TC+1){
	int n;
	cin >> n;
	vi p(1001, 0);
	int maximum = 0;
	FOR(i,0,n){
		int k;
		cin >> k;
		p[k]++;
		maximum = max(maximum, k);
	}
	ll res = maximum;
	FOR(to, 1, maximum+1){
		vector<ll> newp(all(p));
		ll time = 0;
		FORD(i,to+1, maximum+1){
			time += newp[i];
			newp[i-to] += newp[i];
			newp[to] += newp[i];
		}
		ll add = 0;
		FOR(i,1,to+1){
			if(newp[i])
				add = i;
		}
		res = min(res, time + add);
	}
	cout << "Case #" << tc << ": " << res << endl;
  }
}
