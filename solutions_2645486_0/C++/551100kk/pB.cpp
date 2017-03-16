#include<stdio.h>
int s[10000000],e,n,max;
void boom(int ee,int r,int sum,int j){
    int a,i;
    if(j==n){
        if(sum>max) max=sum;
        return;
    }
    for(i=0;i<=ee;i++){
        a=ee-i+r;
        if(a>e) a=e;
        boom(a,r,sum+s[j]*i,j+1);
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,k,i,j,now,r,ne;
    while(scanf("%d",&t)!=EOF){
        for(k=1;k<=t;k++){
            max=0;
            scanf("%d%d%d",&e,&r,&n);
            for(i=0;i<n;i++){
                scanf("%d",&s[i]);
            }
            boom(e,r,0,0);
            printf("Case #%d: %d\n",k,max);
        }
    }
}
