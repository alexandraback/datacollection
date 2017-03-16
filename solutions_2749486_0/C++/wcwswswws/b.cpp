#include<stdio.h>
int tt,x,y;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",t);
        char a='S',b='N';
        if (y<0) {char c=a;a=b;b=c;y=-y;}
        while (y--) printf("%c%c",a,b);
        a='W',b='E';
        if (x<0) {char c=a;a=b;b=c;x=-x;}
        while (x--) printf("%c%c",a,b);
        printf("\n");
    }
    return 0;
}
