#include<bits/stdc++.h>
using namespace std ;
long long dp[1000009] ;

int revers( int n )
{
 int r = 0 ;
    while (n != 0)
   {
      r = r * 10;
      r = r + n%10;
      n = n/10;
   }

return r ;
}

int main()
{

long long rate ;
int t , n ;
cin >> t ;
long long f1 ;
long long f2 ;
int ans ;

for ( int i = 0 ; i <= 20 ; i++)
dp[i] = i ;


for ( int i = 21 ; i <= 1000005 ; i++)
{
    int y = revers(i) ;
    int y2 = revers(y) ;
    if ( y < i )
    {
        if ( y2 == i )
dp[i] = min ( dp[i-1] , dp[ revers(i)]) + 1  ;
else
    dp[i] = dp[i-1] + 1 ;
    }
else
    dp[i] = dp[i-1] + 1 ;
}
for ( int x = 1 ; x <= t ; x++)
{
cin >> n ;
int ans = dp[n];
cout << "Case #"<<x<<": "<<ans << endl ;
}

return 0 ;
}
