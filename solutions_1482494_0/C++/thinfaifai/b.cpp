#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int tc,n;
int a[2][1005],v[1005];

int main() {
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        scanf("%d",&n);
        for (int i=0; i<n; i++)
            scanf("%d%d",&a[0][i],&a[1][i]);
        memset(v,0,sizeof(v));
        int star = 0;
        int ret = 0;
        for (int i=0; i<2*n; i++) {
            int cho = -1;
            for (int j=0; j<n; j++)
                if (star >= a[1][j] && v[j] < 2) {
                    cho = j; break;
                }
                else if (star >= a[0][j] && v[j] < 1) {
                    if (cho == -1) cho = j;
                    else if (a[1][j] > a[1][cho]) cho = j;
                }
            if (cho == -1) break;
            if (star >= a[1][cho]) {
                star += 2-v[cho];
                v[cho] = 2;
            }
            else {
                star += 1-v[cho];
                v[cho] = 1;
            }
            //printf("%d\n",cho);
            ret++;
        }
        if (star != 2*n) printf("Case #%d: Too Bad\n",t);
        else printf("Case #%d: %d\n",t,ret);
    }
}
