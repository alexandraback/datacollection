#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int c,t,i,j,a,b,k,s;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d %d %d",&a,&b,&k);
        s=0;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i&j)<k)
                {
                    s++;
                }
            }
        }
        printf("Case #%d: %d\n",c+1,s);
    }
    return 0;
}
