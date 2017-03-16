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
string x = 
"ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv" ;
string y = 
"our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up" ;
map < char , char >  mp; 
void init () {
    for(int i=0 ; i < LEN(x) ; ++i){
        mp[ x[ i ] ] = y[i] ;  
    }
    
    /*for( map<char,char>::iterator it = mp.begin() ; it != mp.end(); ++it){ 
        cout << it->first <<" "<< it->second << endl; 
    }*/
    mp['q']='z';
    mp['z']='q';
}
char ss[1000000]; 
int main (){  
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout); 
   init () ; 
   int T ; 
   cin >> T ; 
   gets(ss) ; 
   for(int Case = 1;  Case <=  T ; ++Case){
       gets(ss) ;  
       string s = string(ss) ; 
       for(int i=0; i < LEN(s) ;++i){ 
           s[i] =mp[s[i]] ;
       } 
       cout <<"Case #"<<Case <<": " ;
       cout << s << endl; 
    }
      
   return 0; 
}
 
