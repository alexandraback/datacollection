#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;

const int maxn = 100000 + 10;

double wrong[maxn], correct[maxn];

void main2() {
    int A, B;
    scanf("%d%d", &A, &B);
    for (int i = 1; i <= A; ++i) {
        scanf("%lf", &correct[i]);
    }
    wrong[0] = 1.0;
    for (int i = 1; i <= A; ++i) {
        wrong[i] = wrong[i - 1] * correct[i];
    }
    for (int i = 0; i <= A; ++i) {
        wrong[i] = 1.0 - wrong[i];
    }
    double ans = 1E100;
    for (int i = 0; i <= A; ++i) {
        ans = min(ans, wrong[A - i] * (i + B - (A - i) + 1 + B + 1)
                     + (1.0 - wrong[A - i]) * (i + B - (A - i) + 1));
    }
    ans = min(ans, B + 2.0);

    printf("%.10f\n", ans);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int testCnt;
    scanf("%d", &testCnt);
    for (int caseId = 1; caseId <= testCnt; ++caseId) {
        printf("Case #%d: ", caseId);
        main2();
    }
}

