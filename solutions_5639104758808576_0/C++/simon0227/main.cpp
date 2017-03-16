#include <iostream>
#include "solution.hpp"

using namespace std;

int main() {
    freopen("data.in", "r", stdin);
    Solution sol;
    int T;
    int smax;
    char s[1024];
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d %s", &smax, s);
        string p(s);
        printf("Case #%d: %d\n", i, sol.solve(smax, p));
    }
    return 0;
}
