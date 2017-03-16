#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.in","w",stdout);
    int test,tt,a,b,k,c,i,j,cnt;
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
        scanf("%d%d%d",&a,&b,&k);
        cnt=0;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                c=(i&j);
                if(c<k)
                cnt++;
            }
        }
        printf("Case #%d: ",tt);
        printf("%d\n",cnt);
    }
    return 0;
}
