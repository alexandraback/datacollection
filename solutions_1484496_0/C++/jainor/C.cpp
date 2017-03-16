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

int n ;
int num[600];
int sum[600];
int maxsum = 0 ;

int X[600];
vector<int> ans[2];

int L = 0 ;
bool F2( int k ){
 FOR(j,0,2){
   X[k] = j;
   ans[j].pb( num[k]) ;
   sum[j] += num[k];
   if( sum[j] <= maxsum / 2 ){        
           if( k + 1 < n && F2( k + 1 ) )
           {  L = k + 1; return true;}
           else if( sum[0] == sum[1] )
            { L = k ;   return true;}
   }
   sum[j] -=  num[k] ;// quito :S 
   ans[j].erase(ans[j].end()-1); 
 }
 return false;
}

int main(){
 //freopen(".in","r",stdin);
 //freopen(".out","w",stdout);
 int tc;
 cin >> tc;
 FOR(i,0,tc){
   cin >>n ;
   ans[0].clear();ans[1].clear();
   maxsum = 0 ;
   FOR(j,0,n) cin >>num[j] , maxsum += num[j];
   cout <<"Case #"<<i+1<<":"<<endl;
   
   F2(0);
   FOR(j,0,ans[0].sz ) { if(j) cout <<' '; cout << ans[0][j];}
   cout <<endl;
   FOR(j,0,ans[1].sz ) { if(j) cout <<' '; cout << ans[1][j];}
   cout <<endl;
 }
 return 0;
}
