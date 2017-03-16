#include<stdio.h>
#include<stdlib.h>

int main(){

int cases;
scanf("%d",&cases);

long long int r,t,i,j,sum,prev_sum;

for(i=1;i<=cases;i++){

    scanf("%lld",&r);
    scanf("%lld",&t);
    r=r+1;
    for(j=1;j<=t;j++){
        sum = j*(2*r-1) + 2*j*(j-1);
        if(sum>t){
            printf("Case #%lld: %lld\n",i,j-1);
            break;
        }
        prev_sum = sum;
    }
}

return 0;
}
