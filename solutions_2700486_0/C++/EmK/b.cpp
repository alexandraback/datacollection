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

double memo[1500][1500];

double dfs(int L, int R, int rem, int targetX)
{
  if(targetX <= L || R <= targetX) return 1.0;
  if(rem <= 0) return 0;
  double& ret = memo[-L][R];
  if(!isnan(ret)) return ret;
  double val = 0 ;

  if(L < -1 && 1 < R) {
    val = (dfs(L+1,R,rem-1,targetX) + dfs(L,R-1,rem-1,targetX)) / 2.0;
  }else if(L < -1){
    val = dfs(L+1,R,rem-1,targetX);
  }else if(1 < R){
    val = dfs(L,R-1,rem-1,targetX);
  }else{
    if(L==0 && R==0) cout<<"ERROR"<<endl;
    val = dfs(0,0,rem-1,targetX);
  }
  //cout<<" "<<L<<" "<<R<<" "<<rem<<" "<<targetX<<" "<<val<<endl;
  return ret = val;
}

double solve()
{
  int N,X,Y;
  cin>>N>>X>>Y;

  int R = N , L = -1;
  for(int i=0;;i++) {
    int x = i * 4 + 1; // 1,5,9,13...
    if(R >= x) {
      R -= x;
      L = x / 2 + 2;
    }else{
      break;
    }
  }

  int level = abs(X) + abs(Y);
  //cout<<R<<" "<<L<<" "<<level<<" "<<X<<endl;
  if(level < L) return 1.0;
  if(level > L) return 0.0;

  if(R==0) return 0.0;

  memset(memo , -1 , sizeof(memo));
  return dfs(-L-1,L+1,R,X);
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    printf("Case #%d: %.10f\n" , case_no++ , solve());
    
  }
  return 0 ;
}
