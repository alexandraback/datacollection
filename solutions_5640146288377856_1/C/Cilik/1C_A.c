#include<stdio.h>

int main(){
    int R,C,W;
    int T;
    int i,ans,count;
    int temp;

    while(EOF!=scanf("%d",&T)){
        for(i=0;i<T;i++){
            scanf("%d%d%d",&R,&C,&W);
            count = (C/W -1)*R;
            temp = C%W;
            if(temp==0){
                ans = W+count + (R-1);
            }
            else{
                ans = (W +count) +1+(R-1);
            }

            printf("Case #%d: %d\n",i+1,ans);
        }
    }

}
