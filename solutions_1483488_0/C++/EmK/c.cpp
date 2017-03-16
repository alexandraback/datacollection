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

char buf[111];

int solve(int x , int B){
  sprintf(buf , "%d" , x);
  string s(buf);
  set<int> se;
  FOR(_,10){
    int p = atoi(s.c_str());
    if(se.count(p)) break;
    if(p > x && p <= B) se.insert(p);
    rotate(s.begin() , s.begin()+1 , s.end());
  }
  return (int)se.size();
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    ll_t ans = 0;
    int A,B;
    cin>>A>>B;
    for(int i=A;i<=B;i++){
      ans += solve(i , B);
    }
    printf("Case #%d: %I64d\n" , case_no++ , ans);
  }
  return 0 ;
}
