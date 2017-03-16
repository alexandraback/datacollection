#include <iostream>
#include "solution.hpp"

using namespace std;

int main() {
  //  freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt4.in", "r", stdin);
 //   freopen("data.in", "r", stdin);
    Solution sol;
    int T;
    int D;
    int p[1024];
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &D);
        for(int i = 0; i < D; i++) {
            int a;
            scanf("%d", &a);
            p[i] = a;
        }
        printf("Case #%d: %d\n", i, sol.solve(D, p));
    }
    return 0;
}
