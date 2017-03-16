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
ll ans = 0 ;
int n ;
struct node{
    int a[100] ;
    bool operator < (const node & t){
        for(int i=0;i<n;i++){
            if(a[i] < t.a[i]) return 1 ;
            else if(a[i] > t.a[i]) return 0 ;
            else continue ;
        }
        return 1 ;
    }
}lt[200] ;
int d[100][100] ;
int vis[2550] ;
int main(){
    freopen("1" , "r" , stdin) ;
    freopen("2" , "w" ,stdout );
    int T ; scanf("%d" , &T) ;
    int ca = 0 ;
    while(T --){
        mem0(vis , 0) ;
        scanf("%d" ,&n) ;
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&lt[i].a[j]) ;
                vis[lt[i].a[j]] ++  ;
                vis[lt[i].a[j]] %= 2 ;
            }
        }
        printf("Case #%d:" , ++ca) ;
        for(int i=0;i<2500;i++){
            if(vis[i] == 1) {
                printf(" %d" , i) ;
            }
        }
        printf("\n") ;
    }
}

