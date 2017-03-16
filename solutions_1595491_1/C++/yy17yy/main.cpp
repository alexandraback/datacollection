#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int tt,kk=1;
    for(scanf("%d",&tt);tt--;)
    {
        int n,s,p;
        scanf("%d%d%d",&n,&s,&p);
        int v1=0,v2=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(p*3-2<=x && x<=30)
                v1++;
            else if( (x==p*3-3 || x==p*3-4)&&p-2>=0)
                v2++;
        }
        printf("Case #%d: %d\n",kk++,v1+min(v2,s));
    }
    return 0;
}

