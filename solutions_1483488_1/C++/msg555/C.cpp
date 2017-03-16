#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<vector<int> > A;
  for(int i = 1; i <= 2000000; i++) {
    vector<int> V;
    int x = i;
    int m = 1;
    while(x) {
      V.push_back(x % 10);
      x /= 10;
      m *= 10;
    }
    x = i;
    vector<int> S;
    for(int i = 0; i < V.size(); i++) {
      x += V[i] * m;
      x /= 10;
      if(V[i]) S.push_back(x);
    }
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    A.push_back(S);
  }
  sort(A.begin(), A.end());
  A.resize(unique(A.begin(), A.end()) - A.begin());

  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int LO, HI; cin >> LO >> HI;
    long long res = 0;
    for(int i = 0; i < A.size(); i++) {
      int r = 0;
      for(int j = 0; j < A[i].size(); j++) {
        r += LO <= A[i][j] && A[i][j] <= HI;
      }
      res += r * (r - 1) / 2;
    }
    cout << "Case #" << t << ": " << res << endl;
  }
}
