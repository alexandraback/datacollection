#include<stdio.h>
#include<string.h>

int power(int r){
while(r % 2 == 0){
    r = r/2;
}
if(r == 1){
    return 1;
}
else{
    return 0;
}
}


int main(){
    int t,i;
    int k = 0;
    scanf("%d",&t);
    int p,q;
    for(i=1;i<=t;i++){
        scanf("%d/%d",&p,&q);
        if(power(q)){
        while(p/q < 1){
            p = p*2;
            k++;
        }
        printf("Case #%d: %d\n",i,k);
        k = 0;
        }
        else{
            printf("Case #%d: impossible\n",i);
        }
    }
return 0;
}

