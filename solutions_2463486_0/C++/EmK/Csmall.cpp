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


bool isPalindrome(int x)
{
  string s = format("%d",x);
  string rs = s;
  reverse(ALL(rs));
  return s == rs;
}

int solve()
{
  int A,B;
  cin>>A>>B;
  int ans = 0;
  for(int i=1;i*i<=B;i++){
    int i2 = i*i;
    if(A <= i2 && i2 <= B && isPalindrome(i) && isPalindrome(i2)) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    printf("Case #%d: %d\n" , case_no++ , solve());    
  }
  return 0 ;
}
