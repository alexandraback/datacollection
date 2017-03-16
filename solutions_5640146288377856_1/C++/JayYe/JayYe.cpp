#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, cas = 1;
    int n, m, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &c);
        printf("Case #%d: ", cas++);
        int ans = 0;
        ans += (n-1)*(m/c);
        if(m == c) {
            ans += c;
//            printf("%d\n", c);
        }
        else if(m%c == 0) {
            ans += m/c-1+c;
//            printf("%d\n", m/c-1+c);
        } else {
            ans += m/c-1+c+1;
//            printf("%d\n", m/c-1+c+1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
