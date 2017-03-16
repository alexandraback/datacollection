#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>

#define PROBLEM_NUM "c"
#define ATTEMPT "0"

#if 1
#   define SIZE "small"
#else
#   define SIZE "large"
#endif

#if 1
#   define PATH PROBLEM_NUM "."
#else
#   define PATH "C:/Downloads/" PROBLEM_NUM "-" SIZE "-attempt" ATTEMPT "."
#endif

int p[500];
int isum[5000000];

void solve(int num) {
    memset(isum, -1, sizeof(isum));
    printf("Case #%d:\n", num);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    bool ok = false;
    for (int i = 0; i < (1<<n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) if (i & (1 << j))
            sum += p[j];
        if (isum[sum] != -1) {
            for (int j = 0; j < n; ++j) if (i & (1 << j))
                printf("%d ", p[j]);
            printf("\n");
            for (int j = 0; j < n; ++j) if (isum[sum] & (1 << j))
                printf("%d ", p[j]);
            printf("\n");
            ok = true;
            break;
        }
        isum[sum] = i;
    }
    if (!ok)
        puts("Impossible");
}

int main() {
    freopen(PATH "in", "r", stdin);
    freopen(PATH "out", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) 
        solve(i + 1);
}
