#include <cstdio>
#define MAX 103

bool cando(int a, int p) {
    if (p >= 1) return (a >= 3*p - 2);
    else return true;
}

bool candosurprise(int a, int p) {
    if (p >= 2) return (a >= 3*p - 4);
    else if (p == 1) return a >= 1;
    else return a >= 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt) {
        int N, S, p;
        int sol = 0;
        scanf("%d%d%d", &N, &S, &p);
        for (int i = 0; i < N; ++i) {
            int a; scanf("%d", &a);

            if (cando(a, p)) ++sol;
            else if (S && candosurprise(a, p)) ++sol, --S;
        }

        printf("Case #%d: %d\n", tt, sol);
    }
    return 0;
}
