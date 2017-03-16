#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

typedef uint64_t u64;
string solve(u64 K, u64 C, u64 S) {
  if (S * C < K) return "IMPOSSIBLE";
  u64 i = 0;
  bool first = true;
  stringstream s;
  while (i < K) {
    u64 n = 0;
    for (int j = 0; j < C; j++,i++) {
      n = n * K + (i % K);
    }
    if (!first)
      s << ' ';
    s << (n+1);
    first = false;
  }
  return s.str();
}

int main(int argc, char* argv[]) {
  uint64_t T;
  fstream f(argv[1]);
  f >> T;
  for (int i = 0; i < T; i++) {
    uint64_t K,C,S;
    f >> K >> C >> S;
    cout << "Case #" << (i+1) << ": " << solve(K, C, S) << endl;
  } 
  return 0;
}
