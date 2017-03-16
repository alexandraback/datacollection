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
char s[2010];
// #define MAXN

void solve()
{
  int alphabet[26];
  int count[10];
  REPI(i, 26) alphabet[i] = 0;
  REPI(i, 10) count[i] = 0;
  
  int len = strlen(s);
  REPI(i, len) alphabet[s[i] - 'A']++;
  
  // zero
  count[0] = alphabet['Z' - 'A'];
  alphabet['Z' - 'A'] -= count[0];
  alphabet['E' - 'A'] -= count[0];
  alphabet['R' - 'A'] -= count[0];
  alphabet['O' - 'A'] -= count[0];  
  
  // two
  count[2] = alphabet['W' - 'A'];
  alphabet['T' - 'A'] -= count[2];
  alphabet['W' - 'A'] -= count[2];
  alphabet['O' - 'A'] -= count[2];
  
  // four
  count[4] = alphabet['U' - 'A'];
  alphabet['F' - 'A'] -= count[4];
  alphabet['O' - 'A'] -= count[4];
  alphabet['U' - 'A'] -= count[4];
  alphabet['R' - 'A'] -= count[4];

  // six
  count[6] = alphabet['X' - 'A'];
  alphabet['S' - 'A'] -= count[6];
  alphabet['I' - 'A'] -= count[6];
  alphabet['X' - 'A'] -= count[6];

  // one
  count[1] = alphabet['O' - 'A'];
  alphabet['O' - 'A'] -= count[1];
  alphabet['N' - 'A'] -= count[1];
  alphabet['E' - 'A'] -= count[1];
  
  // three 
  count[3] = alphabet['R' - 'A'];
  alphabet['T' - 'A'] -= count[3];
  alphabet['H' - 'A'] -= count[3];
  alphabet['R' - 'A'] -= count[3];
  alphabet['E' - 'A'] -= count[3];
  alphabet['E' - 'A'] -= count[3];
  
  // eight
  count[8] = alphabet['H' - 'A'];
  alphabet['E' - 'A'] -= count[8];
  alphabet['I' - 'A'] -= count[8];
  alphabet['G' - 'A'] -= count[8];
  alphabet['H' - 'A'] -= count[8];
  alphabet['T' - 'A'] -= count[8];
  
  // five, seven, , nine
  count[5] = alphabet['F' - 'A'];
  alphabet['F' - 'A'] -= count[5];
  alphabet['I' - 'A'] -= count[5];
  alphabet['V' - 'A'] -= count[5];
  alphabet['E' - 'A'] -= count[5];
  
  count[7] = alphabet['V' - 'A'];
  alphabet['S' - 'A'] -= count[7];
  alphabet['E' - 'A'] -= count[7];
  alphabet['V' - 'A'] -= count[7];
  alphabet['E' - 'A'] -= count[7];
  alphabet['N' - 'A'] -= count[7];
  
  count[9] = alphabet['I' - 'A'];
  
  REPI(i, 10) REPI(j, count[i]) printf("%d", i);
  printf("\n");
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
    
    scanf("%s", s);
    
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
