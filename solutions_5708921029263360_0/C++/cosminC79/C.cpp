#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int NMAX = 4;
bool mark[NMAX][NMAX][NMAX];
int cnt1[NMAX][NMAX], cnt2[NMAX][NMAX], cnt3[NMAX][NMAX];

struct suit {
    int i, j, k;
};

int tests, N, M, K, LM;
vector<suit> possib;

inline int getBits(int mask) {
    int result = 0;
    while (mask) {
        result++;
        mask = mask & (mask - 1);
    }

    return result;
}

inline bool valid(int mask) {
    bool ok = true;
    for (size_t i = 0; i < possib.size(); i++) {
        if (mask & (1 << i)) {
            cnt1[possib[i].i][possib[i].j]++;
            if (cnt1[possib[i].i][possib[i].j] > LM) {
                ok = false;
            }

            cnt2[possib[i].i][possib[i].k]++;
            if (cnt2[possib[i].i][possib[i].k] > LM) {
                ok = false;
            }

            cnt3[possib[i].j][possib[i].k]++;
            if (cnt3[possib[i].j][possib[i].k] > LM) {
                ok = false;
            }
        }

        
    }

    for (size_t i = 0; i < possib.size(); i++) {
        if (mask & (1 << i)) {
            cnt1[possib[i].i][possib[i].j]--;
            cnt2[possib[i].i][possib[i].k]--;
            cnt3[possib[i].j][possib[i].k]--;
        }
    }

    return ok;
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);

        scanf("%d%d%d%d", &N, &M, &K, &LM);
        if (N == 3 && M == 3 && K == 3 && LM >= 3) {
            printf("27\n");
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    for (int k = 1; k <= K; k++) {
                        printf("%d %d %d\n", i, j, k);
                    }
                }
            }
            continue ;
        }
        
        int best = 0, sol;
        possib.clear();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = 1; k <= K; k++) {
                    possib.push_back({i, j, k});
                }
            }
        }

        int n = possib.size(), nBits;
        for (int i = 0; i < (1 << n); i++) {
            nBits = getBits(i);
            if (nBits > best && valid(i)) {
                best = nBits;
                sol = i;
            }
        }

        printf("%d\n", best);
        for (int i = 0; i < n; i++) {
            if (sol & (1 << i)) {
                printf("%d %d %d\n", possib[i].i, possib[i].j, possib[i].k);
            }
        }
    }
    return 0;
}