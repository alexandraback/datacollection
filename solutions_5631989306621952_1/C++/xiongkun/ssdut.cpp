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
char str[10000] ;
char fir[10000] ,ft = 0 ;
char las[10000] ,lt = 0 ;
int main(){
    freopen("1" , "r" , stdin) ;
    freopen("2" , "w" ,stdout );
    int T ; scanf("%d" , &T) ;
    int ca = 0 ;
    while(T --){
        ft = 0 ; lt = 0 ;
        scanf("%s" , str) ;
        int len = strlen(str) ;
        fir[ft ++] = str[0] ;
        for(int i=1;i<len;i++){
            if(str[i] < fir[ft-1]){
                las[lt++] = str[i] ;
            }
            else fir[ft++] = str[i] ;
        }
        printf("Case #%d: ",++ca) ;
        for(int i=ft-1;i>=0;i--){
            printf("%c",fir[i]) ;
        }
        for(int i=0;i<lt;i++){
            printf("%c" ,las[i]) ;
        }
        printf("\n") ;
    }
}

