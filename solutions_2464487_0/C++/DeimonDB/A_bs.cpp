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

#define ULL unsigned long long
#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())


ULL hoho(ULL r, ULL x) {
	return (x+1)*(2*r+1+2*x);
}
inline void solve(int tc) {
	ULL r, t;
	scanf("%llu %llu", &r, &t);
	ULL aw, ak;
	aw = 0; ak = (ULL)t;
	while(aw + 1 < ak) {
		//printf("%llu %llu\n", aw, ak);
		ULL mid = (aw+ak)/(ULL)2;
		//ULL tmp = hoho(r, mid);
		if ((mid+1) <= t / (2*r+1+2*mid))
			aw = mid;
		else
			ak = mid;
		//printf("%llu %llu\n--\n", aw, ak);
	}
	printf("Case #%d: %llu\n", tc, aw+1);
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
