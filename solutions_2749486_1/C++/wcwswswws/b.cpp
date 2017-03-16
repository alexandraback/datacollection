#include<stdio.h>
#include<string.h>

int tt,x,y;
char s[5000];

void work(int x,int y)
{
    memset(s,0,sizeof(s));
    int sum=x+y;
    if (x<0) sum-=2*x;
    if (y<0) sum-=2*y;
    int k=1,num=1;
    while (num<sum)
    {
        k++;num+=k;
    }
    if ((num-sum)&1) {k++;num+=k;}
    int pos=(num-sum)/2;
    if (pos==0)
    {
        char a='E',b='N';
        if (x<0) {a='W';x=-x;}
        if (y<0) b='S';
        for (int i=k;i>0;i--)
        if (i<=x) {s[i-1]=a;x-=i;} else s[i-1]=b;
    } else
    {
        char a='E',b='N';
        if (x<0) {a='W';x=-x;}
        if (y<0) b='S';
        bool check=true;int xx=x,yy=y;
        x+=pos;
        for (int i=k;i>0;i--)
        if (i<=x) {if (i!=pos){s[i-1]=a;x-=i;}} else {s[i-1]=b;if(i!=pos)y-=i;}
        s[pos-1]='W';if (a=='W') s[pos-1]='E';
        if (x>0) check=false;
        if (!check)
        {
            x=xx;y=yy;y+=pos;
            for (int i=k;i>0;i--)
            if (i<=x) {s[i-1]=a;x-=i;} else {s[i-1]=b;y-=i;}
            s[pos-1]='S';if (b=='S') s[pos-1]='N';
        }
        //printf("%d %d\n",x,y);
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&x,&y);
        work(x,y);
        printf("Case #%d: %s\n",t,s);
    }
    return 0;
}
