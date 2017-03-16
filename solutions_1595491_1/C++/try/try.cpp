#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int k,t,i,n,m,s,p,x;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d %d %d",&n,&s,&p);
        m=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(((x+2)/3>=p)||((x>=2)&&((x+4)/3>=p)&&(s-->0)))
            {
                m++;
            }
        }
        printf("Case #%d: %d\n",k+1,m);
    }
    return 0;
}
