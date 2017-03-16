#include <iostream> 
#include <map> 
#include <vector> 
#include <cassert>
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

inline void open_file(){
    freopen("c.in", "r",stdin) ; 
    freopen("c.out", "w",stdout) ; 
}

const int maxn = 10000+10;  
vector< string > vc ;
map< string ,bool> mp ;   
void init(){ 
    vc.clear(); 
    FILE *fp = fopen("dic.txt", "r") ;
    char ss[100] ; 
    int bd= 0  ;
    while( fscanf (fp, "%s", ss) ==1){ 
        string s = string(ss) ;
        if( s =="code"){
    //        cout <<"FUCK"<<endl;
        }

        bd = max( bd , SZ(s) ) ;
        mp[s] =1 ; 
        vc.push_back(s) ; 
    }
   // cout << bd << endl;
    fclose(fp);
   // cout << mp["code"] << endl ;
   // cout << mp["jam"]<<endl;
}
const int oo = 0x3f3f3f3f;  
int dp[ maxn ][ 6 ] ; 

void gao( int x , int y, string s){
    
    if( mp.find(s) != mp.end()){ 
        int ty = min( 4 , y +  LEN(s)) ; 
        int & res=  dp[x + LEN(s)][ty] ;
        res = min( res, dp[x][y] ) ; 
        return;
    }
    int tt = LEN(s) ; 
    int start = max( 0 , 4-y); 
    bool f= 0; 
    for(int i = start ; i <min(tt, LEN(s)) ; ++i){
        char tmp=s[i]; 
        for(char c = 'a' ; c <='z' ; c++){ 
            if( tmp == c ) continue ;  
            s[i]=c ;  
            if( mp.find(s) == mp.end()){
               // s[i]=tmp;
                continue ;
            }
            
            int ty = min( 4 , LEN(s)-1-i) ;  
            int & res = dp[x + LEN(s)][ ty ];  
            res =min(res, dp[x][y] + 1 ) ; 
            tt = min( tt , x+LEN(s)- ty ) ; 
            f=1; 
            break; 
           // return; 
        }
        s[i]=tmp; 
        if(f) break;  
    }
    bool f1=0, f2=0 ;
    //int tt = LEN(s) ; 
    for(int i= start; i < min(tt,LEN(s)) ; ++i){ 
        char tmpi=s[i];
        for( char c1 = 'a' ; c1 <='z'; c1++){
            if( c1 == tmpi ) continue ; 
            s[i]= c1 ; 
            f2=0; 
            for(int j= i + 5 ; j <min(tt, LEN(s)) ; ++j){  
                char tmpj = s[j]; 
                for(int c2 ='a'; c2 <='z'; ++c2){  
                    if( c2 == tmpj ) continue ;  
                    s[j] = c2 ;
                    if( mp.find(s) !=mp.end()){  
                        int tx = x + LEN(s) , ty =
                            min(4, LEN(s) -1 -j) ; 
                        dp[tx][ty] = min( dp[tx][ty], dp[x][y]+2);
                        f2=1; 
                        tt = min( tt ,tx - ty) ;
                        break; 
                    }
                }
                
                s[j]= tmpj;
                if(f2) break; 
            }
        }
        s[i]=tmpi ; 
    }
}
int main (){ 
    init() ; 
    int T ;
    open_file() ; 
    cin >> T ; 
    //memset( dp , 0x3f , sizeof( dp)) ;
   
    for(int Cas = 1 ; Cas <= T ; ++Cas){
       string s ; 
       cin >> s ;   
       s = "0"+s;
       memset(dp, 0x3f, sizeof(dp)) ; 
       dp[0][4]=0 ;
       
       for(int i=0; i < SZ(s)-1; ++i){ 
           for(int j=0; j <= 4 ; ++j){
                if( dp[i][j] == oo ) continue ; 
                for(int k=1; k <= 11; ++k){ 
                    if( i+1 + k > SZ(s) ) break ;  
                    string tmp = s.substr( i+1 , k) ; 
                    gao( i , j, tmp) ; 
                }
           }
       }
       int ans = oo ; 
       for(int i=0 ; i <SZ(s); ++i){
           for(int j=0; j <=4 ; ++j){ 
       //        cout << dp[i][j] <<" "; 
           }
         //  cout << endl; 
       }

       for(int i=0 ; i <= 4 ; ++i){
           ans = min( ans , dp[SZ(s)-1][i]) ; 
       }
       cout <<"Case #"<<Cas<<": "<< ans <<endl; 
    }
    return 0; 
}
    
