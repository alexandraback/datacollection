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
char C[20], J[20];

void fill_equal(int pos, int len)
{
  for (int i = 0; i < len; i++) {
    if (C[pos + i] == '?' && J[pos + i] == '?') {
      C[pos + i] = J[pos + i] = '0';
    } else if (C[pos + i] == '?') {
      C[pos + i] = J[pos + i];
    } else if (J[pos + i] == '?') {
      J[pos + i] = C[pos + i];
    }
  }
}

void minimize(int pos, int len, char *A)
{
  for (int i = 0; i < len; i++) 
    if (A[pos + i] == '?') A[pos + i] = '0';
}

void maximize(int pos, int len, char *A)
{
  for (int i = 0; i < len; i++) 
    if (A[pos + i] == '?') A[pos + i] = '9';
}

void solve()
{
  int len = strlen(C);
  int pivot = -1;
  int compare = 0;
  REPI(i, len) if (C[i] != '?' && J[i] != '?' && C[i] != J[i]) { 
    pivot = i;
    compare = C[i] > J[i] ? 1 : -1;
    break;
  }
  
  if (pivot == -1) { // equal
    fill_equal(0, len);
  } else { // not equal, minimize
    if (abs(C[pivot] - J[pivot]) < 5) { // natural ordering
      fill_equal(0, pivot);
      minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
      maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
    } else if (abs(C[pivot] - J[pivot]) > 5) { // maybe reverse ordering
      bool r = false;
      for (int i = pivot - 1; i >= 0; i--) {
        if (C[i] != '?' && J[i] != '?') continue;
        if (C[i] == '?' && J[i] == '?') { // simple
          C[i] = (C[pivot] > J[pivot] ? '0' : '1');
          J[i] = (C[pivot] > J[pivot] ? '1' : '0');
          fill_equal(0, i);
          maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
          minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
          r = true;
          break;
        }
        
        if (C[i] == '?') {
          if (C[pivot] > J[pivot] && J[i] > '0') {
            C[i] = J[i] - 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } else if (C[pivot] < J[pivot] && J[i] < '9') {
            C[i] = J[i] + 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } 
        } 
        
        if (J[i] == '?') {
          if (J[pivot] > C[pivot] && C[i] > '0') {
            J[i] = C[i] - 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } else if (J[pivot] < C[pivot] && C[i] < '9') {
            J[i] = C[i] + 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } 
        } 
      }
      if (!r) {
        fill_equal(0, pivot);
        maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
        minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
      }
    } else { // equal 5
      int mivot = -1;
      for (int i = pivot + 1; i < len; i++) {
        if (C[i] == '?' || J[i] == '?') continue;
        if (C[i] != J[i]) {
          mivot = i;
          break;
        }
      }
      if (mivot == -1) {
        fill_equal(0, len);
      } else if ((C[pivot] > J[pivot] && C[mivot] > J[mivot]) || 
                 (C[pivot] < J[pivot] && C[mivot] < J[mivot])) { 
                   
        // paste
        bool r = false;
      for (int i = pivot - 1; i >= 0; i--) {
        if (C[i] != '?' && J[i] != '?') continue;
        if (C[i] == '?' && J[i] == '?') { // simple
          C[i] = (C[pivot] > J[pivot] ? '0' : '1');
          J[i] = (C[pivot] > J[pivot] ? '1' : '0');
          fill_equal(0, i);
          maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
          minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
          r = true;
          break;
        }
        
        if (C[i] == '?') {
          if (C[pivot] > J[pivot] && J[i] > '0') {
            C[i] = J[i] - 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } else if (C[pivot] < J[pivot] && J[i] < '9') {
            C[i] = J[i] + 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } 
        } 
        
        if (J[i] == '?') {
          if (J[pivot] > C[pivot] && C[i] > '0') {
            J[i] = C[i] - 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } else if (J[pivot] < C[pivot] && C[i] < '9') {
            J[i] = C[i] + 1;
            fill_equal(0, i);
            maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
            minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
            r = true;
            break;
          } 
        } 
      }
      if (!r) {
        fill_equal(0, pivot);
        maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
        minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
      }
        // end
      } else { // 
        // fprintf(stderr, "(%d)", pivot);
        fill_equal(0, pivot);
        minimize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? C : J);
        maximize(pivot + 1, len - pivot, C[pivot] > J[pivot] ? J : C);
      }
    }
  }
  
  
  printf("%s %s\n", C, J);
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
    scanf("%s %s", C, J);
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
