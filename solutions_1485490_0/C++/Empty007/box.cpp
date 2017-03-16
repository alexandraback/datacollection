#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

#define MAX 1005

typedef long long ll;

ll dp[4][105][500][500];
ll a[105], A[105], b[105], B[105];
map <ll, int> mapa;
int N, M, cnt;
ll rev[100000];

ll go(int n, int m, int mn, int mm) {
	if (n == N || m == M) return 0;
	//dbg4(n, m, mn, mm);
	ll &res = dp[n][m][mn][mm];
	if (res != -1) return res;
	res = 0;
	if (A[n] == B[m]) {
		ll val1 = rev[mn];
		ll val2 = rev[mm];
		//dbg2(val1, val2);
		ll add = min(val1, val2);
		res += add;
		if (add == val1) {
			if (!mapa.count(a[n+1])) {
				rev[cnt] = a[n+1];
				mapa[a[n+1]] = cnt++;
			}
			if (!mapa.count(val2-add)) {
				rev[cnt] = val2-add;
				mapa[val2-add] = cnt++;
			}
			res += go(n+1, m, mapa[a[n+1]], mapa[val2-add]);
		}
		else {
			if (!mapa.count(b[m+1])) {
				rev[cnt] = b[m+1];
				mapa[b[m+1]] = cnt++;
			}
			if (!mapa.count(val1-add)) {
				rev[cnt] = val1-add;
				mapa[val1-add] = cnt++;
			}
			res += go(n, m+1, mapa[val1-add], mapa[b[m+1]]);
		}
	}
	else {
		if (!mapa.count(a[n+1])) {
			rev[cnt] = a[n+1];
			mapa[a[n+1]] = cnt++;
		}
		if (!mapa.count(b[m+1])) {
			rev[cnt] = b[m+1];
		 	mapa[b[m+1]] = cnt++;
		 }
		ll as = go(n+1, m, mapa[a[n+1]], mm);
		ll bs = go(n, m+1, mn, mapa[b[m+1]]);
		res = max(as, bs);
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	REP(tc, T) {
		cnt = 0;
		CLR(a, 0);
		CLR(b, 0);
		CLR(dp, -1);
		cin >> N >> M;
		REP(i, N) {
			cin >> a[i] >> A[i];
		}
		REP(i, M) {
			cin >> b[i] >> B[i];
		}
		mapa = map<ll, int>();
		rev[cnt] = a[0];
		mapa[a[0]] = cnt++;
		rev[cnt] = b[0];
		mapa[b[0]] = cnt++;
		ll best = go(0, 0, 0, 1);
		printf("Case #%d: %lld\n", tc+1, best);
	}
}
