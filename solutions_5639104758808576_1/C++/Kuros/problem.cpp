#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAXN 110111
#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)

int T, n;

char bx[1100];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("pro.out","w",stdout);
    
    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        scanf("%d", &n);
        scanf("%s", bx);    

        int ans = 0; int now = 0;
        for(int i = 0; i <= n; i++) {
            int a = bx[i] - '0';
            if(a != 0) {
                if(now < i) ans += (i - now), now = i;
            }
            now += a;
        }
        printf("Case #%d: %d\n", cas++, ans);
    }

    
    return 0;
}