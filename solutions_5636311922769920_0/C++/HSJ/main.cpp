#include<stdio.h>

int main()
{
    int test,t;
    int k,c,s,i,j;
    long long temp,temp2,temp3;
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    scanf("%d",&test);
    for(t=1;t<=test;t++){
        scanf("%d%d%d",&k,&c,&s);
        if((c+k-1)/c>s){
            printf("Case #%d: IMPOSSIBLE\n",t);
            continue;
        }
        printf("Case #%d: ",t);
        if(c>=k){
            temp = 0;
            temp2 = 1;
            for(i=0;i<k;i++){
                temp += temp2*(long long)i;
                temp2 *= k;
            }
            printf("%I64d\n",temp+1);
        }
        else{
            temp3 = 0;
            for(i=0;i<(c+k-1)/c;i++){
                temp = 0;
                temp2 = 1;
                for(j=0;j<c;j++){
                    temp += temp2*((temp3+(long long)j)%k);
                    temp2 *= k;
                }
                printf("%I64d ",temp+1);
                temp3 += c;
            }
            printf("\n");
        }
    }
    return 0;
}
