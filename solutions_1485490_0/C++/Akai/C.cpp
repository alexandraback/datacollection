/*
     Author : Akai
     Problem : C
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

long long sb[1001] , sa[1001] ;
int a[1001] , b[1001] ;
int T , n , m ;

long long get(long long s , int x , int l , int r){
    long long sum = 0;
    for (int i = l ; i <= r ; i++) if (b[i] == x) sum += sb[i] ;
    return min(s , sum);
}

int main(){
    freopen("C-small.in" , "r"  , stdin);
    freopen("C-small.out" , "w" , stdout);
    scanf("%d" , &T);
    for (int cases = 1 ; cases <= T ;cases ++){
        scanf("%d%d" , &n , &m);
        for (int i = 1 ; i <= n ; i++) scanf("%I64d%d" , &sa[i] , &a[i]);
        for (int i = 1 ; i <= m ; i++) scanf("%I64d%d" , &sb[i] , &b[i]);
        printf("Case #%d: " , cases);
        if (n == 3){
              if (a[2] == a[3]){
                       sa[2] += sa[3] ;
                       n-- ;
              }
        }
        if (n >= 2){
              if (a[1] == a[2]){
                       sa[1] += sa[2] ;
                       sa[2] = sa[3] ;
                       a[2] = a[3] ;
                       n -- ;
              }
        }
        if (n == 1){
              long long s = 0 ;
              for (int i = 1 ; i <= m ; i++) if (b[i] == a[1]) s+= sb[i] ;
              printf("%I64d\n" , min(s , sa[1]));
        }
        if (n == 2){
              long long ans = 0 ;
              for (int i = 0 ; i <= m ; i++) ans =max(ans , get(sa[1] , a[1] , 1 , i)+ get(sa[2] , a[2] , i + 1 , m));
              printf("%I64d\n" , ans) ;
        }
        if (n == 3){
              long long ans = 0 ;
              for (int i = 0 ; i <= m ; i++) 
                  for (int j = i ; j <= m ; j++)
              ans =max(ans , get(sa[1] , a[1] , 1 , i)+ get(sa[2] , a[2] , i + 1 , j) + get(sa[3] , a[3] , j + 1 , m));
              if (a[1] == a[3]) ans = max(ans , get(sa[3] + sa[1] , a[1] , 1 , m)) ;
              printf("%I64d\n" , ans) ;
        }
    }
}
        
        
         
