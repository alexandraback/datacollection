#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1010;
double a[N],b[N];
int n;

int com(double *a,double *b,int n)
{
    if(n<=0) return 0;
    int s=0;
    int j=0;
    for(int i=0;i<n;i++,j++)
    {
        while(j<n&&b[j]<a[i]) j++;
        if(j<n) s++;
    }
    return n-s;
}

int main()
{
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lf",&a[i]);
        for(int i=0;i<n;i++) scanf("%lf",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int sNormal=com(a,b,n);
        int sCheat=n-com(b,a,n);
//        for(int i=0,j=n-1;i<n&&a[i]<b[j];i++,j--)
//        {
//            sCheat=max(sCheat,com(a+i+1,b,n-i-1));
//        }
        printf("Case #%d: ",++cs);
        printf("%d %d\n",sCheat,sNormal);
    }
    return 0;
}










