#include<bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for(int k = 1; k <= T; k++) {
    int Smax;
    cin >> Smax;
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); i++) S[i] -= '0';

    int less = 0, ret = 0;
    for(int i = 0; i <= Smax; i++) {
      if(less < i) {
        ret += i - less;
        less += i - less;
      }
      less += S[i];
    }
    cout << "Case #" << k << ": " << ret << endl;
  }
}
