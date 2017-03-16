#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);

double dp[2111][2111];
int maxl;
double f(int a, int b){
    double flag1, flag2;
    if(a<0 || b<0) return 0.0;
    if(dp[a][b]>-eps) return dp[a][b];
    if(a==0 && b==0) return dp[a][b]=1.0;
    if(b==maxl) flag1 = 1.0;else flag1 = 0.5;
    if(a==maxl) flag2 = 1.0;else flag2 = 0.5;
    return dp[a][b] = f(a-1,b)*flag1+f(a,b-1)*flag2;
}


#define N 1000005
int sum[N];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("1.txt","w",stdout);
    int i, tt, cnt, cal=0, n, x, y, u, v, j;
    for(sum[0]=0,i=1;i<=100000;i++){
        sum[i] = sum[i-1] + 4*i-3;
        if(sum[i]>N*2) break;
    }
    cnt = i+1;
    scanf("%d",&tt);
    while(tt--){
        printf("Case #%d: ",++cal);
        scanf("%d%d%d",&n,&x,&y);
        u = upper_bound(sum,sum+cnt,n)-sum;
        if(sum[u-1]==n) u--;
        if((fabs(x)+y)/2+1 < u){
            puts("1.000000000000");
            continue;
        }

        if((fabs(x)+y)/2+1 > u){
            puts("0.000000000000");
            continue;
        }

        if(n==sum[u]){
            puts("1.000000000000");
            continue;
        }

        n -= sum[u-1];

        maxl = 2*u-2;
        //cout << maxl << endl;
        for(i=0;i<=maxl;i++)
        for(j=0;j<=maxl;j++)
            dp[i][j] = -1;
            //cout << maxl << endl;
       // cout << maxl << endl;
        double ans = 0;
        for(i= y+1;i <=maxl;i++)
        if(n-i>=0 && n-i<=maxl)
        ans += f(i,n-i);
        printf("%.12f\n",ans);
    }
    return 0;
}
