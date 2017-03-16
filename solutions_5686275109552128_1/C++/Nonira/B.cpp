#include<stdio.h>

int t,i,d,p[1010],k,c,mn,j;

int main(){
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        mn=2000;
        scanf("%d",&d);
        for(i=0;i<d;i++)scanf("%d",&p[i]);
        for(i=1;i<=1000;i++){
            c=0;
            for(j=0;j<d;j++){
                c+=(p[j]-1)/i;
            }
            if(c+i<mn)mn=c+i;
        }
        printf("Case #%d: %d\n",k,mn);
    }
    return 0;
}
