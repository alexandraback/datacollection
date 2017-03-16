#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int c,T,x,y,xx,yy,i;
    char str[505];
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        printf("Case #%d: ",c);
        scanf("%d%d",&x,&y);
        xx=abs(x);
        yy=abs(y);
        if(x<0)
        {
            for(i=0;i<(xx<<1);i+=2)
            {
                str[i]='E';
                str[i+1]='W';
            }
        }
        else
        {
             for(i=0;i<(xx<<1);i+=2)
            {
                str[i]='W';
                str[i+1]='E';
            }
        }
        if(y>0)
        {
             for(i=(xx<<1);i<(xx<<1)+(yy<<1);i+=2)
            {
                str[i]='S';
                str[i+1]='N';
            }
        }
        else
        {
              for(i=(xx<<1);i<(xx<<1)+(yy<<1);i+=2)
            {
                str[i]='N';
                str[i+1]='S';
            }
        }
        str[i]=0;
        printf("%s\n",str);
    }
    return 0;
}
