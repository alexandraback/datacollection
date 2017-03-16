#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define LL long long
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FOR(i,a,n) for(int (i)=(int)(a);i<(int)(n);++(i))
#define FORR(i,a,n) for(int (i)=(int)(a);i>(int)(n);--(i))

using namespace std;

long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
long long bits(long long a){return a?1+bits(a&(a-1)):0;};
long long pot(long long a,long long b){if(!b)return 1;if(b&1)return a*pot(a*a,b>>1); else return pot(a*a,b>>1);}

double v[500];

int main(){
 //freopen(".in","r",stdin);
 //freopen(".out","w",stdout);
 int tc , n ;
 double sum ;
 scanf("%d",&tc);
 FOR(i,0,tc){
   scanf("%d",&n) ;
   sum = 0 ;
   FOR(j,0,n) scanf("%lf",v+j) , sum += v[j];
   printf("Case #%d:",i+1);
   FOR(j,0,n){
     double lo = 0.0 , hi = 100.0000001;     
     FOR(i,0,200){
        double mid = ( lo + hi )  / 2.0 ; 
        double prom = mid ;
        double puntaje = v[j] + sum * mid / 100.0; 
        bool stw = false ;
        FOR(k,0,n)if(k!=j){
            double P = ( puntaje - v[k] ) / sum  * 100.0; 
            if( P < 0.0 ) continue ;
            stw = true;
            prom +=P ;
        }
        if( prom < 100.0 || !stw ) // los demas pueden ser mayores
           lo = mid ;
        else // no sera eliminado 
           hi = mid  ;
        
     }
     printf(" %.6lf",lo );
   }
   printf("\n");
 }
 return 0;
}
