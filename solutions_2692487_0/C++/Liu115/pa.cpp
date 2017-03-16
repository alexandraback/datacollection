#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,t,mote[105];
long long a;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    for(int amm=1;amm<=t;amm++)
    {
        scanf("%lld%d",&a,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&mote[i]);
        }
        sort(mote,mote+n);
        int now=0,op=0;
        while(now<n)
        {
            if(a>mote[now])
            {
                a+=mote[now];
                now++;
            }
            else if(a+a-1>mote[now])
            {
                a+=(a-1);
                a+=mote[now];
                now++;
                op++;
            }
            else
            {
                op++;
                now++;
            }
        }
        printf("Case #%d: %d\n",amm,op);
    }
    return 0;
}
