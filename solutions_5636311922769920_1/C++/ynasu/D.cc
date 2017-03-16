#include <iostream>
#include <string>

using namespace std;

namespace {

string Solve(int K, int C, int S) {
  if (K > C * S) return "IMPOSSIBLE";
  string res;
  for (int i = 0; i < K; i += C) {
    long long index = 1;
    long long stride = 1;
    for (int j = i; j < min(K, i + C); ++j) {
      index += stride * j;
      stride *= K;
    }
    res += " " + to_string(index);
  }
  return res.substr(1);
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int K, C, S;
    cin >> K >> C >> S;
    cout << "Case #" << i << ": " << Solve(K, C, S) << endl;
  }

  return 0;
}
