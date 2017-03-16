#include<cstdio>
#include<algorithm>
using namespace std;
long long int dp[60];
int mat[60][60],b,bits[70];
long long m;
int main()
{
    int t,i,j,k,zero;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%lld",&b,&m);
        printf("Case #%d: ",i);
        for(j=0;j<b;j++){
            for(k=0;k<=j;k++){
                mat[j][k]=0;
            }
            for(k=j+1;k<b;k++){
                mat[j][k]=1;
            }
        }
        for(j=0;j<b;j++)
            mat[0][j]=0;
        j=b-1;
        zero=0;
        while(m&&j>1){
            mat[0][j-1]=m%2;
            if(m%2==0)
                zero++;
            m/=2;
            j--;
        }
        if(j==1&&m==1&&zero==b-2){
            for(j=1;j<b;j++)
                mat[0][j]=1;
            printf("POSSIBLE\n");
            for(j=0;j<b;j++){
                for(k=0;k<b;k++){
                    printf("%d",mat[j][k]);
                }
                printf("\n");
            }
        }
        else if(j==1&&m>=1){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("POSSIBLE\n");
            for(j=0;j<b;j++){
                for(k=0;k<b;k++){
                    printf("%d",mat[j][k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
