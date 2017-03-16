#include<stdio.h>
int main()
{
    int t,n,i,j,cnt[2501],tmp,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=0;j<2501;j++)
            cnt[j]=0;
        for(j=0;j<2*n-1;j++){
            for(k=0;k<n;k++)
            {
                scanf("%d",&tmp);
                cnt[tmp]++;
            }
        }
        printf("Case #%d: ",i);
        for(j=1;j<2501;j++){
            if(cnt[j]%2!=0){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    return 0;
}

