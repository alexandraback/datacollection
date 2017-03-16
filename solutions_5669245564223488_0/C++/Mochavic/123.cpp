#include <stdio.h>
#include <string.h>
char c[110][110];
long long mod = 1000000007, f[110];
int s[30];
int u[110], is[110], b[110];
int pd(char s[]){
    int i, x = 0;
    for (i = 1; s[i]; i++){
        if (s[i] != s[i - 1]){
            x |= (1<<(s[i - 1] - 'a'));
            if (x & (1<<(s[i] - 'a'))) return -1;
        }
    }
    x |= (1<<(s[i - 1] - 'a'));
    return x;
}
int e[30], din[30], dout[30];
int main(){
    int T, ri = 1, n, i, j, k;
    f[0] = 1;
    for (i = 1; i < 110; i++) f[i] = (f[i - 1] * i) % mod;
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        memset(s, 0, sizeof(s));
        memset(is, 0, sizeof(is));
        int flag = 0;
        long long ans = 1;
        for (i = 0; i < n; i++){
            scanf("%s", c[i]);
            for (j = 1; c[i][j]; j++) if (c[i][j] != c[i][0]) break;
            if (!c[i][j]){
                s[c[i][0] - 'a']++;
                is[i] = 1;
            }
            b[i] = pd(c[i]);
            if (b[i] < 0) flag = 1;
        }
        for (k = 0; k < 26; k++){
            for (i = 0; i < n; i++){
                for (j = i + 1; j < n; j++){
                    if ((b[i] & (1<<k)) && (b[j] & (1<<k))){
                        if (!(c[i][0] == k + 'a' && c[j][strlen(c[j]) - 1] == k + 'a') &&
                            !(c[j][0] == k + 'a' && c[i][strlen(c[i]) - 1] == k + 'a')){
                            flag = 1;
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", ri++);
        if (flag){
            printf("0\n");
            continue;
        }
        for (k = 0; k < 26; k++) ans = (ans * f[s[k]]) % mod;
        memset(din, 0, sizeof(din));
        memset(dout, 0, sizeof(dout));
        memset(e, -1, sizeof(e));
        for (i = 0; i < n; i++){
            if (is[i]) continue;
            int x = c[i][0] - 'a', y = c[i][strlen(c[i]) - 1] - 'a';
            e[x] = y;
            din[y]++; dout[x]++;
        }
        int tot = 0;
        for (int i = 0; i < 26; i++){
            if (din[i] > 1 || dout[i] > 1) flag = 1;
            if (din[i] == 0 && dout[i] == 0 && s[i] > 0) tot++;
        }
        if (flag){
            printf("0\n");
            continue;
        }
        for (i = 0; i < 26; i++){
            if (dout[i] && din[i] == 0){
                tot++;
                int x = i;
                while (dout[x]){
                    dout[x]--;
                    x = e[x];
                    if (x >= 0) din[x]--;
                }
            }
        }
        for (i = 0; i < 26; i++) if (dout[i] || din[i]) flag = 1;
        if (flag){
            printf("0\n");
            continue;
        }
        printf("%lld\n", (ans * f[tot]) % mod);
    }
    return 0;
}
