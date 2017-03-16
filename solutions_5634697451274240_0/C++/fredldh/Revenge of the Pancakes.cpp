#include<stdio.h>
#include<string.h>
int main() {
    int T, t = 1;
    char s[105];
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%s", s);
        int res = 0;
        for(int i = 1; i < strlen(s); ++i) {
            if(s[i] != s[i-1]) res ++;
        }
        if(s[strlen(s)-1] == '-') res ++;
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
