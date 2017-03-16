/*
     Author : Akai
     Problem :
     Time :
*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define PI acos(-1.0)

using namespace std ;

int T , d[1007] , dis[1007] ,din[1007] , vis[1007] , f[1007][1007] , s[1007] ,ans , n , m ;

void dfs(int x){
     vis[x] = 1 ;
     if (ans == 1) return ;
     if (dis[x] && !din[x]){ ans = 1 ; return ;}
     if (din[x] == 1) return ;
     dis[x] = 1 ; din[x] = 1 ;
     for (int i = 1 ; i <= d[x] ; i++) dfs(f[x][i]) ;
     din[x] = 0 ;
}

int main(){
    freopen("A-small.in" , "r" , stdin) ;
    freopen("A-small.out" , "w" , stdout);
    scanf("%d" , &T);
    for (int cases = 1 ; cases <= T ; cases++){
          printf("Case #%d: " , cases);
          scanf("%d" , &n);
          memset(f , 0 , sizeof(f)) ;
          for (int i = 1 ; i <= n ; i++){
              scanf("%d" , &d[i]) ;
              for (int j = 1 ; j <= d[i] ; j++) scanf("%d" , &f[i][j]) ;
          }
          if (n <= 2){
                puts("No");
                continue ;
          }
          memset(vis , 0 ,sizeof(vis)) ;
          ans = 0 ;
          for (int i = 1 ; i <= n ; i++)if (!vis[i]){ 
              memset(dis , 0 ,sizeof(dis)) ;
              dfs(i) ;
          }
          if (!ans) puts("No") ; else puts("Yes");
    }
}
