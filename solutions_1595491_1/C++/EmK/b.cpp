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



int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    int N,S,p;
    cin>>N>>S>>p;
    int ans = 0 ;
    FOR(i,N){
      int t;
      cin>>t;
      int a1,a2,a3;
      a1 = a2 = a3 = t / 3;
      if(t%3 >= 1) a1++;
      if(t%3 >= 2) a2++;
      if(a1 >= p) ans++;
      else if(S>0) {
        if(a1 == a2 && a1 > 0 && a1 <= 9 && a1 + 1 >= p) {
          S--; ans++;
          a1++ ; a2--;
        } 
      }
    }
    printf("Case #%d: %d\n" , case_no++ , ans);
  }
  return 0 ;
}
