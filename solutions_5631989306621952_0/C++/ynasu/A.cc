#include <iostream>
#include <string>

using namespace std;

namespace {

string Solve(string S) {
  string res;
  for (char c : S) {
    res = max(c + res, res + c);
  }
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
