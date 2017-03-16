#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define N 1000005
#define M 25
#define Mod 1000000007
#define INF 2000000007
int f[1005][1005];
typedef long long LL;
int n , m;
int cases = 0;

void pre(){
     int i , j;
     memset(f,0,sizeof(f));
     for (i=1;i<=1000;++i){
         int t = i;
         for (j=1;j<=1000;++j){
             if (j % 2) t-=2;
             f[i][j] = f[i][j-1];
             if (t <= 0) continue;
             f[i][j] += t;
         }
     }
}
int x , y , t;
int check(int i , int j){
    return (f[i][y-j] + f[j][x-i]);
}

void Solve(){
     int i , j , k , a , b;
     scanf("%d%d%d",&x,&y,&t);
     int ans = 2*(x+y);
     if (x == 1 || y == 1 || k <= 4) ans = t; else
     for (i=1;i<=x;++i)
         for (j=1;j<=y;++j){
             if (2*(i+j) > ans) break;
             a = 2*(i+j)+i*j + check(i,j);
             if (a >= t) ans = min(ans,2*(i+j));
             a += max(i,j);
             if (a >= t) ans = min(ans,2*(i+j)+1);
         }
     printf("Case #%d: %d\n",++cases,ans);
}

int main(){
    freopen("3.txt","r",stdin);
    freopen("2.txt","w",stdout);
    pre();
    int test;
    cin >> test;
    while (test--) Solve();
    return 0;
}
