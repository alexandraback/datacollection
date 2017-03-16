/* Opgave: B */
// 7+8+7=22 includes
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPowerOfTwo(long long v) {
  return (v & (v - 1ll)) == 0ll;
}

int bitlen(long long v) {
  int ret = 0;
  while(v) {
    ++ret;
    v >>= 1;
  }
  return ret;
}


long long count2(long long A, long long B, long long K) {
  if(A == 0 || B == 0)
    return 0;
  if(A == 1)
    return B;
  if(B == 1)
    return A;
  assert(K >= 1);
  assert(A >= 1);
  assert(B >= 1);
  if (K >= A || K >= B)
    return A * B;
  if(K == 1)
    return 1;
  int Ab = bitlen(A - 1) - 1;
  int Bb = bitlen(B - 1) - 1;
  int Kb = bitlen(K - 1) - 1;
  if(Ab == Bb && Ab > Kb)
    
  if(Ab > Bb)
    return count2(A - (1ll << Ab), B, K);
  if(Bb > Ab)
    return count2(A, B - (1ll << Bb), K);
  long long ret = count2(A - (1ll << Kb), B - (1ll << Kb), K - (1ll << Kb));
  ret += A * B - ((A - (1ll << Kb)) * (B - (1ll << Kb)));
  return ret;
}

void testcase() {
  long long A, B , K;
  cin >> A >> B >> K;
  long long cnt = 0;
  for(int i = 0; i < A; ++i)
    for(int j = 0; j < B; ++j)
      if((i & j) < K)
	++cnt;
  cout << cnt << "\n";
}

int main () {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    testcase();
  }
	return 0;
}
/* Opgave: B */
