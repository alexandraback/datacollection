#include <stdio.h>
#include <assert.h>
unsigned long long pw(int k,int c){
    return c==0?1:k*pw(k,c-1);
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int s,k,c;scanf("%d%d%d",&k,&c,&s);
        unsigned long long mx=pw(k,c);
        if(s*c<k){
            printf("Case #%d: IMPOSSIBLE\n",i);
            continue;
        }
        printf("Case #%d:",i);
        int b=0;unsigned long long tp=0;
        for(int j=0;j<k;j++){
            tp=tp*k+j;++b;
            assert(tp<mx);
            if(b==c){printf(" %llu",tp+1);b=0;tp=0;}
        }
        if(b>0)printf(" %llu",tp+1);
        printf("\n");
    }
}