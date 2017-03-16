#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int casen = 1; casen <= T; casen++) {
    int A, B; cin >> A >> B;
    int ans = 0;
    for (int i = A; i < B; i++) {
      int x = i;
      string s;
      while (x) {
        s = char(x % 10 + '0') + s;
        x /= 10;
      }
      
      set<int> uniq;
      for (int j = 1; j < s.size(); j++) {
        if (s[j] >= s[0]) {
          int ni = 0;
          for (int k = j; k < s.size(); k++) {
            ni = ni * 10 + s[k] - '0';
          }
          for (int k = 0; k < j; k++) { 
            ni = ni * 10 + s[k] - '0';
          }
          if (ni > i && ni <= B) {
            uniq.insert(ni);
          }
        }
      }
      ans += uniq.size();
    }
    
    printf("Case #%d: %d\n", casen, ans);
  }
}