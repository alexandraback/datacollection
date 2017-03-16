#include <cstdio>

const int MAX_D = 100;

int T;
long long C, D, V;
long long den[MAX_D + 1];

long long answer;

int main(void) {
    int t;
    int i;

    // citirea datelor
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%lld %lld %lld", &C, &D, &V);
        for (i = 0; i < D; ++i) {
            scanf("%lld", &den[i]);
        }

        // calcularea solutiei
        den[D++] = V + 1;
        answer = 0;
        long long min = 1;
        i = 0;
        while (min <= V) {
            while (i < D && den[i] <= min) {
                min += den[i] * C;
                ++i;
            }
            if (min <= V && i < D && den[i] > min) {
                answer++;
                min += min * C;
            }
        }

        // afisarea solutiei
        printf("Case #%d: %lld\n", t, answer);
    }
    return 0;
}
