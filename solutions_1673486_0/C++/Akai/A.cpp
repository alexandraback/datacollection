/*
     Author : Akai
     Problem : A
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

double a[100001] , Tmp ,  ans ;
int T , n , m ;

int main(){
    freopen("A-small.in" , "r" , stdin);
    freopen("A-small.out" , "w" , stdout);
    scanf("%d" , &T);
    for (int cases = 1 ; cases <= T ; cases++){
        scanf("%d%d" , &n , &m);
        ans = m*1.0 + 2 ;
        for (int i = 1 ; i <= n ; i++) scanf("%lf" , &a[i]);
        Tmp = 1 ;
        for (int i = 1 ; i <= n ; i++){
            Tmp *= a[i] ;
            ans = min(ans , (1 + (n - i) * 2 +(m - n))*Tmp+(1+(n-i)*2+(m-n)+m+1)*(1-Tmp));
        }
        printf("Case #%d: %.6lf\n" , cases , ans);
    }
}
