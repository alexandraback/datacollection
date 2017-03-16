#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>

using namespace std;

long long r, t;

long long solve() {
    long long left = 1, right = t / (r + r + 1), ans = 0;
    while (left <= right) {
        long long mid = (left + right) >> 1;
        double cost = (double)mid * (r + r + 1.0) + 2.0 * ((double)mid - 1.0) * mid;
        bool possible = cost < 1.0 * t + 1e-12;
        if (possible) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    while (true) {
        long long t1 = (ans + 1) * (r + r + 1) + 2 * (ans + 1) * ans;
        if (t1 <= t)
            ++ans;
        else
            break;
    }
    while (true) {
        long long t0 = ans * (r + r + 1) + 2 * (ans - 1) * ans;
        if (t0 <= t)
            break;
        else
            --ans;
    }
    long long t0 = ans * (r + r + 1) + 2 * (ans - 1) * ans;
    if (t0 > t) {
        cerr << t0 << " " << t << " r=" << r << " t=" << t << endl;
    }
    assert(t0 <= t);
    long long t1 = (ans + 1) * (r + r + 1) + 2 * (ans + 1) * ans;
    if (t1 <= t) {
        cerr << t1 << " " << t << " r=" << r << " t=" << t << endl;
    }
    assert(t1 > t);
    return ans;
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 1; caseNo <= numCases; ++caseNo) {
        scanf("%lld %lld", &r, &t);
        printf("Case #%d: %lld\n", caseNo, solve());
    }
    return 0;
}
