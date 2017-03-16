#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;

typedef unsigned int ui32;

const int INF = (int)1e+9;
const double EPS = (double)1e-9;

long long Gcd(long long a, long long b) {
    return (b == 0) ? a : Gcd(b, a % b);
}

bool Power2(long long b) {
    while (b % 2 == 0)
        b /= 2;
    return (b == 1);
}

int Solve(int testId) {
    long long P, Q;
    scanf("%lld/%lld", &P, &Q);
    long long gcd = Gcd(P, Q);
    P /= gcd;
    Q /= gcd;
    if (!Power2(Q))
        return -1;
    for (int step = 1; Q > 1; Q /= 2, ++step) {
        if (P*2 >= Q)
            return step;
    }
    assert(false);
}

int main() {
    int testCnt;
    cin >> testCnt;
    for (int testId = 1; testId <= testCnt; ++testId) {
        int res = Solve(testId);
        if (res != -1)
            printf("Case #%d: %d\n", testId, res);
        else
            printf("Case #%d: impossible\n", testId);
    }

    return 0;
}

