#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int len;
int p10[10];
int A, B;
int vis[2001000];

int calc(int k) {
    int t, s = 0;
    for (int i = 1 ; i < len ; ++i) {
        int left = k / p10[i];
        int right = k % p10[i];
        int tmp = right * p10[len - i] + left;
        if (tmp <= k || tmp > B) continue;
        if (vis[tmp] != k) {
            ++s;
            vis[tmp] = k;
        }
        // printf("%d %d\n", k, tmp);
        // ++s;
    }
    return s;
}

int main() {
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    p10[0] = 1;
    for (int i = 1 ; i < 10 ; i++)
        p10[i] = p10[i-1] * 10;
    int T, ca;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d",&A,&B);
        char buf[128];
        sprintf(buf, "%d", A);
        len = strlen(buf);
        int ans = 0;
        for (int k = A ; k <= B ; k++) {
            ans += calc(k);
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
