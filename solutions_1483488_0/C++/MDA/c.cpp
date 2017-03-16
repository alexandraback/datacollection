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

#define PROBLEM_NUM "C"
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

int next(int n, int p) { return (n % p) * 10 + n / p; }

int normalize(int n) {
    int p = 1;
    while (p * 10 <= n)
        p *= 10;
    int max = n;
    for (int t = next(n, p); t != n; t = next(t, p))
        max = std::max(max, t);
    return max;
}

void solve(int num) {
    printf("Case #%d: ", num);
    int n, m;
    scanf("%d%d", &n, &m);
    long long res = 0;
    std::map< int, int > count;
    for (int i = n; i <= m; ++i) {
        int j = normalize(i);
        res += count[j]++;
    }
    std::cout << res << "\n";
}

int main() {
    freopen(PATH "in", "r", stdin);
    freopen(PATH "out", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) 
        solve(i + 1);
}
