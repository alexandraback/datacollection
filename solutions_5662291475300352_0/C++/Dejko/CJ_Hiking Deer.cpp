#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long d1,h,m1,d2,m2,n,sol;

int main() {
    freopen("C-small-1-attempt6.in","r",stdin);
    freopen("CCC16.out","w",stdout);
    scanf("%d",&T);
    for (int t=1; t<=T; t++) {
        scanf("%lld",&n);
        scanf("%lld %lld %lld",&d1,&h,&m1);
        if (n==2) scanf("%lld %lld %lld",&d2,&h,&m2);
        else if (h>1) {
            d2=d1;
            m2=m1+1;
        }
        else {
            printf("Case #%d: 0\n",t);
            continue;
        }
        if (d2<d1 || (d2==d1 && m2>m1)) {
            swap(d1,d2);
            swap(m1,m2);
        }
        if (m1>=m2) {
            if ((360-d1)*m1 < (720-d2)*m2) sol=0;
            else sol=1;
        }
        else {
            double x=(double)d1 + (double)(d2-d1)*m1/(double)(m2-m1);
            if (x>360) sol=0;
            else {
                if ((360-x)*m2 < (720-x)*m1) sol=0;
                else sol=1;
            }
        }
        printf("Case #%d: %lld\n",t,sol);
    }

    return 0;
}
