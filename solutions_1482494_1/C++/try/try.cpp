#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1000
#define INF 10000
using namespace std;

int a[MAXN+1],b[MAXN+1];
int n;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int k,t,i,c,m,s,p,f;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        c=0;
        m=0;
        s=0;
        do
        {
            p=-1;
            for(i=1;i<=n;i++)
            {
                if(s>=b[i])
                {
                    c++;
                    m++;
                    p=i;
                    s++;
                    if(a[i]<INF)
                    {
                        a[i]=INF;
                        s++;
                    }
                    b[i]=INF;
                    break;
                }
            }
            if(p!=-1)
            {
                continue;
            }
            for(i=1;i<=n;i++)
            {
                if((s>=a[i])&&((p==-1)||(b[p]<b[i])))
                {
                    p=i;
                }
            }
            if(p!=-1)
            {
                c++;
                s++;
                a[p]=INF;
            }
        }while((m<n)&&(p!=-1));
        printf("Case #%d: ",k+1);
        if(m==n)
        {
            printf("%d\n",c);
        }
        else
        {
            printf("Too Bad\n");
        }
    }
    return 0;
}
