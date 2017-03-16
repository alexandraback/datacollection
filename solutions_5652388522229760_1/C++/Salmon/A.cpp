#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool hs[12];
int ct=0;
int ad(int x)
{
    while(x!=0)
    {
        ct+=(hs[x%10]==0);
        hs[x%10]=1;
        x/=10;
    }
    return ct;
}
int ty(int x)
{
    if(x==0)
        return 0;
    ct=0;
    for(int i=0;i<=10;i++)
        hs[i]=0;
    for(int i=1;;i++)
    {
        if(ad(x*i)==10)
            return x*i;
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int t;
    int x;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&x);
        if(x==0)
            printf("Case #%d: INSOMNIA\n",i);
        else
            printf("Case #%d: %d\n",i,ty(x));
    }
}
