#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int cas = 1; cas <= t; cas++){
    string s;
    cin >> s;
    cout << "Case #" << cas << ": ";
    string ans;
    ans += s[0];
    for(int i = 1; i < s.size(); i++){
      if(ans[0] > s[i])
        ans = ans + s[i];
      else
        ans = s[i] + ans;
      continue;
    }
    cout << ans << endl;
  }
}
