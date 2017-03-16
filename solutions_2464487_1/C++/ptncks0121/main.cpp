#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef unsigned long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

void precalc();

const int N_ = 100;
const double PI = acos(-1);

int TC, TCC;
ll R, T;

ll sq (ll v) { return v * v; }
ll Paint (ll black) {
	ll ret = 2 * black * (R + 2) + 1;
	return ret;
}

int main() {
    freopen("input.txt", "r", stdin);

    int i, j, k;

    precalc();
    freopen("output.txt", "w", stdout);


    scanf("%d", &TC);
    while(++TCC <= TC) {
        printf("Case #%d: ", TCC);

		scanf("%lld%lld", &R, &T);

		ll left = 0, right = (ll)(1e18 / T + 1), ret = 0;
		while(left <= right) {
			ll mid = (left + right) >> 1;
			ll value = Paint (mid);
			if(value <= T) ret = mid, left = mid + 1;
			else right = mid - 1;
		}

		printf("%lld\n" ,ret);
    }
    return 0;
}

void precalc() {
}
