#include <cstdio>

using namespace std;

double p[1500][1500];
int des;
int sum[1000005];
int m;
int n;
int h;

double dp(int a,int b)
{
    if(a+b>n or a>h or b>h) return p[a][b] = 0;
    if(p[a][b]!=-1) return p[a][b];
    if(b==des) return p[a][b] = 1;
    if(a==h) return p[a][b] = dp(a,b+1);
    if(b==h) return p[a][b] = dp(a+1,b);
    return p[a][b] = 0.5*dp(a+1,b) + 0.5*dp(a,b+1);
}
    
int sol(int cse)
{
    int i,j,k;
    for(i=0;i<1500;i++) for(j=0;j<1500;j++) p[i][j] = -1;
    scanf("%d %d %d",&n,&j,&k);
    if(j<0) j = -j;
    if((j+k)/2 > m) {
        printf("Case #%d: 0.0\n",cse);
        return 0;
    }
    if(sum[(j+k)/2]<=n) {
        printf("Case #%d: 1.0\n",cse);
        return 0;
    }
    des = k+1;
    n -= sum[(j+k)/2-1];
    h = j+k;
    printf("Case #%d: %lf\n",cse,dp(0,0));
    return 0;
}
    

int main()
{
    int i,j,k;
    int t;
    sum[0] = 1;
    for(i=1,j=5;sum[i-1]+j<=1000000;i++,j+=4) sum[i] = sum[i-1] + j;
    sum[i] = sum[i-1]+j;
    m = i;
    scanf("%d",&t);
    for(i=1;i<=t;i++) sol(i);
    return 0;
}
