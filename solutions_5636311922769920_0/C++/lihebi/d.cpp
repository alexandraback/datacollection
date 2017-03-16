#include <iostream>
#include <vector>
#include <set>
#include <cmath>

/**
 * 
5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
 */
#include <cassert>
using namespace std;
/**
 * Return the tiles to inspect
 */
std::vector<long> solve(long K, long C) {
  std::vector<long> ret;
  long x=0;
  for (;;) {
    long res=0;
    for (long e=0;e<C;x++,e++) {
      res+=x*pow(K, e);
      if (x == K-1) {
        ret.push_back(res);
        return ret;
      }
    }
    ret.push_back(res);
  }
  assert(false);
}
int main() {
  long T;
  cin >> T;
  for (long i=0;i<T;i++) {
    /**
     * K: original size
     * C: Complexity, orignal 1
     * S: students, allowed pick
     */
    long K,C,S;
    cin >> K >> C >> S;
    cout << "Case #" << i+1 << ": ";
    for (int i=0;i<K;i++) {
      cout << i+1  << " ";
    }
    cout  << "\n";
    continue;
    if (C*S<K) {
      cout << "IMPOSSIBLE";
    } else {
      std::vector<long> tmp = solve(K, C);
      // for (long t : tmp) {
      //   assert(t>=0);
      //   cout << t+1 << " ";
      // }
      // for (int i=0;i<(int)tmp.size()-1;i++) {
      //   cout << tmp[i]+1 << " ";
      // }
      // cout << tmp[tmp.size()-1]+1;
      // for (int x=0;x<K;x++) {
      //   cout << pow(K, C-1) * x + 1 << " ";
      // }
    }
    cout  << "\n";
  }
}
