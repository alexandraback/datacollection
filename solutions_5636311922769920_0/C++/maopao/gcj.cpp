#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
long long qpow(long long x,int k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans*=x;
        k>>=1;
        x*=x;
    }
    return ans;
}
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
//    freopen("B-large.in","r",stdin);
//    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        long long beg=1LL;
        long long step=qpow(k,c-1);
        printf("Case #%d: ",cas);
        for(int i=0;i<s;i++)
        {
            printf("%I64d ",beg);
            beg+=step;
        }
        printf("\n");
    }
    return 0;
}
