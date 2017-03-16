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

const int kMaxN = 10001;

long long E, R, N;
long long v[kMaxN];
long long kG[kMaxN];

long long solve() {
    long long ans = 0;
    kG[0] = E; fill(kG + 1, kG + N, min(E, R));
    queue<pair<int, int> > rangeQ;
    rangeQ.push(make_pair(0, N - 1));
    for (int iter = 1; iter <= N; ++iter) {
        assert(!rangeQ.empty());
        pair<int, int> cRange = rangeQ.front(); rangeQ.pop();
        int l = cRange.first, r = cRange.second; // [l, r]
        int maxPos = l;
        for (int j = l + 1; j <= r; ++j)
            if (v[j] > v[maxPos]) {
                maxPos = j;
            }
        long long maxPosE = 0;
        for (int j = l; j <= maxPos; ++j) {
            maxPosE += kG[j];
        }
        maxPosE = min(maxPosE, E);
        ans += maxPosE * v[maxPos];
        for (int j = maxPos; j >= l; --j) {
            long long x = min(kG[j], maxPosE);
            kG[j] -= x;
            maxPosE -= x;
            if (maxPosE == 0)
                break;
        }
        assert(maxPosE == 0);
        if (l < maxPos) {
            rangeQ.push(make_pair(l, maxPos - 1));
        }
        if (maxPos < r) {
            rangeQ.push(make_pair(maxPos + 1, r));
        }
    }
    assert(rangeQ.empty());
    return ans;
}

long long solve2() {
    long long f[kMaxN][6];
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= 5; ++j)
            f[i][j] = -1;
    f[0][E] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= E; ++j) {
            if (f[i][j] >= 0) {
                for (int k = 0; k <= j; ++k) {
                    f[i + 1][min(E, j - k + R)] = max(f[i + 1][min(E, j - k + R)], f[i][j] + k * v[i]);
                }
            }
        }
    long long ans = 0;
    for (int j = 0; j <= E; ++j)
        ans = max(ans, f[N][j]);
    return ans;
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 1; caseNo <= numCases; ++caseNo) {
        scanf("%lld %lld %lld", &E, &R, &N);
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &v[i]);
        }
        printf("Case #%d: %lld\n", caseNo, solve2());
    }
    return 0;
}
