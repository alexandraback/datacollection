#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>

using namespace std;

int T , x , n , y;
double f[207][207] ; 

int main()
{   
   freopen("B-small-attempt2.in" , "r" , stdin);
   freopen("B-small-attempt2.txt" ,"w" , stdout);
  // freopen("A-large.in" , "r" , stdin);
  // freopen("A-large.out" ,"w" , stdout);
   scanf("%d" , &T);
   for (int cases = 1 ; cases <= T ; cases++){
      scanf("%d%d%d" , &n , &x,&y);
      x = abs(x) ;
      y = abs(y) ;
      double ans = 0.0 ;
      int cnt = n , tmp = 0 ; 
      while (cnt > 0){
         tmp ++ ;
         cnt -= (tmp * 4) - 3 ;
      }
    //  printf("%d\n" , cnt);
    //  printf("%d\n" , tmp);
       if (cnt < 0){
         cnt += tmp * 4 - 3 ;
         tmp -- ;
        }
      // printf("%d\n" , tmp);
      int d = (x + y) / 2 ;
      if (d < tmp) ans = 1.0 ;
      else if (d > tmp) ans = 0.0 ;     
      else {
         memset(f , 0 , sizeof(f)) ;
         f[0][0] = 1.0 ;
         for (int i = 0 ; i < cnt ; i++)
            for (int j = 0 ; j <= 2 * tmp ; j++){
               if (i + 1 - j <= 2 * tmp)
               f[i+1][j] += f[i][j] * (double)0.5 ;
               else f[i+1][j+1] += f[i][j] *(double) 0.5 ;
               if (j + 1 <= 2 * tmp)
               f[i+1][j+1] += f[i][j] * (double)0.5 ;
               else f[i+1][j] += f[i][j] * (double) 0.5 ;
            }
           /*for (int i = 0 ; i <= cnt ; i++){
            for (int j = 0 ; j <= cnt ; j++)
               printf("%.6lf " , f[i][j]) ;
             printf("\n");}
             */
         for (int i = 1 ; i <= 2 * tmp  ; i++)
            if (i >= y + 1) ans += f[cnt][i] ;
      }
      printf("Case #%d: %.8lf\n" ,cases ,  ans);
    }                
            
      

   return 0;
}
