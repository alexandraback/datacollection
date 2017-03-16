#include <stdio.h>
#include <cstring>
using namespace std;

char st[2000];
char ans[3000];
int cnt[3000];

int main(){
        freopen("b.in", "r", stdin);
        freopen("b.out", "w", stdout);

        int tt, ca = 0;
        scanf("%d", &tt);
        while (tt--) {
                memset(cnt, 0, sizeof(cnt));
                int n;
                scanf("%d", &n);
                for (int tot = 0; tot < 2 * n - 1; tot ++){
                        int x;
                        for (int i = 0; i < n; i ++) {
                                scanf("%d", &x);
                                cnt[x] ++;
                        }
                }
                printf("Case #%d:", ++ca);
                for (int i = 1; i <= 2500; i ++) 
                        if (cnt[i] % 2 == 1) printf(" %d", i);
                putchar('\n');


                
        }
}
