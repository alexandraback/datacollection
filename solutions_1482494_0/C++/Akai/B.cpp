/*
     Author : Akai
     Problem : B
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

int a[1007] , b[1007] , D[1007] ;
int s , ans , n , T ;
bool flag ; 

void get(){
     flag = 1 ;
     for (int i = 1 ; i <= n ; i++) if (D[i] != 2) flag = 0 ;
     if (flag) return ;
     ans ++ ;
     for (int i = 1 ; i <= n ; i++) if (D[i] != 2) if (b[i] <= s){
         s += 2 - D[i] ;
         D[i] = 2 ;
         
   //  for (int i = 1 ; i <= n ; i++) printf("%d " , D[i]) ; printf("\n");
         return ;
     }
     int k = 0 ;
     for (int i = 1 ; i <= n ; i++) if (D[i] == 0) 
         if (a[i] <= s && b[i] > b[k]) k = i ;
     if (k == 0) return ;
     D[k] = 1 ; s++ ; 
     
    //for (int i = 1 ; i <= n ; i++) printf("%d " , D[i]) ; printf("\n");
     return ;
}

int main(){
    freopen("B-small.in" , "r" , stdin);
    freopen("B-small.out" , "w" , stdout);
    scanf("%d" , &T);b[0] = -1 ;
    for (int cases = 1 ; cases <= T ; cases++){
        scanf("%d" , &n); ans = 0 ; s = 0 ;
        for (int i = 1 ; i <= n ; i++) scanf("%d%d" , &a[i] , &b[i]);
        for (int i = 1 ; i <= n ; i++) D[i] = 0 ; 
        flag = 0 ;
        for (int i = 1 ; i <= n * 2 ; i++)if (!flag) get();
        printf("Case #%d: " , cases);flag = 1 ;
        for (int i = 1 ; i <= n ; i++) if (D[i] != 2) flag = 0 ;
        if (flag) printf("%d\n" , ans) ; else puts("Too Bad");
    }
}
