#include <iostream>
#include <string>
using namespace std;

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    string s;
    cin >> N >> s;
    int tot = 0, ret = 0;
    for (int i = 0; i < s.size(); i++) {
      while (tot < i) {tot++; ret++;}
      tot += s[i]-'0';
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
