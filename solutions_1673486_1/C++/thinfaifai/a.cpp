#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int tc,n,m;
double p[100005];

int main() {
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++)
            scanf("%lf",&p[i]);
        double ret = m+2.0;
        double td = 1.0;
        for (int i=0; i<n; i++) {
            td *= p[i];
            ret = min(ret,td*((n-i-1)*2+m-n+1)+(1-td)*((n-i-1)*2+m-n+1+m+1));
        }
        printf("Case #%d: %f\n",t,ret);
    }
}
