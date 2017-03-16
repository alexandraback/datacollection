#include<cstdio>
int main(){
    int i,turn,a,b,c;
    scanf("%d",&turn);
    for(i=1;i<=turn;i++){
        scanf("%d %d %d",&a,&b,&c);
        printf("Case #%d: ",i);
        if((b*c)%a||a==4||(a==3&&(b*c)%2==1)){
            printf("RICHARD\n");
        }else{
            printf("GABRIEL\n");
        }
    }
}
