#include<cstdio>

using namespace std;

long long int cost(long long int n,long long int r){
    long long int i,j,k;
    k = n*2*r + ((2+4*(n-1))*n)/2;
    if(k<0){
        printf("n: %lld r: %lld k: %lld\n",n,r,k);
    }
    return k;
}

long long int min(long long int a, long long int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

int main(){
    long long int i,j,k,l,m,n,o,p,r,t;
    long long int b, e, mid;
    long long int maxint;
    long long int maxmaxint;
    
    scanf("%lld",&n);
    
    maxint=1;
    for(i=0;i<9;i++){
        maxint*=10;
    }
    //printf("%lld\n",maxint);
    
    maxmaxint=1;
    for(i=0;i<18;i++){
        maxmaxint*=10;
    }
    maxmaxint*=2;
    maxmaxint+=215;
    //printf("%lld\n",maxmaxint);
    
    for(l=0;l<n;l++){
        scanf("%lld",&r);
        scanf("%lld",&t);
        //printf("%lld %lld\n",r,t);
        e = min(maxint,maxmaxint/r);
        b = 0;
        
        while((e-b)>1){
            mid = (b+e)/2;
            //printf("b: %lld e: %lld mid: %lld cost: %lld\n",b,e,mid,cost(mid,r));
            if(cost(mid,r)>t){
                e=mid;
            }else{
                b=mid;
            }
        }
        //mid = (b+e)/2;
        //printf("b: %lld e: %lld mid: %lld cost: %lld\n",b,e,mid,cost(mid,r));
        
        printf("Case #%lld: %lld\n",l+1,b);
        
    }
    
    return 0;
}
