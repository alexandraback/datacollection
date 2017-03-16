#include <stdio.h>

int main() {
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i) {
        int N, S, p;
        scanf("%d %d %d", &N, &S, &p);
        int M = p * 3;
        int CountMSub4AndSub3 = 0;
        int CountBiggerThanMASub3 = 0;
        for (int j = 0; j < N; ++j) {
            int tj;
            scanf("%d", &tj);
            if (((M - 4 == tj) || (M - 3 == tj))&& tj != 0) {
                ++CountMSub4AndSub3;
            } else if (tj > M - 3) {
                ++CountBiggerThanMASub3;
            }
        }
        // Answer without Surprising
        int Ans = CountBiggerThanMASub3;
        if (S <= CountMSub4AndSub3) {
            Ans += S;
        } else {
            Ans += CountMSub4AndSub3;
        }
        printf("Case #%d: %d\n", i, Ans);
    }
    return 0;
}

