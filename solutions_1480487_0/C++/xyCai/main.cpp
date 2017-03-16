#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
double ans[220];
double HeHe[220];
struct JieGouTi
{
    double val;
    int id;
    bool operator <(const JieGouTi &a)const
    {
        double x = val;
        double y = a.val;
        int ju;
        if(fabs(x-y)<1e-9)
            ju = 0;
        else ju = x<y?-1:1;
        return ju<0;
    }
} p[220];
int main()
{
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt0.out","w",stdout);
    int t;
    int i,j,k;
    scanf("%d",&t);
    int cases = 1;
    while(t--)
    {
        scanf("%d",&n);
        double Ehehe=0,Sum=0;
        for(i=0; i<n; ++i)
        {
            scanf("%lf",&p[i].val);
            p[i].id=i;
            Ehehe= Ehehe + p[i].val;
        }
        Sum=Ehehe;
        sort(p,p+n);
        p[n].val = 1000000000;
        i = 0;
        while(i<=n)
        {
            ans[i++]=0;
        }
        for(i=0; i<n; ++i)
        {
            int ju;
            double x = Ehehe;
            double y = (i+1)*(p[i+1].val-p[i].val);
            if(fabs(x-y)<1e-9)
                ju = 0;
            else ju = x<y?-1:1;
            if(ju>0)
            {
                ans[i] = (p[i+1].val-p[i].val);
                Ehehe -= ans[i]*(i+1);
            }
            else
            {
                ans[i] = Ehehe*1.0/(i+1);
                break;
            }
        }
        i = n-1;
        while(i>=0)
        {
            ans[i] += ans[i+1];
            i--;
        }
        for(i=0; i<n; ++i)
        {
            int id=p[i].id;
            HeHe[id]=ans[i];
        }
        printf("Case #%d:",cases++);
        for(int i=0; i<n; ++i)
            printf(" %.6f",HeHe[i]/Sum*100);
        printf("\n");
    }
    return 0;
}
