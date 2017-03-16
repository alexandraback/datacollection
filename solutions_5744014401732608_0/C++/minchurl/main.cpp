#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct emp{
    int x,y;
};
int net[55][55];
int main(){
    int n,tt,T,i,j,x;
    int m,y;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++){
        scanf("%d %d",&n,&m);
        y=(1<<(n-2));
        if(m>y){
            printf("Case #%d: IMPOSSIBLE\n",tt);
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
        printf("Case #%d: POSSIBLE\n",tt);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)   printf("%d",net[i][j]);
            printf("\n");
        }
    }
    return 0;
}

