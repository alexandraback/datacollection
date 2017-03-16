#include <cstdio>
#include <cstdlib>
#include <cstring>
const int maxn = 110;
int t[maxn];
int T, N,S,P;

int main(){
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++) {
        int ret = 0, cnt = 0;
        scanf("%d%d%d", &N, &S, &P);
        for (int i = 0; i < N; i++) {
            scanf("%d", t + i);
        }
        for (int i = 0; i < N; i++) {
            if (P == 0) ret++;
            else if (P == 1) {
                 if (t[i] > 0) ret++;
            }
            else {
                 if (t[i] >= 3 * P - 2) ret++;
                 else if (t[i] >= 3 * P - 4) {
                      cnt++;
                      if (cnt <= S) ret++;
                 }
            }   
        }
        printf("Case #%d: %d\n", cas, ret);
    }
}
