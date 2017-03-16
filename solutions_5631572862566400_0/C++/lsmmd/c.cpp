#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
int main() {
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    int ans = 1;
    /*
    for (int i = 0; i < n; i++) {
      cout << "i = " << i << endl;
      int cnt = 0, now = i + 1;
      set<int> st;
      do {
        st.insert(now);
        cnt++;
        if (a[a[now - 1] - 1] == now) {
          ans = max(ans, cnt + 1);
          break;
        }
        now = a[now - 1];
        cout << "now, cnt = " << now << ", " << cnt << endl;
      } while (st.find(now) == st.end() && now != i + 1);
      if (now == i + 1) {
        ans = max(ans, cnt);
      }
      cout << "ans = " << ans << endl;
    }*/

    //int ans = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      nums[i] = i;
    }
    do {
      int cnt = 1;
      for (int i = 1; i <= n; i++) {
        bool flag = true;
        if (a[nums[0]] != nums[i - 1] && a[nums[0]] != nums[1]) {
          continue;
        }
        if (a[nums[i - 1]] != nums[i - 2] && a[nums[i - 1]] != nums[0]) {
          continue;
        }
        for (int j = 1; j <= i - 2; j++) {
          if (a[nums[j]] != nums[j - 1] && a[nums[j]] != nums[j + 1]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          ans = max(ans, i);
        }
      }
      ans = max(ans, cnt);
    } while (next_permutation(nums.begin(), nums.end()));

    cout << "Case #" << tk1 << ": " << ans << endl;
  }
  return 0;
}
