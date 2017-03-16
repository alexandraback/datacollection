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
#include <cassert>
using namespace std; 
 
typedef long long int64 ; 
typedef unsigned long long uint64 ; 
 
#define two(X) (1<<(X))  
#define twoL(X) (((int64)(1))<<(X)) 
#define PB push_back 
#define SZ(X) ((int)(X.size())) 
#define LEN(X) ((int)(X.length())) 
#define MP(X,Y) make_pair(X,Y)  
#define F first
#define S second
#define foreach(c , itr) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
#define INPUT(s) freopen(s,"r",stdin) ;
#define OUTPUT(s) freopen(s,"w",stdout) ; 
inline int  lowbit(int n) { return n&(-n) ;} 

set<int> se ;  
int x[1000+10], y[1000+10];  
int usedx[1000+10], usedy[1000+10]; 
int n;   
int main (){  
    INPUT("a.in") ; 
    //OUTPUT("a.out") ; 
    int T  ;  
    scanf ("%d",&T) ; 
    for( int Cas = 1 ; Cas <= T; ++Cas ){ 
       se.clear () ;
       scanf ("%d", &n) ;
       memset(usedx,0,sizeof(usedx)) ; 
       memset(usedy,0,sizeof(usedy)) ;
       for(int i=1; i <= n ; ++i){ 
           scanf ("%d%d", x + i , y + i) ; 
           se.insert(i) ; 
       } 
       int now =0, ans = 0; 
       while(SZ(se)){  
           bool can = 0 ; 
           int pos =-1 ;
           foreach( se, it ){ 
               int t = *it ; 
               if( now <  y[t] )  continue ;  
               can = 1  ;   
               se.erase(it) ;  
               pos = t ;   
               break ; 
           }  

           if(can){ 
               now += ( usedx[pos] ==1 ?1 : 2)  ;   
               ++ans ; 
               continue ; 
           }  
           foreach( se, it ){ 
               int t = *it ; 
               if( usedx[*it] ) continue ; 
               if( now < x[ *it ] ) continue ;  
               if( pos == -1 ||(  y[ pos ] <  y[ t]||  y [pos] == y[t] && x[t] < x[pos] ) ){ 
                   pos =t ; 
                   can = 1; 
               }
           }
       //    cout << pos << endl ;
           if(!can) break ;  
           else{ 
               usedx[pos]=1; 
               ++ans ;
               ++now ;
           }
          
       } 
       cout << "Case #"<<Cas <<": " ; 
       if(SZ(se)){  
           puts("Too Bad") ; 
       }else{ 
           cout<< ans << endl ;
       } 
    }
    return 0; 
}

               
            

      
