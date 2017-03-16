#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;

#define N 111111

double a[N] , b[N] ;
bool vis[N] ;
int main() {
    freopen("D-large.in" , "r" , stdin) ;
    freopen("D-large.out" , "w" , stdout) ;
    int T ; cin >> T ;
    int ca = 0 ;
//    int ca = 0 ;
    while(T -- ) {
        int n ; cin >> n ;
        for (int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
        for (int i = 0 ; i < n ; i ++ ) cin >> b[i] ;
        sort(a , a + n) ;
        sort(b , b + n) ;
        memset(vis , 0 , sizeof(vis)) ;
        for (int i = 0 ; i < n ; i ++ ) {
            for (int j = 0 ; j < n ; j ++ ) {
                if(!vis[j] && b[j] > a[i]) {
                    vis[j] = 1 ;
                    break ;
                }
            }
        }
        int ans1 = 0 ;
        for (int i = 0 ; i < n ; i ++ ) ans1 += !vis[i] ;
//        for (int i = 0 ; i < n ; i ++ ) if(a[i] > b[i]) ans1 ++ ;
//        reverse(b , b + n) ;
        int ans2 = 0 ;
        memset(vis , 0 , sizeof(vis)) ;
        for (int i = 0 ; i < n ; i ++ ) {
            bool flag = 0 ;
            for (int j = 0 ; j < n ; j ++ ) {
                if(!vis[j] && a[i] > b[j]) {
                    vis[j] = 1 ;
                    flag = 1 ;
                    break ;
                }
            }
            ans2 += flag ;
        }
//        for (int i = 0 ; i < n ; i ++ ) cout << a[i]<<  " " ; cout << endl;
//        for (int i = 0 ; i < n ; i ++ ) cout << b[i]<<  " " ; cout << endl;

//        for (int i = 0 ; i < n ; i ++ ) if(a[i] > b[i]) ans2 ++ ;
        printf("Case #%d: %d %d\n" , ++ ca , ans2  , ans1) ;
    }
    return 0 ;
}
/*


50

10

0.93 0.68 0.60 0.66 0.79 0.63 0.55 0.67 0.98 0.61

0.46 0.14 0.11 0.28 0.31 0.37 0.29 0.19 0.53 0.49

*/
