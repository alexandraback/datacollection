#include<stdio.h>

int main(){
    int R,C,W;
    int T;
    int i,ans,count;
    int temp;

    while(EOF!=scanf("%d",&T)){
        for(i=0;i<T;i++){
            scanf("%d%d%d",&R,&C,&W);
            count = C*R/W -1;
            temp = C%W;
            if(temp==0){
                ans = W+count;
            }
            else{
                ans = (W +count) +1;
            }

            printf("Case #%d: %d\n",i+1,ans);
        }
    }

}
