#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

bool solve(const vector<vector<int> > &a) {
  const int n = a.size(), m = a[0].size();
  vector<int> r_max(n, -1), c_max(m, -1);
  rep(i, n) rep(j, m) r_max[i] = max(r_max[i], a[i][j]), c_max[j] = 
max(c_max[j], a[i][j]);
  rep(i, n) rep(j, m) if(r_max[i] > a[i][j] && c_max[j] > a[i][j]) 
return false;
  return true;
}

int main() {
  int T; cin >> T;
  for(int t=1; t<=T; t++) {
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m)); rep(i, n) rep(j, m) cin 
>> a[i][j];
    cout << "Case #" << t << ": " << (solve(a)?"YES":"NO") << endl;
  }
}

