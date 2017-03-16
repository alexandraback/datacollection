#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REPI(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

// insert other library code here...

// #define MAXN
int b;
ll m;

ll recursive(int s[60][60], int n) {
  if (n == b - 1) return 1ll;

  ll sum = 0;
  for (int i = n + 1; i < b; i++) {
    if (s[n][i] == 1)
      sum += recursive(s, i);
  }
  return sum;
}

ll count_ways(int s[60][60])
{
  return recursive(s, 0);
}

void solve()
{
  int s[60][60];
  REPI(i, b) REPI(j, b) s[i][j] = 0;
  
  if (m < b) {
    REPI(i, m) {
      s[0][i + 1] = 1;
      if (i + 1 != b - 1) s[i + 1][b - 1] = 1; 
    }
    printf("POSSIBLE\n");
    REPI(i, b) {
      REPI(j, b) printf("%d", s[i][j]);
      puts("");
    }
    return;
    
  } else { // m >= b, try:

    REPI(i, b) {
      if (i == 0) continue;
      s[0][i] = 1;
      if (i != b - 1) s[i][b - 1] = 1; 
    }
    REPI(r, 128) {
      int bit_pos = 0;
      for (int i = 1; i < b - 2; i++) {
        for (int j = i + 1; j < b - 1; j++) {
          s[i][j] = (r >> bit_pos) & 0x01;
          bit_pos++;
        }
      }
      ll ways = count_ways(s);
      if (ways == m) {
        printf("POSSIBLE\n");
        REPI(i, b) {
          REPI(j, b) printf("%d", s[i][j]);
          puts("");
        }
        return;
      }
    }
    puts("IMPOSSIBLE");
  }
  
}

int main(int argc, char* argv[])
{
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);

  int T = 0;
  scanf("%d", &T);
  for(int testcase = 1; testcase <= T; testcase++) {
    ll begin_clock = (ll)clock();
    // *** input data starts ***
    scanf("%d %lld", &b, &m);
    // *** input data ends ***
    if (testcase < TEST_FROM || testcase > TEST_TO) {
      continue;
    }
    
    printf("Case #%d: ", testcase);
    fflush(stdout);
    
    // *** solution starts ***
    solve();
    // *** solution ends ***
    
    fflush(stdout);
    fprintf(stderr, "\x1b[1;33;40m test %d solved, time = %lld clocks.\x1b[m\n", testcase, (ll)(clock() - begin_clock));
  }
  return 0;
}
