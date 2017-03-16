#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, N;

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        int n1, n2;
        int start1, start2;
        int period1, period2;
        if (N == 1) {
            scanf("%d %d %d", &start1, &n1, &period1);
            start2 = start1;
            period2 = period1 + 1;
        } else if (N == 2) {
            scanf("%d %d %d %d %d %d", &start1, &n1, &period1, &start2, &n2, &period2);
        }

        // is the answer 1?
        // if faster starts ahead of slow, it's whether the faster laps slow before slow reaches 0
        // if faster starts behind slow, it's whether the faster reaches 0 and then laps slow again before slow reaches 0
        // it's just whether faster reaches 0 for the second time before slower reaches 0
        // first, we make 1 the faster one
        if (period1 > period2) {
            int temp = start1;
            start1 = start2;
            start2 = temp;

            temp = period1;
            period1 = period2;
            period2 = temp;
        }

        double reach1 = period1 * (double) (360 - start1) / 360.0 + period1;
        double reach2 = period2 * (double) (360 - start2) / 360.0;
        int answer;
        if (reach1 <= reach2) {
            answer = 1;
        } else {
            answer = 0;
        }

        printf("Case #%d: %d\n", t, answer);
    }

    return 0;
}
