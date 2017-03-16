#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[105];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t, i, cnt, cas = 1, len;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        len = strlen(s);
        cnt=0;
        for(i = len - 1;i >= 0;i--) {
            if(cnt % 2 == 0) {
                if(s[i] == '+') continue;
                else cnt++;
            }
            else {
                if(s[i] == '-') continue;
                else cnt++;
            }
        }
        printf("Case #%d: %d\n", cas++, cnt);
    }
    return 0;
}
