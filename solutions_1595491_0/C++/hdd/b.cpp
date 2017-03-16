#include <iostream>
#include <cstdio>
#define maxn 2000
using namespace std;

int number[maxn];

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,icas,n,s,p,i,yes,wants;
    scanf("%d",&cas);
    for(icas=1; icas<=cas; ++icas)
    {
        yes=wants=0;
        scanf("%d%d%d",&n,&s,&p);
        for(i=0; i<n; ++i)
        {
            scanf("%d",&number[i]);
            if(number[i]>=3*p-2) yes++;
            else if(number[i]<3*p-4);
            else if(number[i]>=2) wants++;
        }
        int ans=yes+(s>wants?wants:s);
        printf("Case #%d: %d\n",icas,ans);
    }
    return 0;
}
