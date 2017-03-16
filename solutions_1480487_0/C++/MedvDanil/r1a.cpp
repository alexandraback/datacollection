#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn = 100*1024;
int a[maxn];
int n;
double p[maxn];
double eps=1e-9;
double sum=0;
double check(double k){
    double res=0;
    for(int i=0;i<n;i++)
        if(k>=a[i])
            res+=(k-a[i])/sum;
    return res;
}
double bsearch(){
    double l=0,r=100000;
    while(r-l>eps){
        double m=(l+r)/2;
        if(check(m)<1)
            l=m;
        else r=m;
    }
    return l;
}
int main(){
#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        int v,i,min;

        int t;
        scanf("%d",&t);
        for(int I=1;I<=t;I++){
            scanf("%d",&n);
            sum=0;
            for( i=0;i<n;i++){
                scanf("%d",a+i);
                sum+=a[i];
            }
            printf("Case #%d:",I);
            double k=bsearch();
           /* double sump=0;
            for(i=0;i<n;i++){
                double x=(2*sum/n-a[i])*100.0/sum;
                if(x<0)x=0;
                p[i]=x;
                sump+=x;
            }
            for(i=0;i<n;i++)
                printf(" %.9lf",p[i]/sump*100);
                */
            for(i=0;i<n;i++)
                printf(" %.7lf",(k-a[i])*100.0/sum < 0.0 ?  0.0 : (k-a[i])*100.0/sum);

            putchar('\n');
        }
}
