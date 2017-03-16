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

int a[1007] ;
//bool b[1000007] ;
struct tx{ 
       int x , s ;
} dx[20000007] ; 
int d[107] , e[107] ;
int sd , se ;
int T , n , s ;

bool cmp(const tx &a , const tx &b){
     return a.s < b.s ;
}
void getans(){
     for (int i = 1 ; i <(1 << n) - 1 ; i++){
         int j = i ;
         while (dx[i].s == dx[j].s){
             //  printf("%d %d XXX\n" , dx[i].s , i);
               if ((dx[i].x & dx[j].x) == 0){
            //     printf("%d %d %d %d\n" , dx[i].x , dx[j].x , dx[i].s , dx[j].s);
                  for (int k = 1 ; k <= n ; k++) if ((1 << (k - 1)) & dx[i].x) printf("%d " , a[k]);printf("\n");  
                  for (int k = 1 ; k <= n ; k++) if ((1 << (k - 1)) & dx[j].x) printf("%d " , a[k]);printf("\n");                            
                  return ;
               }
               j++ ;
         }
     }
}

int main(){
    freopen("C-small.in" , "r" , stdin);
    freopen("C-small.out" , "w" , stdout);
    scanf("%d" , &T);
    for (int cases = 1 ; cases <= T ; cases++){
        scanf("%d" , &n);
        printf("Case #%d:\n" ,cases);
        for (int i = 1 ; i <= n ; i++) scanf("%d" , &a[i]);
        for (int i = 1 ; i < (1 << n) - 1 ; i++){
            dx[i].s = 0 ;
            for (int j = 1 ; j <= n ; j++) if ((1 << (j - 1)) & i) dx[i].s += a[j] ;
        //   if (i <= 1000) printf("%d " , dx[i].s);
       ////     printf("%d " , dx[i].s);
                if (dx[i].s == 0) printf("XXXXX\n");
            dx[i].x = i ;
       }
        sort(dx + 1 , dx + (1 << n) - 1 , cmp);
        //for (int i = 1 ; i <= 1000 ; i++)  printf("%d  %d\n" , dx[i].s , dx[i].x);
        getans() ;
    }
}
