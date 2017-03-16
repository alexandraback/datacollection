#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
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
#include <cstring>
#include <ctime>

using namespace std;

bool check(long long r, long long t, long long k) {
    long double tmp = (long double)(2 * r + 2 * k - 1) * k;
    if (tmp > 9e18) return false;
    return (2 * r + 2 * k - 1) * k <= t;
}

void work() {
    long long r, t;
    scanf("%lld%lld", &r, &t);
    long long head = 1;
    long long tail = 2000000000LL;
    while (head <= tail) {
        long long mid = (head + tail) / 2;
        if (check(r, t, mid)) head = mid + 1; else tail = mid - 1;
    }
    printf("%lld\n", head - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test ++) {
        printf("Case #%d: ", test + 1);
        work();
    }

    return 0;
}