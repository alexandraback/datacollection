#include<cstdio>
#include<cstring>

char S[10000];
char ans[20000];

int T;

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%s", S);
        printf("Case #%d: ", cas);
        int cnt = 10000, head = cnt - 1, rail = cnt + 1;
        ans[cnt] = S[0];
        for(int i = 1; S[i]; i++) {
            if(S[i] >= ans[head + 1]) {
                ans[head--] = S[i];
            }
            else {
                ans[rail++] = S[i];
            }
        }
        for(int i = head + 1; i < rail ; i++) {
            printf("%c", ans[i]);
        }
        puts("");
    }
    return 0;
}