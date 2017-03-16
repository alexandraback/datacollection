#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


const vector<string> names {
"ZERO",
"TWO",
"SIX",
"SEVEN",
"FIVE",
"FOUR",
"THREE",
"EIGHT",
"ONE",
"NINE",
};
const vector<int> nums {0,2,6,7,5,4,3,8,1,9};


int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    string s; cin >> s;
    vector<int> v(26, 0);
    vector<int> ans;
    for (char c : s) v[c-'A']++;
    for (int i = 0; i < int(nums.size()); ++i) {
      bool valid = true;
      while (valid) {
        for (char c : names[i]) {
          if (!v[c-'A']) valid = false;
        }
        if (valid) {
          ans.push_back(nums[i]);
          for (char c : names[i]) {
            v[c-'A']--;
          }
        }
      }
    }
    sort(ans.begin(), ans.end());
    cout << "Case #" << ++ncase << ": ";
    for (int x : ans) cout << x;
    cout << endl;
  }
}

