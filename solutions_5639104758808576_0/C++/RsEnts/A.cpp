#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1010

using namespace std;

int T, N;
char str[MaxN];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int i, j, T0 = 0;
    scanf("%d", &T);
    for( ; T; --T) {
        scanf("%d", &N);
        scanf("%s", &str);
        int now = 0, ans = 0;
        for(i = 0; i <= N; ++i) {
            if(now < i && str[i] - '0' > 0) {
                ans += i - now;
                now = i;
            }
            now += str[i] - '0';
        }
        printf("Case #%d: %d\n", ++T0, ans);
    }
    return 0;
}
