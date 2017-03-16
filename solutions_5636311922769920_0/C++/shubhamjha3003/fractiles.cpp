#include<cstdio>
int main()
{
    int i,t,k,c,s,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&k,&c,&s);
        if(c==1){
            printf("Case #%d: ",i);
            if(s<k){
                printf("IMPOSSIBLE\n");
            }
            else{
                for(j=1;j<=k;j++){
                    printf("%d ",j);
                }
                printf("\n");
            }
        }
        else{
            printf("Case #%d: ",i);
            if(k%2==0&&s<k/2)
                printf("IMPOSSIBLE\n");
            else if(k%2==1&&s<k/2+1)
                printf("IMPOSSIBLE\n");
            else if(k==1){
                printf("1\n");
            }
            else{
                for(j=1;j<=k/2;j++){
                    printf("%d ",k*(j-1)+(k-j+1));
                }
                if(k%2==1){
                    printf("%d ",k*(j-1)+(k/2+1));
                }
                printf("\n");
            }
        }
    }
    return 0;
}
