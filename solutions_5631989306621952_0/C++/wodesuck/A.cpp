#include <stdio.h>
#include <string.h>

const int MAXN = 1010;
int n;
char s[MAXN];
bool v[MAXN];

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        scanf("%s", s);
        n = strlen(s);
        printf("Case #%d: ", cas);
        memset(v, 0, sizeof(v));
        int cur = n;
        for (char ch = 'Z'; ch >= 'A'; --ch) {
            for (int i = cur - 1; i >= 0; --i) {
                if (s[i] == ch) {
                    putchar(ch);
                    v[cur = i] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) if (!v[i]) putchar(s[i]);
        puts("");
    }
}
