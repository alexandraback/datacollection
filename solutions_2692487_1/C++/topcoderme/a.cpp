#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int a[105];

int  func(int i,int m,int n)
{
    int c=0,c1;

      for(;i<n&&a[i]<m;i++)
            m+=a[i];

    if(i==n) return 0;
    for(c1=0;m<=a[i];)
    {
        m=m+(m-1);c1++;
    }

    c=c1+func(i,m,n);
    if(c>n-i) c=n-i;
    return c;

}

int main()
{
    int t,w,c,i;
    scanf("%d",&t);
    for(w=1;w<=t;w++)
    {
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);c=0;

        if(m==1)
            printf("Case #%d: %d\n",w,n);
        else
      printf("Case #%d: %d\n",w,func(0,m,n));


    }
}
