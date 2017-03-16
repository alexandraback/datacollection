#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int Case = 1;Case <= T;Case++) {
    int n;
    string st;
    cin >> n;
    cin >> st;
    int current = 0;
    int ans = 0;
    for (int i = 0;i <= n;i++) {
      int addition = 0;
      if (i - current > 0) { 
        addition = (i - current);
        ans += addition;
      }
      current += st[i] - '0' + addition;
    }
    printf("Case #%d: %d\n",Case,ans);
  }
}
