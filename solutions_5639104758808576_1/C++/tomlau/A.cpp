#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int Smax;
    string S;
    cin >> Smax >> S;
    int cnt = S[0]-'0', friends = 0;
    for (int i=1; i<=Smax; i++) {
      if (cnt < i) {
        friends += i-cnt;
        cnt = i;
      }
      cnt += S[i]-'0';
    }
    cout << "Case #" << t << ": " << friends << endl;
 }
}
