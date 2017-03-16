#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n;i++) {
    int k;
    cin >> k;
    map<int,int> sol;
    int tmp;
    for (int j = 0; j < (2*k)-1; j++) {
      for (int l = 0; l < k; l++) {
        cin >> tmp;
        sol[tmp]++;
      }
    }
    vector<int> ans;
    for (map<int,int>::iterator it = sol.begin(); it != sol.end(); it++) {
      if (it->second % 2 == 1) {
        ans.push_back(it->first);
      }
    }
    cout << "Case #" << i+1 << ": ";
    for (int j = 0; j < k; j++) {
      cout << ans[j];
      if (j != k-1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
