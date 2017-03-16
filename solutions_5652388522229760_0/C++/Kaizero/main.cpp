#include<stdio.h>
int TC, N, TT, j;
bool v[10];
int main(){
    long long i, t;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        printf("Case #%d: ",TT);
        scanf("%d",&N);
        if(N==0){
            printf("INSOMNIA\n");
            continue;
        }
        for(i=0;i<10;i++)v[i]=false;
        for(i=1;;i++){
            t=i*N;
            while(t){
                v[t%10]=true;
                t/=10;
            }
            for(j=0;j<10;j++)if(!v[j])break;
            if(j==10)break;
        }
        printf("%lld\n",i*N);
    }
}
