#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N=1000010;
double P[N];
int A,B;

double work(int i,int A,int B,double tmp)
{
    return ((A-i)*2+B-A+1)*tmp+(1-tmp)*((B+1)+(A-i)*2+B-A+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t=0,ca;
    for(scanf("%d",&ca);ca--;)
    {
        scanf("%d%d",&A,&B);
        P[0]=1;
        double tmp=1;
        double ans=B+2;
        for(int i=1;i<=A;++i)
            scanf("%lf",&P[i]);
        for(int i=0;i<=A;++i)
            tmp*=P[i],ans=min(ans,work(i,A,B,tmp));
        printf("Case #%d: %.6f\n",++t,ans);
    }
    return 0;
}
