#include <stdio.h>

int c[2501];
int main()
{
    int T,N,k,i,j,temp;
    scanf("%d",&T);
    for(k=1;k<=T;k++){
        for(j=0;j<2501;j++)
            c[j] = 0;
        scanf("%d",&N);
        for(i=0;i<(2*N)-1;i++){
            for(j=0;j<N;j++) {
                scanf("%d",&temp);
                c[temp]++;
            }
        }
        printf("Case #%d: ",k);
        for(i=1;i<=2500;i++){
            if(c[i]%2==1)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
