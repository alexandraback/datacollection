#include <bits/stdc++.h>
using namespace std ;

string s ;
int t , n , x, cse ;
int ans[30] ;
int main()
{
    freopen("A-small-attempt0.txt", "r" , stdin ) ;
    freopen("ansA.txt", "w+" , stdout ) ;

     cin >> t ;

     while(t--)
     {
         cin >> s ;
         n = s.size() ;
         map < char , int > cnt ;
         memset( ans , 0 , sizeof(ans )  ) ;

         for( int i = 0 ; i < n ; i++ )
         {
             cnt[s[i]]++ ;
         }
         ans[0] = cnt['Z'] ;
         ans[1] = cnt['O'] - cnt['Z'] - cnt['W'] - cnt['U'] ;
         ans[2] = cnt['W'] ;
         ans[3] = cnt['H'] -  cnt['G'] ;
         ans[4] = cnt['U'] ;
         ans[5] = cnt['F'] -cnt['U'] ;
         ans[6] = cnt['X'] ;
         ans[7] = cnt['S'] - cnt['X'] ;
         ans[8] = cnt['G'] ;
         ans[9] = cnt['I'] -cnt['F'] +cnt['U'] -cnt['X'] -  cnt['G'];
         cout << "Case #"<<++cse<< ": " ;
         for( int i = 0 ; i < 10 ; i++ )
         {
             while(ans[i]-- > 0 )printf("%d", i) ;
         }
         cout << endl ;
     }






return 0 ;
}
