#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
int n;
int a[300];
int main()
{
    freopen("in3.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;++c)
    {
        printf("Case #%d:",c);
        int i,sun=0;
        scanf("%d",&n);
        for(i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            sun+=a[i];
        }
        double x=2*sun*1.0;
        double xx=x/n;
        int z=0;
        int visit[300]={0};
        for(i=0;i<n;++i){if(a[i]>=xx){z++;x=x-a[i];visit[i]=1;}}
        xx=x/(n-z);
       // cout<<x<<endl;
        for(i=0;i<n;++i)
        {
            if(visit[i]){printf(" 0.00000");continue;}
        double y=(xx-a[i])/sun;
            y=y*100;

         printf(" %.6f",y);
        }
        printf("\n");
    }

}
