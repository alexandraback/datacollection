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
#define MP(X,Y) make_pair(X,Y)  
#define CLR(que)   while(!que.empty()) que.pop()  
#define CA(a, m, n) for(int ii=0; ii<m; ++ii){  for(int jj=0;  jj<n; ++jj)   cout<<a[ii][jj]<<" " ; puts("")  ;} 
 
inline int  lowbit(int n) { return n&(-n) ;} 

string apart(int x){
    if(x == 0 ) return "0"; 
    string res = "" ;
    for(; x ; x/=10){
        res += (char) ( x%10 +'0') ; 
    }
    reverse( res.begin(), res.end());
    return res;
}
int64 init(int a, int b){   
    int64 res = 0 ; 
    string m = apart(a) ; 
    for( int i= a ; i <= b ; ++i){ 
        string s = apart(i); 
        //cout << s << endl;  
        string t= s; 
        s += s ;
        set<string> se; 
        for(int j=0;  j < LEN(t); ++j){
            string tmp = s.substr(j,LEN(t)) ;
            if( tmp[0] !='0' && ( LEN(tmp) > LEN( m ) || tmp >= m   ) &&  tmp <  t ){ 
              se.insert(tmp) ; 
            }
        }
        res+= se.size() ;
    }
    return res ;
}

int main () { 
    /*freopen("in.ixt","w",stdout);
    cout << 50 << endl; 
    for(int i=0; i < 50; ++i){
        cout << 1 <<" "<<2000000 << endl; 
    }
    return 0; */
    freopen("in.txt","r",stdin) ;
    freopen("out.txt","w",stdout); 
    int T ;
    cin >> T ; 
    for(int Cas = 1 ; Cas <= T; ++Cas){
        int a , b ;  
        cin >> a >> b ;
        cout <<"Case #"<<Cas<<": "<< init(a,b) << endl; 
    }
    return 0; 
}



