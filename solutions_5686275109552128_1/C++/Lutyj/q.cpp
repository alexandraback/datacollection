#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXD = 1000;

int D, P[MAXD];

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t + 1);

        scanf("%d", &D);
        for (int i = 0; i < D; ++i) scanf("%d", &P[i]);

        int maxP = *max_element(P, P + D);
        int answer = -1;

        for (int L = 1; L <= maxP; ++L) {
            int res1 = 0, res2 = 0;

            for (int i = 0; i < D; ++i) {
                if (P[i] > L) res1 = L; else res1 = max(res1, P[i]);
                res2 += (P[i] - 1) / L;
            }

            if (answer == -1 || (res1 + res2 < answer)) answer = res1 + res2;
        }

        printf("%d\n", answer);
    }

    return 0;
}
