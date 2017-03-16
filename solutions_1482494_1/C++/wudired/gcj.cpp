#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
double p[100000];
void checkmin(double &a,double b)
{
    if (a>b)
        a=b;
}
struct data
{
    int x,y;
}a[1003];
bool b[1003];
bool cmp(const data &a, const data &b)
{
    if (a.y<b.y)
        return true;
    if (a.y==b.y&&a.x>b.x)
        return true;
    return false;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int cs,i,j,k,n,m,q=0;
    scanf("%d",&cs);
    while (cs--)
    {

        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        memset(b,true,sizeof(b));
        sort(a,a+n,cmp);
        m=0;
        k=0;
        for (i=0;i<n;i++)
        {
            if (a[i].y<=m)
            {
                if (b[i])
                m+=2;
                else
                   m++;
                continue;
            }
            while (a[i].y>m)
            {
                int t=m;
                for (j=n-1;j>=i;j--)
                {
                    if (a[j].x<=m&&b[j])
                    {
                        k++;
                        m++;

                        b[j]=false;
                        break;
                    }
                }
                if (m==t) break;
            }
            if (a[i].y>m) break;
            if (b[i])

            m+=2;
            else m++;
        }
        if (i==n)
            printf("Case #%d: %d\n",++q,k+n);
        else
            printf("Case #%d: Too Bad\n",++q);
    }
}
