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
#define maxr 1005
#define MOD  1000000007
#define INF  1000000000000000000ll
#define LSOne(S) (S & (-S))


int temp ; 
vector < int > br[maxr] ; 

void dfs( int a , int f  , int c )
{  
    int i ;  int s = br[a].size() ; 
    if(s==0) return  ; 
    f ( i , 0 , s-1)
   { 
      //cout<<br[a][i]<<" "<<f<<endl ; 
   if(br[a][i]!=c){ dfs( br[a][i] , f+1  , c ) ; if(f+1 > temp ) temp = f+1 ; 
         
}
   }

return  ;

}

void dfs2( int a , int f   , int b )
{  //cout<<b ;
    int i ;  int s = br[a].size() ; if(s==0)return ; 
   // if(s==1 && br[a][0]== b) return  ; 
    f ( i , 0 , s-1)
   { 
      //cout<<br[a][i]<<" "<<f<<endl ; 
  if(br[a][i]!=b) { dfs2( br[a][i] , f+1 , b  ) ; if(f+1 > temp ) temp = f+1 ; }
   

   }

return  ;

}



 int main()
 {
   
   
int t; sd(t)  ; int T = t ; 

   
   while(t--)
  { 
int ar[maxr]  ;  bool c[maxr][maxr] ; 
 int n ;sd(n)  ; 
	int i, j  ;int x ;  f ( i ,1 , n ) br[i].clear() ; 
	f ( i ,1, n )
	f ( j , 1 , n ) c[i][j] = 0 ; 
	 f ( i , 1, n )
      {sd(x) ; ar[i] = x ;  br[x].pb(i) ; c[i][x] = 1 ;   


      }

vector < pair < int , int > > p ;   

//int j  ; 
f ( i ,1 , n )
f ( j  , i+1,  n )
 {if(c[i][j]==1 && c[j][i]==1) p.pb( mp ( i , j )) ;  

}

   ll ans = 0 ; 
   
   int si = p.size() ; //cout<<si<<endl  ;

   int k = 0 ; 
    f ( k , 0 , si -1 )
   {  temp = 0 ;     dfs(p[k].F , 0 , p[k].S ) ; int a1 = temp ; 
        temp = 0 ;   dfs( p[k].S  , 0 , p[k].F) ; int a2 = temp ;   
         int c = a1+a2 ;
if(c!=0) ans+=  c+2 ;  
   }
if(si==0)
{ ll maxa = - 1; 
 f ( i ,1, n )  { temp = 0 ; dfs2(i , 0  , i ) ; 
 if(temp>maxa) maxa = temp ; //cout<<temp<<" "<<i<<endl ;
 }
 ans+= maxa ; ans++ ; 

}  
      printf("Case #%d: " , T-t ) ; 
   
     cout<<ans<<endl ; 
}
     
 }




