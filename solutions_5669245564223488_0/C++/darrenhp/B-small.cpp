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

int N;
vector<string> strs; 
bool used[32];
bool valid(string s){
  memset(used, 0, sizeof(used));
  for (size_t i = 0; i < s.size(); i++){
    if (i == 0 || s[i] != s[i - 1]){
      if (used[s[i] - 'a'])return false;
      used[s[i] - 'a'] = true;
    }
  }
  return true;
}

i64 solve(){
  vector<int> a;
  for (int i = 0; i < N; i++) a.push_back(i);
  i64 tot = 0;
  do{
    string s;
    for (int i = 0; i < N; i++) s += strs[a[i]];
    if (valid(s)) tot++;
  }while (next_permutation(a.begin(), a.end()));
  return tot;
}
string Trim(string s){
  string t;
  for (size_t i = 0; i < s.size(); i++){
    if (i == 0 || s[i] != s[i - 1]) t += s[i];
  }
  return t;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    cin >> N; 
    strs.resize(N);
    for (auto &s: strs) cin >> s;
    for (auto &s: strs) s = Trim(s);
    cout << "Case #" << ++TestNum << ": " << solve() << endl;
  }
}

