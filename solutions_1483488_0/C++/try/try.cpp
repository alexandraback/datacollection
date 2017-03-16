#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXL 255
using namespace std;

char s[MAXL+1];
int x[MAXL+1];
int a,b;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int k,t,n,m,c,d,i,len;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d %d",&a,&b);
        c=0;
        for(n=a;n<b;n++)
        {
            sprintf(s,"%d",n);
            len=strlen(s);
            d=0;
            for(i=0;i<len;i++)
            {
                rotate(s,s+1,s+len);
                sscanf(s,"%d",&m);
                if((m>n)&&(m<=b))
                {
                    x[d++]=m;
                }
            }
            sort(x,x+d);
            c=c+unique(x,x+d)-x;
        }
        printf("Case #%d: %d\n",k+1,c);
    }
    return 0;
}
