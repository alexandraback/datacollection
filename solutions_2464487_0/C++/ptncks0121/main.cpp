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
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

void precalc();

const int N_ = 100;
const double PI = acos(-1);

int TC, TCC;
ll R, T;

ll sq (ll v) { return v * v; }
ll Paint (int black) {
	ll ret = 0;
	for(ll n = 0; n < black; n++) {
		ret += sq(R + n * 2 + 1) - sq(R + n * 2);
	}
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

		ll left = 0, right = (ll)1e4, ret = 0;
		while(left <= right) {
			ll mid = (left + right) >> 1;
			double value = Paint (mid);
			if(value <= T) ret = mid, left = mid + 1;
			else right = mid - 1;
		}

		printf("%lld\n" ,ret);
    }
    return 0;
}

void precalc() {
}
