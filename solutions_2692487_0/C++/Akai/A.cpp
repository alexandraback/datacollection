#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>

using namespace std;

int T , a[107] , x , n;

int main()
{   
   freopen("A-small-attempt0.in" , "r" , stdin);
   freopen("A-small-attempt0.out" ,"w" , stdout);
   scanf("%d" , &T);
   for (int cases = 1 ; cases <= T ; cases++){
      scanf("%d%d" , &x ,&n);
      int ans = n ; 
      for (int i = 1 ; i <= n ; i++) scanf("%d" , &a[i]);
      sort(a + 1 , a + n + 1) ;
      if (x > 1)
      for (int i = 1 ; i <= n ; i++){
         int cnt = n - i , tmp = x ;
         for (int j = 1 ; j <= i ; j++){
            while (tmp <= a[j]){
               tmp += tmp - 1; 
               cnt ++ ;
              }
              tmp += a[j] ;
         }
         ans = min(ans , cnt) ;
     }
     printf("Case #%d: %d\n" ,cases ,  ans);
    }                
            
      

   return 0;
}
