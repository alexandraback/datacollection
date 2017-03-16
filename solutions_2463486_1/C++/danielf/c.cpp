#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))

#define MSET(c, v) memset(c, v, sizeof(c))

#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vector<ll> pal;

char temp[200];

ll makepal1(ll i) {
	sprintf(temp, "%lld", i);
	int l = strlen(temp);
	fu(j, l) temp[2*l-j-1] = temp[j];
	temp[2*l] = '\0';
	ll ans;
	sscanf(temp, "%lld", &ans);
	return ans;
}

ll makepal2(ll i) {
	sprintf(temp, "%lld", i);
	int l = strlen(temp);
	fu(j, l-1) temp[2*l-j-2] = temp[j];
	temp[2*l-1] = '\0';
	ll ans;
	sscanf(temp, "%lld", &ans);
	return ans;
}

bool ispal(ll x) {
	sprintf(temp, "%lld", x);
	int l = strlen(temp);
	fu(i, l) if (temp[i] != temp[l-i-1]) return false;
	return true;
}

void prepare() {
	fu(i, 10000) {
		ll number = makepal1(i);
		number *= number;
		if (number <= 100000000000000ll && ispal(number)) pal.pb(number);
		number = makepal2(i);
		number *= number;
		if (number <= 100000000000000ll && ispal(number)) pal.pb(number);
	}
	sort(all(pal));
	pal.erase(unique(all(pal)), pal.end());
}

int main() {
	prepare();
	int T;
	scanf("%d", &T);
	fu(t, T) {
		printf("Case #%d: ", t+1);
		ll A,B;
		scanf("%lld %lld", &A, &B);
		int ans = upper_bound(all(pal), B) - upper_bound(all(pal), A-1);
		printf("%d\n", ans);
	}
	return 0;
}

