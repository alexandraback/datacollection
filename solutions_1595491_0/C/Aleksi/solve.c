#include<stdio.h>

int ceildiv3(int x){
    if(x==0)return 0;
    return 1+(x-1)/3;
}

int main(){
    int t;
    int i;
    scanf("%i\n",&t);
    for(i=0;i<t;i++){
        int n,p,s;
        int result=0;
        int j;
        scanf("%i %i %i",&n,&s,&p);
        for(j=0;j<n;j++){
            int x;
            int x3;
            scanf("%i",&x);
//printf("xx %i\n",x);
            x3 = ceildiv3(x);
            if(x3>=p)result++;
            else if(x3==p-1 && s>0){
                switch(x%3){
                    case 0: // x x x
                        if(x!=0){
                            result++;
                            s--;
                        }
                        break;
                    case 1: // x x x+1
                        break;
                    case 2: // x x+1 x+1
                        result++;
                        s--;
                        break;
                }
            }
        }
        printf("Case #%i: %i\n",i+1,result);
    }
    return 0;
};
