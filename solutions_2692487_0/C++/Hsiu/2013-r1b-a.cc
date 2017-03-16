#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int T, cases;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        int A, N;
        int mote[2000000];
        scanf("%d %d", &A, &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &mote[i]);
        }
        sort(mote, mote+N);
        int ind;
        for (ind = 0; ind < N; ind++) {
            if (A <= mote[ind])
                break;
            A += mote[ind];
        }
        int ans = N-ind;
        int add = 0;
        int need = 0;
        if (A == 1) {
            ans = N;
            N = 0;
        }
        for (int cut = ind; cut < N; cut++) {
            //printf("ans = %d, cut = %d, A = %d, add = %d\n", ans, cut, A, add);
            while (A <= mote[cut]) {
                A = 2*A - 1;
                add += 1;
            }
            //printf("cut = %d, A = %d, add = %d\n", cut, A, add);
            A += mote[cut];
            if (add + N-cut-1 < ans)
                ans = add + N-cut-1;
        }
        printf("Case #%d: %d\n", cases, ans);
    }
}
