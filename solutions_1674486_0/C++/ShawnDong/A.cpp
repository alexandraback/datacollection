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
const int N=1001;
int mp[N][N];
int vis[N*N];
int lis[N],head,tail;
bool bfs(int x){
     CLR(vis);
     vis[x]=1;
     lis[0]=x;
     head=-1,tail=0;
     do{
        int now=lis[++head];
        for (int i=1;i<=mp[now][0];++i){
            if (vis[mp[now][i]]) return true;
            vis[mp[now][i]]=now;
            lis[++tail]=mp[now][i];
        }
     }while (head<tail);
     return false;
}
void solve(){
     cin>>n;
     for (int i=1;i<=n;++i){
         scanf("%d",&mp[i][0]);
         for(int j=1;j<=mp[i][0];++j)
                 scanf("%d",&mp[i][j]);
     }
     CLR(vis);
     printf("Case #%d: ",++T);
     bool f=false;
     for (int i=1;i<=n && !f;++i)
         f |= bfs(i);
     if (f){
        printf("Yes\n");
     }
     else printf("No\n");
}
int main(){
    freopen("A-small-attempt3.in","r",stdin);
    freopen("A.out","w",stdout);
    int _;
    cin>>_;
    T=0;
    while (_--)
          solve();
}
