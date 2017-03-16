#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
long long net[55][55];
int main(){
    long long n,tt,T,i,j,x;
    long long m,y;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&T);
    for(tt=1;tt<=T;tt++){
        scanf("%lld %lld",&n,&m);
        y=1LL;
        for(i=1;i<=n-2;i++) y*=2;
        if(m>y){
            printf("Case #%lld: IMPOSSIBLE\n",tt);
            continue;
        }
        for(i=1;i<n;i++){
            for(j=1;j<=i;j++)   net[i][j]=0;
            for(j=i+1;j<n;j++)    net[i][j]=1;
        }
        for(i=1;i<=n;i++)   net[n][i]=net[i][n]=0;
        x=2;
        if(m==y){net[1][n]=1;m--;}
        while(m){
            net[x++][n]=m%2;
            m/=2;
        }
        printf("Case #%lld: POSSIBLE\n",tt);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)   printf("%lld",net[i][j]);
            printf("\n");
        }
    }
    return 0;
}

