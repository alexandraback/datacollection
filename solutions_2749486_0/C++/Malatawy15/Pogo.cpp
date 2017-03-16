#include<stdio.h>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,x,y;
    scanf("%d",&t);
    for (int k=1;k<=t;k++){
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",k);
        if (x<0){
            for (int i=0;i<-2*x;i++){
                if (i%2==0)
                    printf("E");
                else printf("W");
            }
        }
        else {
            for (int i=0;i<2*x;i++){
                if (i%2==0)
                    printf("W");
                else printf("E");
            }
        }
        if (y<0){
            for (int i=0;i<-2*y;i++){
                if (i%2==0)
                    printf("N");
                else printf("S");
            }
        }
        else{
            for (int i=0;i<2*y;i++){
                if (i%2==0)
                    printf("S");
                else printf("N");
            }
        }
        printf("\n");
    }
}
