#include<stdio.h>
#include<stdlib.h>
//#include <gmpxx.h>
long long int binsearch(long long int b, long long int e, long long int r , long long int t){
    long long int form, sum, mid;
    sum = b*(2*r-1) + 2*b*(b-1);
    if(sum>t)return b-1;
    if(b==e)return b;
    mid = (b+e)/2;
    sum = mid*(2*r-1) + 2*mid*(mid-1);
//    printf("%lld %lld\n",mid,sum);
    if(sum==t)return mid;
    if(sum<t)return binsearch(mid+1,e,r,t);
    if(sum>t)return binsearch(b,mid,r,t);

}

int main(){

int cases;
scanf("%d",&cases);

long long int r,t,i,j,sum,prev_sum,end;

for(i=1;i<=cases;i++){

    scanf("%lld",&r);
    scanf("%lld",&t);
//    printf("%lld %lld\n",r,t);
    r=r+1;
    end = 2*1000000000000000000/r;
    if(end > 1000000030)end = 1000000030;
    prev_sum = 2*1000000000;
    sum = binsearch(1,end+10,r,t);
    printf("Case #%lld: %lld\n",i,sum);
//    for(j=1;j<=t;j++){
//        sum = j*(2*r-1) + 2*j*(j-1);
//        if(sum>t){
//            printf("Case #%lld: %lld\n",i,j-1);
//            break;
//        }
//        prev_sum = sum;
//    }
}

return 0;
}
