#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

double solve(void)
{
    double N=2.,C,F,X,wait=1.,ret=0.;
    cin>>C>>F>>X;
    if(C>X)return X/N;
    for(double buy=0.;wait>buy;N+=F)
    {
        ret+=C/N;
        wait=(X-C)/N;
        buy=X/(N+F);
    }
    return ret+wait;
}

int main()
{
#ifdef LOCALMACHINE
    freopen("C:\\Users\\zero\\Desktop\\B-small-attempt0.in","r",stdin);
    freopen("C:\\Users\\zero\\Desktop\\B-small-attempt0.txt","w",stdout);
#endif
    int T;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        printf("Case #%d: %.7f\n",i,solve());
    }
    return 0;
}
