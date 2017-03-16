#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
char chr[2005], s[1005];
int Cas;
int main() {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    int t;
    int l , r;
    scanf("%d", &t);
    while(t--) {
        printf("Case #%d: ", ++Cas);
        scanf("%s", s);
        l = r = 1001;
        chr[l] = s[0];
        for(int i = 1; i < strlen(s); i++) {
            if(s[i] >= chr[l]) chr[--l] = s[i];
            else chr[++r] = s[i];
        }
        for(int i = l; i <= r; i++)
            printf("%c", chr[i]);
        puts("");
    }

    return 0;
}
