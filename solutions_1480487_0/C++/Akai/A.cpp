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

struct anode{
       int x , s ;
}a[1007] ;
double ans[1007] ; 
int T , n , s ;

bool cmp(const anode &a , const anode &b){
     return a.x < b.x ;
}

int main(){
    freopen("A-small.in" , "r" , stdin);
    freopen("A-small.out" , "w" , stdout);
    scanf("%d" , &T);
    for (int cases = 1 ; cases <= T ; cases++){
        scanf("%d" , &n);
        s = 0 ;
        for (int i = 1 ; i <= n ; i++){ 
            scanf("%d" , &a[i].x);
            a[i].s = i ; 
            s += a[i].x ;
            ans[i] = 100.000 ;
        }
        printf("Case #%d:" ,cases); 
        sort(a + 1 , a + n + 1 , cmp);
        int s2 = 0 ;
        for (int i = 1 ; i <= n ; i++){
            s2 += a[i].x ;
            for (int j = 1 ; j <= i ; j++) ans[a[j].s] = min(
            max(0.0 ,  100.0*(   (s+s2) / (i*1.0) - a[j].x )   / (s*1.0) ) ,
             ans[a[j].s]) ; 
        }
        for (int i = 1 ; i <= n ; i++)
            printf(" %.6lf" , ans[i]);
        printf("\n");
    }
}
