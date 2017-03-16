#include<stdio.h>
#include<stdlib.h>
int main(){
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int T,i,j;
    long long r,t;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%lld%lld",&r,&t);
        long long value = 2*r+1;
        for(j=0;;j++){
            if(t >= value)
                t -= value;
            else break;
            value += 4;
            //printf("%lld\n",value);
        }
        printf("Case #%d: %d\n",i+1,j);
    }
}
