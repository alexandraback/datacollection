#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXK = 22;

int T, R, N, M, K, prods[MAXK];

double freq[135];
double expected[135];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        // N numbers (digits <= M) = 3
        // M = max = 5 (2,3,4,5)
        // K = 7 products
        scanf("%d %d %d %d", &R, &N, &M, &K);
        printf("Case #%d:\n", t);

        for (int r = 0; r < R; r++) {
        for (int i = 1; i <= 125; i++) {
            freq[i] = 0.0;
        }

        for (int i = 1; i <= K; i++) {
            scanf("%d", &prods[i]);
            freq[prods[i]] += 1.0 / K;
        }

        double combos = 4.0 * 4.0 * 4.0;
        double best = 1.0e9;
        int aa, bb, cc;
        for (int a = 2; a <= 5; a++) {
            for (int b = 2; b <= 5; b++) {
                for (int c = 2; c <= 5; c++) {
                    for (int i = 1; i <= 125; i++) {
                        expected[i] = 0.0;
                    }
                    double x = 1.0 / 8.0;
                    expected[1] += x;
                    expected[a] += x;
                    expected[b] += x;
                    expected[c] += x;
                    expected[a * b] += x;
                    expected[b * c] += x;
                    expected[a * c] += x;
                    expected[a * b * c] += x;

                    double diff = 0.0;
                    for (int i = 1; i <= 125; i++) {
                        diff += (expected[i] - freq[i]) * (expected[i] - freq[i]);
                    }
                    if (diff < best) {
                        best = diff;
                        aa = a; bb = b; cc = c;
                    }
                }
            }
        }
        printf("%d%d%d\n", aa, bb, cc);
        }
    }

    return 0;
}
