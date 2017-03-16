#include<stdio.h>
#include<stdlib.h>
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,i,j;
    long long r,t;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%lld%lld",&r,&t);
        long long tmp = t;
        long long value = 2*r+1;
        int check = 0;
        for(j=0;;j++){
            if(t >= value)
                t -= value;
            else{
                check = 1;
                break;
            }
            value += 4;
            if(j > 1000) break;
        }
        t = tmp;
        if(check == 1)
            printf("Case #%d: %d\n",i+1,j);
        else{
            long long plus = 100000;
            long long k;
            for(k=1;;){
                long long value1 = 2*k*k + 3*k + 1 + 2*k*r + 2*r;
                long long value2 = 2*(k+1)*(k+1) +3*(k+1) + 1 + 2*(k+1)*r + 2*r;
                //printf("%lld %lld %lld %lld\n",k,value1,value2,t);
                //system("pause");
                if(value1 == t){
                    printf("Case #%d: %lld\n",i+1,k+1);
                    break;
                }
                else if(value2 == t){
                    printf("Case #%d: %lld\n",i+1,k+2);
                    break;
                }
                else if(value1 < t && value2 > t){
                    printf("Case #%d: %lld\n",i+1,k+1);
                    break;
                }
                else if(value1 > t){
                    if(plus == 10000){
                        k -= 9999;
                        plus = 1000;
                    }
                    else if(plus == 1000){
                        k -= 999;
                        plus = 100;
                    }
                    else if(plus == 100){
                        k -= 99;
                        plus = 10;
                    }
                    else{
                        k -= 9;
                        plus = 1;
                    }
                }
                else{
                    k += plus;
                }
            }
        }
    }
}
