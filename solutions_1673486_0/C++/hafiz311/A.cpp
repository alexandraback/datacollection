#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<sstream>
using namespace std;


double p[100003];
int A,B;

int main()
{
    freopen("A.in","rt",stdin);
    freopen("A.out","wt",stdout);
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d%d",&A,&B);
        double rt=1.0;
        for(int i=0;i<A;i++) {
            scanf("%lf",&p[i]);
            rt*=p[i];
        }
        double mnn=rt*(B-A+1.0) + (1.0-rt)*(B-A+1.0+B+1.0);

        rt=1.0;
        double cl;

        for(int i=0;i<A-1;i++) {

            rt*=p[i];
            cl=(A-1-i+B-i)*rt+(1.0-rt)*(A-1-i+B-i+B+1.0);
            mnn=min(cl,mnn);
        }
        cl=(A+B+1.0);
        mnn=min(cl,mnn);
        cl=B+1.0+1.0;
        mnn=min(cl,mnn);

        printf("Case #%d: %.8lf\n",cas,mnn);
    }
    return 0;
}
