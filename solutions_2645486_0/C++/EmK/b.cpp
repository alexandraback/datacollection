// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

const double PI = 4.0*atan(1.0);

ll_t memo[55][55];

ll_t dfs(VI& v, int E, int R , int current, int pos)
{
  if(pos == SZ(v)) {
    return 0 ;
  }
  ll_t& ret = memo[current][pos];
  if(ret != -1) return ret;
  ll_t val = 0 ;
  for(int i=0;i<=current;i++) {
    val = max(val , dfs(v,E,R,min(E,current-i+R),pos+1) + 1LL* i * v[pos]);
  }
  return ret = val;
}

ll_t solve()
{
  ll_t E,R,N;
  cin>>E>>R>>N;
  VI v(N);
  FOR(i,N) cin>>v[i];
  memset(memo , -1 , sizeof(memo));
  return dfs(v , E, R , E , 0);
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    ll_t ans = solve() ;
    printf("Case #%d: %lld\n" , case_no++ , ans);
    
  }
  return 0 ;
}
