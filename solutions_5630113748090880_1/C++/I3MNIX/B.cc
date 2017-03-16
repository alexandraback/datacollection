#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int grid[55][55];
vvi arr;

void solve(){
  int n; cin >> n;
  arr.assign(2 * n - 1, vi(n));
  vi nums(3000, 0);
  for (int i = 0; i < 2 * n - 1; i++){
    for (int j = 0; j < n; j++){
      cin >> arr[i][j];
      nums[arr[i][j]]++;
    }
  }
  vi ans;
  for (int i = 0; i < 3000; i++){
    if (nums[i] & 1) ans.push_back(i);
  }
  assert((int) ans.size() == n);
  sort(ans.begin(), ans.end());
  for (int x : ans){
    cout << ' ' << x;
  }
  cout << endl;
}

int main(){
  int tc; cin >> tc;
  for (int cs = 1; cs <= tc; cs++){
    cout << "Case #" << cs << ":";
    solve();
  }


  return 0;
}
