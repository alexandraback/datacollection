#include <cstdio>

char s[105];

int main() {
    int t; scanf("%d", &t);
    for(int _i=1; _i<=t; _i++) {
        scanf(" %s", s);
        int c=0, i;
        for(i=1; s[i]!='\0'; i++) {
            if(s[i]!=s[i-1]) c++;
        }
        if(s[i-1]=='-') c++;
        printf("Case #%d: %d\n", _i, c);
    }
}
