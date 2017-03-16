#include <stdlib.h>
#include <iostream>

using namespace std;

bool before(string A, string B)
{
  for (size_t i = 0; i < A.length(); i++) {
    if (A[i] < B[i]) {
      return true;
    }
    else if (A[i] > B[i]) {
      return false;
    }
  }
  return false;
}

string solve(string S)
{
  string ans = "";
  for (size_t i = 0; i < S.length(); i++) {
    string a = S[i] + ans;
    string b = ans + S[i];
    //cout << a << "\n" << b << "\n\n";
    if (before(a, b)) {
      ans = b;
    }
    else {
      ans = a;
    }
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string S;
    cin >> S;
    cout << "Case #" << t << ": " << solve(S) << "\n";
  }
  return 0;
}

