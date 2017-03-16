#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1000000007;

double dp[3000][3000];

double gao(int n, int x, int y){
    int m;
    for(m=0;(m+1)*(2*m+1)<=n;m++)
        if(abs(x)+y<=m*2) return 1;
    if(abs(x)+y>m*2) return 0;
    n-=m*(2*m-1);
    dp[0][0]=1;
    double ret=0;
    for(int i=0;i<=m+m;i++) for(int j=0;j<=m+m;j++){
        if(i==m+m && j==m+m){
        }else if(i==m+m){
            dp[i][j+1]+=dp[i][j];
        }else if(j==m+m){
            dp[i+1][j]+=dp[i][j];
        }else{
            dp[i+1][j]+=dp[i][j]*0.5;
            dp[i][j+1]+=dp[i][j]*0.5;
        }
        if(i+j==n && i>y) ret+=dp[i][j];
        dp[i][j]=0;
    }
    return ret;
}

int main(){
    int cs,no=0;
    scanf("%d",&cs);
    while(cs--){
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        double ans=gao(n,x,y);
        printf("Case #%d: %.15f\n",++no,ans);
    }
}
