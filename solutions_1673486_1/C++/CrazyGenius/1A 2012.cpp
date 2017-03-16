#include<stdio.h>

using namespace std;

int main()
{
    int cc,a,b;
    double ans,tmp;
    scanf("%d",&cc);
    for(int cas = 1 ; cas <= cc ; cas++)
    {
        scanf("%d %d",&a,&b);
        double prob[a+1],dym[a+1];
        prob[0] = 1;
        dym[0] = 1;
        for(int i = 1 ; i <= a ; i++) scanf("%lf",&prob[i]);
        for(int i = 1 ; i <= a ; i++) dym[i] = dym[i-1]*prob[i];
        ans = 2+b;
        for(int i = 0 ; i <= a ; i++)
        {
            tmp = dym[a-i]*(2*i+1+(b-a)) + (1-dym[a-i])*(2*i+2+b+(b-a));
            if(ans > tmp) ans = tmp;
        }
        printf("Case #%d: %lf\n",cas,ans);
    }
    return 0;
}
