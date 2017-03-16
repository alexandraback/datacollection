#include<cstdio>
#include<algorithm>
using namespace std;
int T,testNo,N,I,DW,W,i;
double EA[1010],EL[1010];
int calculeaza1()
{
    int lbN,ubN,lbK,ubK,result;
    lbN=lbK=1;
    ubN=ubK=N;
    result = 0;
    for(;lbN<=ubN;)
    {
        if(EA[lbN]<EL[lbK])
        {
            lbN++;
            ubK--;
            continue;
        }
        result++;
        lbN++;
        lbK++;
    }
    return result;
}
int calculeaza2()
{
    int lbN,ubN,lbK,ubK,result;
    lbN=lbK=1;
    ubN=ubK=N;
    result = 0;
    for(;lbN<=ubN;)
    {
        if(EA[ubN]>EL[ubK])
        {
            ubN--;
            lbK--;
            result++;
            continue;
        }
        ubK--;
        ubN--;
    }
    return result;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    for(scanf("%d",&T);T;T--)
    {
        testNo++;
        printf("Case #%d: ",testNo);
        DW=W=0;
        scanf("%d",&N);
        for(i=1;i<=N;i++)scanf("%lf",&EA[i]);
        for(i=1;i<=N;i++)scanf("%lf",&EL[i]);
        sort(EA+1,EA+N+1);
        sort(EL+1,EL+N+1);
        DW = calculeaza1();
        W = calculeaza2();
        printf("%d %d\n",DW,W);
    }
    return 0;
}
