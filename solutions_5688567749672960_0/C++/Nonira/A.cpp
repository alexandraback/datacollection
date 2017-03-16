#include<stdio.h>

long long x,q,k,i,a,j,s,t1,t2,inv;

int main(){
    scanf("%lld",&q);
    for(k=1;k<=q;k++){
        scanf("%lld",&x);
        i=0;
        a=x;
        s=0;
        inv=0;
        while(a>0){
            i++;
            inv*=10;
            inv+=a%10;
            a/=10;
        }
        if(i==1){
            printf("Case #%lld: %lld\n",k,x);
            continue;
        }
        t1=1;
        t2=1;
        for(j=1;j<=i;j++){
            if(j%2==1)t1*=10;
            else t2*=10;
            if(j==i)break;
            s+=t1+t2-2;
            s++;
        }
        if(inv%t2!=1&&x%t1==0){
            s++;
            x--;
        }
        a=x;
        inv=0;
        while(a>0){
            inv*=10;
            inv+=a%10;
            a/=10;
        }
        if(inv%t2==1)printf("Case #%lld: %lld\n",k,s+x%t1);
        else printf("Case #%lld: %lld\n",k,s+x%t1+inv%t2);
    }
    return 0;
}
