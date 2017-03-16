#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char ans[20000];
char st[20000];
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _ = 1; _ <= cas; _++) {
        printf("Case #%d: ", _);
        scanf("%s", st + 1);
        int n = strlen(st + 1);
        int offset = n + 1, l = n + 1, r = n + 1;
        ans[offset] = st[1];
        for (int i = 2; i <= n; i++) {
            if (st[i] >= ans[l]) {
                l--;
                ans[l] = st[i];
            } else {
                r++;
                ans[r] = st[i];
            }
        }
        for (int i = l; i <= r; i++) putchar(ans[i]);
        puts("");
    }
}
