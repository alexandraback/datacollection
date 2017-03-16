#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int tests;
int K, C, S;

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);

    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d:", test);
        scanf("%d%d%d", &K, &C, &S);

        vector<long long> sol;
        int covered = 0;
        while (covered < K) {
            long long pos = covered + 1;
            for (int dim = 2; dim <= C; dim++) {
                pos = (pos - 1) * K;
                if (covered + dim <= K) {
                    pos += covered + dim;
                } else {
                    pos += covered + 1;
                }
            }

            sol.push_back(pos);
            covered += C;
        }

        if (sol.size() > S) {
            printf(" IMPOSSIBLE\n");
        } else {
            for (auto& x: sol) {
                printf(" %lld", x);
            }
            printf("\n");
        }
    }
    return 0;
}