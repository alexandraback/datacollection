#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool isok(ll x) {
	int A[20];
	int k=0;
	for(; x; k++) {
		A[k] = x % 10;
		x /= 10;
	}
	rep(i, k) if (A[i] != A[k-i-1]) return false;
	return true;
}
ll solve() {
	ll A, B;
	cin >> A >> B;
	ll ans = 0;
	for(ll x=sqrt(A); x*x<=B; x++) {
		if (x*x<A) continue;
		if (isok(x) && isok(x*x)) ans++;
	}
	return ans;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
}

