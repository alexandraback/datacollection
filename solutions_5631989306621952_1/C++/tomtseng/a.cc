#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    string str;
    cin >> str;
    deque<char> ans;

    ans.push_front(str[0]);
    char first = str[0];
    for (int i = 1; i < str.length(); i++) {
      if (str[i] >= first) {
        ans.push_front(str[i]);
        first = str[i];
      } else {
        ans.push_back(str[i]);
      }
    }

    string sans (ans.size(), 'x');
    for (unsigned i = 0; i < ans.size(); i++) {
      sans[i] = ans[i];
    }

    cout << "Case #" << t << ": " << sans << "\n";
  }

  return 0;
}
