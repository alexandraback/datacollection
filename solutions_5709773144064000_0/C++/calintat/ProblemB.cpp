#include <cstdio>
using namespace std;
double C,F,X,tx,ty,t;
int i,T,ok,f;
int main()
{
    freopen("ProblemB.in","r",stdin);
    freopen("ProblemB.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf %lf %lf",&C,&F,&X);
        t=0;
        f=0;
        tx=0;
        ty=0;
        ok=1;
        while(ok)
        {
            ty=tx;
            tx=t+X/(2+f*F);
            if(tx>ty && tx!=0 && ty!=0)
            {
                printf("Case #%d: %.7f\n",i,ty);
                ok=0;
            }
            t+=C/(2+f*F);
            f++;
        }
    }
}
