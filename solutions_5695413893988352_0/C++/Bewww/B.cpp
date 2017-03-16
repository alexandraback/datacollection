#include<stdio.h>
#include<string.h>
char a[20];
char b[20];
int T;
int A,B;
int abs = 999999999;
char nowa[20],nowb[20];
int ans1,ans2;
int rec2(int yy)
{
    int i;
    int p,q,r;
    if(yy == B)
    {
        p=0;
        for(i=0;i<A;i++)
        {
            p+=(nowa[i] - '0');
            p*=10;
        }
        p/=10;
        q=0;
        for(i=0;i<B;i++)
        {
            q+=(nowb[i] - '0');
            q*=10;
        }
        q/=10;
        r = p-q;
        if(r<0)r*=-1;
        if(r < abs)
        {
            ans1 = p;
            ans2 = q;
            abs = r;
        }
        else if(r == abs)
        {
            if(p < ans1)
            {
                ans1 = p;
                ans2 = q;
            }
            else if(p == ans1)
            {
                if(q < ans2)
                {
                    ans1 = p;
                    ans2 = q;
                }
            }
        }
        return 0;
    }
    if(b[yy] != '?')
    {
        nowb[yy] = b[yy];
        rec2(yy+1);
        return 0;
    }
    for(i=0;i<=9;i++)
    {
        nowb[yy] = '0' + i;
        rec2(yy+1);
    }
}
int rec(int xx)
{
    int i;
    if(xx == A)
    {
        rec2(0);
        return 0;
    }
    if(a[xx] != '?')
    {
        nowa[xx] = a[xx];
        rec(xx+1);
        return 0;
    }
    for(i=0;i<=9;i++)
    {
        nowa[xx] = '0' + i;
        rec(xx+1);
    }
    return 0;
}
int main()
{
        freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.txt","w",stdout);
    int i,j,k;
    int p,q,r;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%s",a);
    scanf("%s",b);
    A = strlen(a);
    B = strlen(b);
    ans1=-1;ans2=-1;
    abs = 999999999;
    rec(0);
    printf("Case #%d: ",ii);
    if(A == 1)printf("%d",ans1);
    else if(A == 2)printf("%02d",ans1);
    else if(A == 3)printf("%03d",ans1);
    if(B == 1)printf(" %d",ans2);
    else if(B == 2)printf(" %02d",ans2);
    else if(B == 3)printf(" %03d",ans2);
    printf("\n");
}
    return 0;
}
