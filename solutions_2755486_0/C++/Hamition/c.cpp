#include <iostream> 
#include <map> 
#include <vector> 
#include <string> 
#include <set> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <queue> 
#include <list> 
#include <limits> 
#include <stack> 
#include <sstream> 
#include <fstream> 
#include <ctime> 
#include <cstdlib> 
#include <complex> 
#include <cctype> 
#include <iomanip> 
#include <functional> 
#include <cstring> 
using namespace std; 
 
typedef long long int64 ; 
typedef unsigned long long uint64 ; 
 
#define two(X) (1<<(X))  
#define twoL(X) (((int64)(1))<<(X)) 
#define PB push_back 
#define SZ(X) ((int)(X.size())) 
#define LEN(X) ((int)(X.length())) 

void open(){
    freopen( "c.in" , "r", stdin);
    freopen( "c.out", "w", stdout);
}
const int maxn = 1000000+ 10;  

int tree[ maxn  << 3 ] ;
int cover[ maxn << 3 ] ; 

#define L(x) ((x)<<1)
#define R(x) (L(x)+1)

//yep
void build( int rt, int l, int r ){ 
    if( l == r ){ 
         tree[ rt ] = 0 ; 
         cover[rt]= 0 ;
         return ;
    }

    int mid = ( l + r ) >> 1 ;   
    build( L(rt) , l , mid) ; 
    build( R(rt) , mid + 1, r ) ;  
    tree[rt] = 0 ;
    cover[rt]=0; 
}

void push_down( int rt, int l, int r ){ 
    if( l == r){ 
        tree[rt] = max( cover[rt],tree[rt]) ; 
        cover[rt] =0 ; 
        return ;
    }
   
    tree[ L(rt)] = max( cover[rt], tree[L(rt)] ) ; 
    cover[L(rt) ] = max( cover[L(rt)], cover[rt])  ;  

    tree[ R(rt)] = max( cover[rt], tree[R(rt)] ) ;
    cover[ R(rt) ] = max( cover[R(rt) ], cover[rt] ) ;

    tree[rt] = max( cover[rt], tree[rt]) ; 
    cover[rt] = 0 ;
      
}
int ask(int rt ,int l, int r, int ll, int rr){
    if( cover[rt] ) push_down(rt, l,r) ;

    if( l <= ll && r >= rr ){ 
        return tree[rt];  
    }
   // if( cover[ rt ] )
       // push_down(rt, l , r );  
    int mid = ( l + r ) >> 1; 
    int ans = 10000000;  
    if( ll <= mid ) {
      ans =min(ans,  ask(L(rt), l, mid, ll, rr )) ; 
    }
    if( rr > mid ){
        ans = min( ans , ask(R(rt), mid+ 1, r ,ll, rr)) ; 
    }
    return ans ;
}

void up(int rt, int l, int r , int ll, int rr,int val ){ 
    if( cover[rt] ) push_down(rt,l,r) ; 
    if( l <= ll && r >= rr ){ 
        cover[ rt ] =  val  ;  
        tree[rt] = max( tree[rt], val) ;
        return ;
    }
     

    int mid = ( l + r )>> 1;  
    if( ll <= mid ){ 
        up( L(rt), l , mid, ll, rr, val) ;
    }
    if( rr > mid ){ 
        up( R(rt), mid+ 1,r , ll, rr, val) ; 
    }
    tree[ rt ] = min( tree[L(rt)] , tree[R(rt)]);  
}

int N  ; 

struct event{ 
    int d,  w , e , s; 
    event() {} ;  
    event(int _d, int _w, int _e, int _s):d(_d),w(_w),e(_e), s(_s){} ; 

}  ; 

bool cmp( const event & x, const event & y){ 
    return x.d < y.d ; 
}

int main (){
    
 open() ; 
    int T ; 
    cin >> T ;
    for(int Cas = 1 ; Cas <= T ; ++Cas){     
      cin >> N ;
      vector< event > evt; 
      vector< int > pos ;
      map< int ,int > mp  ; 
      for(int i=1; i <= N ; ++i){ 
          int d , n , w , e , s , dd ,dp , ds ;   
          cin >> d >> n >> w >> e >> s >> dd >> dp >> ds ;  
          
          for(int i=1 ; i <= n ; ++i){
                evt.push_back( event( d , w ,e , s ) ) ; 
                d += dd ;  
                pos.push_back(w) ;
                pos.push_back(e) ;
                e += dp ;
                w += dp ; 
                s += ds;
          }
      }
      
     // cout << SZ(pos) << endl; 
      sort( pos.begin() , pos.end()) ; 

      pos.erase( unique( pos.begin(), pos.end()), pos.end()) ; 

      sort( evt.begin() , evt.end(), cmp ) ; 
     // cout << SZ(evt) << endl; 
      for(int i=0 ; i < SZ(pos) ;++i){
           mp[ pos[i]] = 1 + i ; 
      }
      N = SZ(pos) ; 

      build( 1, 1 ,N ) ;  

      int ans = 0  ;  
  
        
      for(int i= 0 ; i <SZ(evt) ; ++i){ 
           int d = evt[i].d ;
           int end = i ;
          
           for(end =i+1 ; end <SZ(evt) ; ++end){ 
               if( evt[end].d != evt[i].d ) break ;  
           }
           --end ; 

           for(int j = i ; j <= end ; ++j){
//             cout << ask( 1, 1, N , mp[evt[j].w], mp[evt[j].e] ) << endl;   
               ans += (ask( 1, 1, N , mp[ evt[j].w ], mp[evt[j].e] ) < 
                   evt[i].s) ; 
           }
           for(int j= i ; j <= end ; ++j){ 
               up( 1, 1 , N , mp[ evt[j].w ], mp[evt[j].e], evt[j].s )  ; 
           }
           i= end;
           //cout << d << " "<< ans <<endl; 
      }
      cout << "Case #"<<Cas <<": "<< ans << endl ;  
    }
    return 0; 
}



                 


