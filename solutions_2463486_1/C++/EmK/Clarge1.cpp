// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdarg>
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

string format(const char* format, ...)
{
  char buf[10000];
  va_list ap;
  va_start(ap, format);
  vsprintf(buf, format, ap);
  va_end(ap);
  return buf;
}

bool isPalindrome(ll_t x)
{
  string s = format("%lld",x);
  for(int i=0,j=SZ(s)-1;i<=j;i++,j--) {
    if(s[i] != s[j]) return false;
  }
  return true;
}

vector<long long> fairAndSquares;

void initFairAndSquareNumbers()
{
  const ll_t MAX = 100000000000000LL + 10;
  for(ll_t i=1;i*i<=MAX;i++){
    ll_t i2 = i*i;
    if(isPalindrome(i) && isPalindrome(i2)) {
      fairAndSquares.push_back(i2);
    }
  }
}

ll_t solve()
{
  ll_t A,B;
  cin>>A>>B;

  vector<long long>::iterator p1,p2;

  p1 = lower_bound(ALL(fairAndSquares), A);
  p2 = lower_bound(ALL(fairAndSquares), B + 1);

  return p2 - p1;
}

int main() {
  int t,case_no=1;
  initFairAndSquareNumbers();
  cin>>t;
  while(t--){
    printf("Case #%d: %lld\n" , case_no++ , solve());    
  }
  return 0 ;
}
