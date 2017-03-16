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

ll_t solve()
{
  ll_t E,R,N;
  cin>>E>>R>>N;
  VI v(N);
  FOR(i,N) cin>>v[i];

  ll_t ans = 0 ;

  VI energy(N, E);
  VI used(N);
  FOR(_,N) {
    int maxValue = -1 , maxIndex = -1;
    FOR(j, N) {
      if(used[j]) continue;
      if(maxValue < v[j]) {
        maxValue = v[j];
        maxIndex = j ;
      }
    }
    if(maxIndex == -1) break;

    ll_t useEnergy = energy[maxIndex];

    for(int j=maxIndex+1;j<N;j++) {
      ll_t newE = (j - maxIndex) * R;
      if(newE >= E) break;
      if(used[j] && (energy[j] - newE) > 0) {
        useEnergy = min(useEnergy, energy[maxIndex] - (energy[j] - newE));
      }
    }

    if(useEnergy < 0) useEnergy = 0 ;

    ans += useEnergy * v[maxIndex];
    used[maxIndex]=true;
    //cout<<maxIndex<<" "<<useEnergy<<endl;

    for(int j=maxIndex+1;j<N;j++) {
      ll_t newE = energy[maxIndex] - useEnergy + (j - maxIndex) * R;
      if(newE >= E) break;
      energy[j] = min(E, newE);
    }
  }

  return ans;
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
