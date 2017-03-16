//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
i64 gcd(i64 a, i64 b){
  return b == 0? a: gcd(b, a % b);
}

i64 solve(i64 P, i64 Q){
  i64 g = gcd(P, Q);
  P /= g, Q /= g;
  //cout << P << ", " << Q << endl;
  if (__builtin_popcountll(Q) != 1) return -1; 
  int cnt = 0;
  while (P < Q) P *= 2, cnt++;
  return cnt;
}
i64 getI64(string s){
  istringstream iss(s);
  i64 n; iss >> n;
  return n;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    string s; cin >> s;
    i64 P, Q;  
    P = getI64(s.substr(0, s.find("/"))); 
    Q = getI64(s.substr(s.find("/") + 1));
    i64 ans = solve(P, Q);
    cout << "Case #" << ++TestNum << ": ";
    if (ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;
  }
}

