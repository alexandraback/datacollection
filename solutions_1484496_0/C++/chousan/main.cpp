#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct hh
{
    int x;
    int sum;
}qq[10000000];
bool cmp(const hh p,const hh q)
{
    if(p.sum==q.sum)return p.x<q.x;
    else return p.sum<q.sum;
}
int n;
int a[300];
int main()
{
    freopen("in4.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;++c)
    {
        printf("Case #%d:\n",c);
        scanf("%d",&n);
        int i;
        for(i=0;i<n;++i)scanf("%d",&a[i]);
        for(i=0;i<(1<<n);++i)
        {
            int j;
            int s=0;
            for(j=0;j<20;++j)
            {
                if(i&(1<<j))s+=a[j];
            }
            qq[i].x=i;
            qq[i].sum=s;
        }
        sort(qq,qq+(1<<n),cmp);

       for(i=1;i<(1<<n);++i)
       {
           if(qq[i].sum==qq[i-1].sum)
           {
               int j;
               int f=0;
               for(j=0;j<20;++j)
               {
                   if((1<<j)&qq[i-1].x)
                   {
                       if(f==0){printf("%d",a[j]);f=1;}
                       else printf(" %d",a[j]);
                   }
               }
               printf("\n");
               f=0;
               for(j=0;j<20;++j)
               {
                   if((1<<j)&qq[i].x)
                   {
                       if(f==0){printf("%d",a[j]);f=1;}
                       else printf(" %d",a[j]);
                   }
               }
               printf("\n");
               break;
           }

       } if(i==(1<<n))printf("Impossible\n");
    }

}
