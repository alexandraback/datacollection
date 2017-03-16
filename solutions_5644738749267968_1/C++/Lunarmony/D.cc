#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int n, y, z;
double wMy[1001], wOther[1001];

void solve() {
    sort(wMy, wMy + n);
    sort(wOther, wOther + n);
    y = 0;
    for (int i = 0, oFront = 0; i < n; ++i)
        if (wMy[i] > wOther[oFront]) {
            ++y;
            ++oFront;
        }
    z = 0;
    int oLeft = 0, oRight = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (wMy[i] > wOther[oRight]) {
            ++z;
            ++oLeft;
        } else
            --oRight;
    }
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 0; caseNo < numCases; ++caseNo) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lf", &wMy[i]);
        for (int i = 0; i < n; ++i)
            scanf("%lf", &wOther[i]);
        solve();
        printf("Case #%d: %d %d\n", caseNo + 1, y, z);
    }
    return 0;
}


