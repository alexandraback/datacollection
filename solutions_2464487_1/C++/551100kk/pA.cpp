#include<stdio.h>
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    unsigned long long int t,k,i,j,n,m,mi,all,now,sum,l,r,x;
    while(scanf("%lld",&t)!=EOF){
        for(k=1;k<=t;k++){
            all=0,now=0,sum=0;
            scanf("%lld%lld",&n,&m);
            l=0;r=1000000000LL;
            x=2*n+1;
            if(n<=1000000000000LL){
            while(l!=r-1){
                mi=(l+r)/2;
                if((x+x+4*(mi-1))*mi/2>m)
                    r=mi;
                else
                    l=mi;
            }
            printf("Case #%lld: %lld\n",k,l);
            }
            else{
            for(i=2*n+1;;i+=4){
                sum+=i;
                if(sum<=m)
                    all+=1;
                else
                    break;
            }
            printf("Case #%lld: %lld\n",k,all);
            }
        }
    }
}
