#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int a[1024];

int main() {
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T, ca, n, s, p, i;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        scanf("%d%d%d",&n,&s,&p);
        int c0 = 0, c1 = 0;
        for (i = 0 ; i < n ; i++) {
            scanf("%d",&a[i]);
            if (a[i] >= p + max(0,(p-1)) + max(0,(p-1))) {
                ++c0;
            } else if (a[i] >= p + max(0,(p-2)) + max(0,(p-2))) {
                ++c1;
            }
        }
        printf("Case #%d: %d\n",ca,c0+min(c1,s));
    }
    return 0;
}
