#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, cas = 1;
    int n, m, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &c);
        printf("Case #%d: ", cas++);
        if(m == c)  printf("%d\n", c);
        else if(m%c == 0) {
            printf("%d\n", m/c-1+c);
        } else {
            printf("%d\n", m/c-1+c+1);
        }
    }
    return 0;
}
