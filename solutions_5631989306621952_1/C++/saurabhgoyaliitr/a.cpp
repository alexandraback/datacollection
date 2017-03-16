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

string s ; 

 int main()
 {
      int t ; sd(t) ; int T = t ; 
      while(t--)
     {   int i ; 
         cin>>s ; int l = s.length() ; char temp = s[0] ;  
         string s1 = "" , s2 = "" ; 
           for ( i  = 1 ; i < l ; i++  )
         {
             if(s[i] >=temp)  { s1+= s[i] ; temp = s[i] ; }
             else s2 += s[i] ; 
         }
         
         printf("Case #%d: " , T-t ) ; 
        int l2 =s1.length() ;  fr ( i , l2-1 , 0) cout<<s1[i] ; 
        cout<<s[0]<<s2<<endl ; 
         
     }
     
     
 }