#include<stdio.h>
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,k,i,j,n,m,all,now,sum;
    while(scanf("%d",&t)!=EOF){
        for(k=1;k<=t;k++){
            all=0,now=0,sum=0;
            scanf("%d%d",&n,&m);
            for(i=2*n+1;;i+=4){
                sum+=i;
                if(sum<=m)
                    all+=1;
                else
                    break;
            }
            printf("Case #%d: %d\n",k,all);
        }
    }
}
