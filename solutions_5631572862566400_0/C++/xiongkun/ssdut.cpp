#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <algorithm>
#define inf 0x3f3f3f3f
#define mem0(x , y)  memset(x , y , sizeof(x))
#define ll long long
#define REP(x , y)   for(int i=0;i<y;i++)
#define FOR(x , y)   for(int i=1;i<y;i++)
#define lowbit(x) (x & (-x))
#define read(x) scanf("%d",&x)
using namespace std ;
int a[2000] ;
int n ;
int num[2000] ;
int vis[2000] ;
int lt[2000] ;
int main(){
    freopen("1" , "r" , stdin) ;
    ///freopen("2" , "w" ,stdout );
    int T ; scanf("%d" , &T) ;
    int ca = 0 ;
    while(T --){
        mem0(num , 0) ;
        scanf("%d" , &n) ;
        for(int i=1;i<=n;i++){
            scanf("%d" , &a[i]) ;
        }
        for(int i=1;i<=n;i++){
            mem0(vis , 0) ;
            int ts = i ;
            int pre = -1 ;
            int cnt = 1 ;
            vis[ts] = 1 ;
            while(1){
                /// printf("ok\n") ;
                if(a[ts] == pre) {
                    lt[i] = cnt ;
                    num[pre] += cnt - 2  ;
                    num[ts] = num[pre] ;
                    break ;
                }
                else if(vis[a[ts]] == 1){
                    if(a[ts] == i)  lt[i] = cnt ;
                    else lt[i] = 0 ;
                    break ;
                }
                else {
                    pre = ts ; ts = a[ts] ; cnt ++ ;
                    vis[ts] = 1 ;
                }
            }
        }
        mem0(vis , 0) ;
        int ans = 0 ;
        for(int i=1;i<=n;i++){
            printf("lt[%d] = %d\n" , i , lt[i]) ;
            ans = max(ans , lt[i]) ;
        }
        int tans = 0 ;
        for(int i=1;i<=n;i++)if(num[i] != 0&&!vis[i]){
            printf("num[%d] = %d\n" , i , num[i]+2 ) ;
            tans += num[i] + 2 ;
            vis[i] = 1 ; vis[a[i]] = 1 ;
        }
        ans = max(tans , ans);
        printf("Case #%d: " , ++ca) ;
        printf("%d\n",ans) ;
    }
}

