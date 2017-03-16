#include <bits/stdc++.h>
 
using namespace std;
#define sd(t) scanf("%d" , &t)  
#define sdl(t) scanf("%lld" , &t)  
#define sdd(t) scanf ("%lf" , &t)
#define  ll long long 
 #define f(i , a , n)  for ( i=a ; i<=n ; i++ )
 #define fr( i , a , n ) for ( i=a ; i>=n ; i-- )
#define mp make_pair
#define pb push_back
#define F first  
#define S second
#define maxn 305
#define maxr 105
#define MOD  1000000007
#define INF  1000000000000000000ll
#define LSOne(S) (S & (-S))



 int main()
 {
      int t ; sd(t) ; int T = t ; 
      while(t--)
     {    int n ;sd(n) ; 
     int i ; 
     map  <int , int > m ; int x = (2*n-1)*n ; 
     	int y ; 
     	f ( i ,1 , x ) { sd(y) ; m[y]++ ;  } vector < int > br ; 
     	 f ( i , 1 , 2500)
     	 { if(m[i]%2) br.pb(i) ; }
     	sort( br.begin() , br.end()) ; 
    	
     	int s = br.size() ; printf("Case #%d: " , T-t ) ; 
     	f ( i , 0 , s-1) printf("%d "  ,br[i] ) ; 
  cout<<endl ; 
     }
     
     
 }