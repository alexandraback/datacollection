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

int T ; 
int A,B ; 
double p[1000000+10] ; 
double pp[1000000+100]; 
double sum[1000000+100];
void cal( ){  
    pp[0]=1;
    for(int i=1; i<=A; ++i){ 
        pp[i]=pp[i-1]*p[i];
    }
}
    
    
int main (){
    INPUT("a.in") ;
    OUTPUT("a.out") ; 
    cin >> T ; 
    for(int Cas =  1 ; Cas <= T; ++Cas ) { 
        cin >> A >> B ; 
        for(int i=1; i <= A ; ++i){ 
            scanf ("%lf", p + i ) ; 
        }
        cal() ; 
        double ans = (double) 1000000000000. ; 
        
        for(int x= A; x >=0 ; --x){ 
            ans =min(ans, pp[x]*( 2*(A-x)+B-A+1) + (1-pp[x])*(2*(A-x)+B-A+B+2)) ;
        } 
        ans = min(ans , B+2.) ; 
        cout<<"Case #"<<Cas <<": " ; 
        printf ("%.6lf\n",ans) ; 
    }
    return 0; 
}
        


    
