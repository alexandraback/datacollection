#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void dw(size_t caseNo) {
  string S;
  cin >> S;
  string ans;
  for (int i = 0; i < S.length(); i++) {
    ans = max(ans + S[i], string(1, S[i]) + ans);
  }
  cout << "Case #" << caseNo << ": " << ans << endl;
}

int main() {
  size_t T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    dw(i + 1);
  }
}

