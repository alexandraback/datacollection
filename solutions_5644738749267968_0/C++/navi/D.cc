#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
double a[1000], b[1000];

int gao1() {
    int ret = 0;
    for (int i = 0, j = 0; j < n; ++j) {
        for (; i < n && a[i] < b[j]; ++i);
        if (i < n) {
            ++ret;
            ++i;
        }
    }
    return ret;
}

int gao2() {
    int ret = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        for (; j < n && a[i] > b[j]; ++j);
        if (j < n) {
            ++ret;
            ++j;
        }
    }
    ret = n - ret;
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &b[i]);
        }
        sort(b, b + n);

        int res1 = gao1();
        int res2 = gao2();
        printf("Case #%d: %d %d\n", caseNum, res1, res2);
    }
    return 0;
}
