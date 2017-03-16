
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 2510;
int ia[MAXN], ib[MAXN];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int icase, n;
    scanf("%d", &icase);
    for(int i=1; i<=icase; ++i) {
        scanf("%d", &n);
        memset(ia, 0, sizeof(ia));
        for(int j=0; j<2*n-1; ++j) {
            for(int k=0; k<n; ++k) {
                int x;
                scanf("%d", &x);
                ++ia[x];
            }
        }
        int cnt = 0;
        for(int j=1; j<=2500; ++j) {
            if(ia[j] & 1) {
                ib[cnt++] = j;
            }
        }
        printf("Case #%d: ", i);
        for(int j=0; j<cnt; ++j) {
            if(j) {
                printf(" ");
            }
            printf("%d", ib[j]);
        }
        printf("\n");
    }
    return 0;
}
