#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

double a[MAXN+1],b[MAXN+1];
int n;

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int c,t,i,j,y,z;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%lf",&b[j]);
        }
        sort(a,a+n);
        sort(b,b+n);
        y=0;
        for(i=0,j=0;(i<n)&&(j<n);i++)
        {
            if(a[i]>b[j])
            {
                y++;
                j++;
            }
        }
        z=0;
        for(i=0,j=0;(i<n)&&(j<n);j++)
        {
            if(b[j]>a[i])
            {
                i++;
            }
            else
            {
                z++;
            }
        }
        printf("Case #%d: %d %d\n",c+1,y,z);
    }
    return 0;
}
