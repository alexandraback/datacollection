#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, R, N, M, K;
int a[7], res[3];

bool test(int n) {
    for (int i = 0; i < K; ++i) {
        if (a[i] % n == 0) {
            return true;
        }
    }
    return false;
}

void gao() {
    //bool f2 = test(2);
    bool f3 = test(3);
    bool f4 = test(4);
    bool f5 = test(5);
    //bool f8 = test(8);
    bool f9 = test(9);
    bool f25 = test(25);
    bool f27 = test(27);
    bool f125 = test(125);
    int count = 0;
    //printf("%d %d %d %d %d %d %d %d %d\n", f2, f4, f8, f3, f9, f27, f5, f25, f125);
    if (f27) {
        res[count++] = 3;
        res[count++] = 3;
        res[count++] = 3;
    } else if (f9) {
        res[count++] = 3;
        res[count++] = 3;
    } else if (f3) {
        res[count++] = 3;
    }
    if (f125) {
        res[count++] = 5;
        res[count++] = 5;
        res[count++] = 5;
    } else if (f25) {
        res[count++] = 5;
        res[count++] = 5;
    } else if (f5) {
        res[count++] = 5;
    }
    if (f4) {
        res[count++] = 4;
    }
    while (count < N) {
        res[count++] = 2;
    }
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        printf("Case #%d:\n", caseNum);
        scanf("%d%d%d%d", &R, &N, &M, &K);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < K; ++j) {
                scanf("%d", &a[j]);
            }
            gao();
            for (int j = 0; j < N; ++j) {
                printf("%d", res[j]);
            }
            puts("");
        }
    }
    return 0;
}
