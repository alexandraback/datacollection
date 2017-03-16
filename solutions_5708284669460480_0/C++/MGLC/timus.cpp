#include <cstdio>

const int MAX_K = 100;
const int MAX_L = 100;
const int MAX_S = 100;

int T;
int K, L, S;
char keys[MAX_K + 1];
char target[MAX_L + 1];
char generated[MAX_S + 1];

double answer;

bool isPossible() {
    int i, j;
    bool answer = true;
    for (i = 0; i < L; ++i) {
        bool ok = false;
        for (j = 0; j < K; ++j) {
            if (target[i] == keys[j]) {
                ok = true;
            }
        }
        answer &= ok;
    }
    return answer;
}

int main(void) {
    int t;
    int i, j, k;

    // citirea datelor
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s", keys);
        scanf("%s", target);

        // calcularea solutiei
        int bestCase;
        long long possibilities = 1;
        long long occurences = 0;
        for (i = 0; i < S; ++i) {
            possibilities *= K;
        }
        generated[S] = 0;
        for (i = 0; i < possibilities; ++i) {
            int current = i;
            for (j = 0; j < S; ++j) {
                generated[j] = keys[current % K];
                current /= K;
            }
            //printf("%s\n", generated);
            for (j = 0; j + L - 1 < S; ++j) {
                k = 0;
                while (k < L && target[k] == generated[j + k]) {
                    ++k;
                }
                if (k == L) {
                    occurences++;
                }
            }
        }
        double expected = (double)occurences / possibilities;
        for (i = 1; i < L; ++i) {
            j = 0;
            while (i + j < L && target[j] == target[i + j]) {
                ++j;
            }
            if (i + j == L) {
                break;
            }
        }
        if (isPossible()) {
            bestCase = 1 + (S - L) / i;
        } else {
            bestCase = 0;
        }
        //printf("bestCase = %d\n", bestCase);
        answer = bestCase - expected;

        // afisarea solutiei
        printf("Case #%d: %.8lf\n", t, answer);
    }
    return 0;
}
