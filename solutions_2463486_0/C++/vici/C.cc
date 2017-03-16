#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int num[20];
bool isp(ll x) {
	int cnt = 0;
	while (x) {
		num[cnt++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < cnt; ++i) {
		if (num[i] != num[cnt - i - 1]) return false;
	}
	return true;
}
ll pl[100000]; int pnt;


int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T, ca = 1;
	ll a, b;
	for (ll i = 1; i <= 10000000; ++i) {
		if (isp(i) && isp(i * i)) pl[pnt++] = i * i;
	}
	for (scanf("%d", &T); T--; ) {
		scanf("%lld %lld", &a, &b);
		int ret = 0;
		for (int i = 0; i < pnt; ++i) {
			if (pl[i] >= a && pl[i] <= b) ++ret;
		}
		printf("Case #%d: %d\n", ca++, ret);
	}
    return 0;
}

