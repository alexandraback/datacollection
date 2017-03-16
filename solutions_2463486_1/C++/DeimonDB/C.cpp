#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

const ll MAXX = 100000000000000LL;
vector<ll> solutions;
inline void solve(int tc) {
	ll A, B;
	scanf("%lld %lld", &A, &B);
	ll ans = upper_bound(solutions.begin(), solutions.end(), B) - lower_bound(solutions.begin(), solutions.end(), A);
	printf("Case #%d: %lld\n", tc, ans);
}

bool isPalindrome(ll x) {
	char lho[20];
	sprintf(lho, "%lld", x);
	int sz = strlen(lho);
	for (int i = 0; 2*i < sz; i++) if (lho[i] != lho[sz - i - 1]) return false;
	return true;
}
inline void init() {
	for (ll x = 1; x*x <= MAXX; x++) {
		if (isPalindrome(x*x) && isPalindrome(x)) solutions.PB(x*x);
	}
	//REP(i, SZ(solutions)) printf("%lld\n", solutions[i]);
	//printf("%d\n", SZ(solutions));
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	FOR(i, 1, T) solve(i);
	return 0;
}
