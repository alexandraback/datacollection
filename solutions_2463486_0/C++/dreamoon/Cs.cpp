#include<stdio.h>
int cs,d[5]={1,4,9,121,484};
int main(){
    int T,A,B;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&A,&B);
        printf("Case #%d: ",++cs);
        int an=0,i;
        for(i=0;i<5;i++)if(A<=d[i]&&d[i]<=B)an++;
        printf("%d\n",an);
        
    }
}
