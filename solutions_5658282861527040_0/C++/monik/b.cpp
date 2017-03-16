#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

using namespace std;

int T;
long long A,B,K;
long long sum = 0;

int main(void) {
  cin >> T;
  REP(t,T) {
    sum = 0;
    cin >> A >> B >> K;
    for(long long a = 0; a < A; ++a) {
      for(long long b = 0; b < B; ++b) {
        if ((a & b) < K) {
          ++sum;
        }
      }
    }
    cout << "Case #" << t + 1 << ": " << sum << endl;
  }
  return 0;
}
