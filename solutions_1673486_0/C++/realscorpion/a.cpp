#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);

    int T,A,B;
    double p[10000],mul[10000];
    double ans=-1,expv;
    cin>>T;
    for(int iter=1;iter<=T;++iter)
    {
        mul[0]=1;
        cin>>A>>B;
        ans=2+B;
        for(int i=1;i<=A;++i)
        {
            cin>>p[i];
            mul[i]=mul[i-1]*p[i];
        }
        for(int i=0;i<=A;++i)
        {
            expv=(B-A+2*i+1)*mul[A-i]+(2*B-A+2*i+2)*(1-mul[A-i]);
            if(expv<ans)
                ans=expv;
        }
        printf("Case #%d: %.6f\n",iter,ans);
    }
}
