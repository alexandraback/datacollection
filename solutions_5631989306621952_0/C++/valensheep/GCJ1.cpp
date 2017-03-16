#include <stdio.h>
#include <cstring>
using namespace std;

char st[2000];
char ans[3000];

int main(){
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);

        int tt, ca = 0;
        scanf("%d", &tt);
        while (tt--) {
                printf("Case #%d: ", ++ca);
                scanf("%s", st);
                int L, R;
                L = 1200; R = 1200;
                ans[L] = st[0];
                int n = strlen(st);
                for (int i = 1; i < n; i ++) {
                        int p = L;
                        char ch = st[i];
                        while (p <= R && ans[p] == ch) p ++;
                        if (p > R || ch < ans[p]) {R ++; ans[R] = ch; }
                        else {L --; ans[L] = ch;}
                }
                for (int i = L; i <= R; i ++) putchar(ans[i]);
                putchar('\n');
        }
}
