#include <iostream>
#include <string>

using namespace std;

namespace {

int Solve(string S) {
  S.push_back('+');
  int res = 0;
  for (int i = 1; i < S.size(); ++i) res += S[i] != S[i - 1];
  return res;
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    string S;
    cin >> S;
    cout << "Case #" << i << ": " << Solve(S) << endl;
  }

  return 0;
}
