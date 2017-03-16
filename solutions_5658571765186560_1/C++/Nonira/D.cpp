#include<stdio.h>

int t,x,r,c,k,mx,mn;
int main(){
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        scanf("%d %d %d",&x,&r,&c);
        if(r*c%x!=0)printf("Case #%d: RICHARD\n",k);
        else if(x>=7)printf("Case #%d: RICHARD\n",k);
        else{
            if(c>r){
                mx=c;
                mn=r;
            }
            else{
                mx=r;
                mn=c;
            }
            if(mx<x)printf("Case #%d: RICHARD\n",k);
            else{
                if(x==3&&mn<=1)printf("Case #%d: RICHARD\n",k);
                else if(x==4&&mn<=2)printf("Case #%d: RICHARD\n",k);
                else if(x==5&&mn<=3)printf("Case #%d: RICHARD\n",k);
                else if(x==6&&mn<=3)printf("Case #%d: RICHARD\n",k);
                else printf("Case #%d: GABRIEL\n",k);
            }
        }
    }
    return 0;
}
