#include<stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>


unsigned long long int ans = 2000000000, longans = 9000000000000000000;


int main(){
    int T;
    unsigned long long int k,r,n,n1,n0,temph,templ,tempn;
    long double srt;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(int t=0; t<T; t++){
        scanf("%llu%llu",&r,&k);
        n1 = ans;
        temph = k/r;
        //printf("h is %llu\n, k is %llu, r is %llu\n",temph,k,r);
        if(n1>temph) n1 = temph+1;
        //printf("n1 is %llu\n",n1);
        n0 = 0;
        n = (n1+n0)/2;
        //printf("n is %llu",n);
        while(1){
            templ = 2*n*n + 2*n*r - n;
            temph = 2*(n+1)*(n+1) + 2*(n+1)*r - (n+1);
            //printf("temps are %llu and %llu\n ",templ,temph);
            if( (k<temph)&&(k>=templ) ) break;
            if(k>=temph) n0 = n;
            if(k<templ) n1 = n;
            n = (n1+n0)/2;
        }
        printf("Case #%d: %llu\n",t+1,n);
    }


    return 0;
}
