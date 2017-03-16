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

#define PROBLEM_NUM "a"
#define ATTEMPT "1"

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

double s[1000];
double ans[1000];

void solve(int num) {
    printf("Case #%d:", num);
    int n;
    scanf("%d", &n);
    double x = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &s[i]);
        x += s[i];
    }
    for (int i = 0; i < n; ++i) 
        s[i] /= x;
    for (int i = 0; i < n; ++i) {
        double left = 0, right = 1;
        for (int k = 0; k < 100; ++k) {
            double m = (left + right) / 2;
            double sum = 0;
            for (int j = 0; j < n; ++j)
                sum += std::max(0., m + s[i] - s[j]);
            if (sum >= 1)
                right = m;
            else
                left = m;
        }
        printf(" %lf", right * 100);
    }
    printf("\n");
}

int main() {
    freopen(PATH "in", "r", stdin);
    freopen(PATH "out", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) 
        solve(i + 1);
}
