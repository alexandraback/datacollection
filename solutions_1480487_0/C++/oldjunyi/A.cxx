#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int cs,n,a[200];
    scanf("%d",&cs);
    for(int no=1;no<=cs;no++){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        int sum=accumulate(a,a+n,0);
        printf("Case #%d:",no);
        for(int i=0;i<n;i++){
            double lo=0,hi=1;
            for(int c=0;c<100;c++){
                double at=(lo+hi)/2;
                double use=at,now=a[i]+sum*at;
                for(int j=0;j<n;j++)
                    if(i!=j && a[j]<now) use+=(now-a[j])/sum;
                if(use>1) hi=at; else lo=at;
            }
            printf(" %.12f",lo*100);
        }
        puts("");
    }
}