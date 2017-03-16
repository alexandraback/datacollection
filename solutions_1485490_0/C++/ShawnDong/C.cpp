/*
 * =====================================================================================
 *
 *         Author:  KissBuaa.DS(AC)
 *        Company:  BUAA-ACMICPC-Group
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
#include <math.h>
#define LL long long
#define CLR(x) memset(x,0,sizeof(x))
#define typec double
#define sqr(x) ((x)*(x))
#define abs(x) ((x)<0?(-(x)):(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define inf 100000000
//For C++
#include <cctype>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
int n,m,T;
const int N=200;
struct ele{
       long long num;
       int t;
       void input(){
            cin>>num>>t;
       }
}a[N],b[N],c[N],d[N];
long long prea[N][N],preb[N][N];
long long dp[N][N][3];
void solve(){
     cin>>n>>m;
     CLR(prea,preb);
     for (int i=1;i<=n;++i) {
         a[i].input();
         for (int j=1;j<=100;++j)
             prea[i][j]=prea[i-1][j];
         prea[i][a[i].t]+=a[i].num;
     }
     for (int i=1;i<=m;++i) {
         b[i].input();
         for (int j=1;j<=100;++j)
             preb[i][j]=preb[i-1][j];
         preb[i][b[i].t]]+=b[i].num;
     }
     CLR(dp);
     for (int i=1;i<=n;++i)
         for (int j=1;j<=m;++j)
             for(int p=0;p<=i;++p)
                 for (int q=0;q<=j;++q){
                     if (a[i].t!=b[j].t){
                        if (dp[i][j][0]<dp[p][q][0]){
                           dp[i][j][0]=dp[p][q][0];
                           if (i==p) dp[i][j][1]=dp[p][q][1];
                           if (j==q) dp[i][j][2]=dp[p][q][2];
                        }
                     }
                     else{
                        if (dp[i][j][0]<dp[p][q][0]+min())
                     }
                 }
}
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int _;
    cin>>_;
    while (_--)
          solve();
}
