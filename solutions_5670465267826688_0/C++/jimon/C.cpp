// include {{{
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include <deque>
#include <stack>
#include <queue>
//#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <numeric>
//#include <complex>
// }}}
using namespace std;
// macro {{{
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0,__end=(n);i<__end;++i)
#define REP(i,j,k) for(int i=j,__end=(k);i<__end;++i)
//#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define priority_queue_greater(T) priority_queue< T, vector<T>, greater<T> >
#define F first
#define S second
// BEGIN CUT HERE {{{
// convert {{{
template<typename T> T fromString(string& s){
  T res;
  std::istringstream is(s);
  is >> res;
  return res;
}
template<typename T> string toString(T& v){
  stringstream ss;
  ss << v;
  return ss.str();
} // }}}
// inspect {{{
string inspect( string str );
string inspect( bool str );
template<typename T> string inspect( T v );
template<typename T,typename U> string inspect( pair<T,U> v );
template<typename T> string inspect( vector<T> v );
string inspect( string str ){
  return "\"" + str + "\"";
}
string inspect( bool flag ){
  return flag ? "True" : "False";
}
template<typename T> string inspect( T v ){
  return toString<T>( v );
}
template<typename T,typename U> string inspect( pair<T,U> v ){
  return "(" + inspect(v.first) + "," + inspect(v.second) + ")";
}
template<typename T> string inspect( vector<T> v ){
  string res = "[";
  rep(i,v.size()){
    if( i != 0 ){ res += ","; }
    res += inspect( v[i] );
  }
  return res + "]";
}
// }}}
// puts {{{
void puts() {};
template<class First, class... Rest>
void puts(const First& first, const Rest&... rest ){
  cout << inspect(first) << endl;
  puts(rest...);
}
// }}}
// END CUT HERE }}}
// }}}

int times;
ll L, X;
string str;

int main(){
  cin >> times;
  REP(t,1,times+1){
    cin >> L >> X;
    cin >> str;

    char now = str[0];
    bool neg = false;

    REP(i,1,L){
      switch (now) {
        case '1':
          now = str[i];
          break;
        case 'i':
          switch(str[i]){
            case '1':
              now = 'i';
              break;
            case 'i':
              now = '1';
              neg = !neg;
              break;
            case 'j':
              now = 'k';
              break;
            case 'k':
              now = 'j';
              neg = !neg;
              break;
          }
          break;
        case 'j':
          switch(str[i]){
            case '1':
              now = 'j';
              break;
            case 'i':
              now = 'k';
              neg = !neg;
              break;
            case 'j':
              now = '1';
              neg = !neg;
              break;
            case 'k':
              now = 'i';
              break;
          }
          break;
        case 'k':
          switch(str[i]){
            case '1':
              now = 'k';
              break;
            case 'i':
              now = 'j';
              break;
            case 'j':
              now = 'i';
              neg = !neg;
              break;
            case 'k':
              now = '1';
              neg = !neg;
              break;
          }
          break;
      }
    }

    //printf("%c ", now);
    //puts(neg);

    bool ans = false;
    bool isAllSame = true;
    REP(i,1,L)if(str[i-1] != str[i]){ isAllSame = false; }

    int cnt[] = {0,0,0};
    rep(i,L){ cnt[str[i] - 'i']++; }

    if(isAllSame){
    }else if((!cnt[0] || !cnt[1] || !cnt[2]) && X * L < 12){
    }else if(now == '1'){
      if(neg == true && (X % 2) == 1){ ans = true; }
    }else{
      if((X % 4) == 2){ ans = true; }
    }


    cout << "Case #" << t << ": " << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}


