#include<stdio.h>

int main()
{
    int t,test;
    long long n,i,digit,temp;
    int check;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&test);
    for(t=1;t<=test;t++){
        scanf("%I64d",&n);
        if(n == 0){
            printf("Case #%d: INSOMNIA\n", t);
            continue;
        }
        i=0,check=0;
        while(1){
            i++;
            temp = n*i;
            while(temp){
                check = check | (1<<(temp%10));
                temp /= 10;
            }
            if(check == 1023)
                break;
        }
        printf("Case #%d: %I64d\n",t, i*n);
    }
    return 0;
}
