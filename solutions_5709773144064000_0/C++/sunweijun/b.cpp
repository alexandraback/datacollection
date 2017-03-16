#include<cstdio>
#define fo(i,a,b) for(int i=a;i<=b;++i)
double C,F,X;
double solve()
{
    if(X==0)return 0.0;
    double res=X/2,fi=0.0,now;
    fo(i,1,100000)
    {
        fi=fi+(double)C/(2+F*(i-1));
        now=fi+(double)X/(2+F*i);
        if(now>res)break;
        res=now;
    }
    return res;
}
int main()
{
    int Q;
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        scanf("%lf%lf%lf",&C,&F,&X);
        double answer=solve();
        printf("Case #%d: %.8lf\n",T,answer);
    }
    return 0;
}
