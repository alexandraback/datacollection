#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    int N; cin >> N;
    vector<vector<double> > a(2, vector<double>(N));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < 2; i++) {
      sort(a[i].begin(), a[i].end());
    }

    vector<int> res(2);
    res[0] = 0;
    for (int l = 0; l <= N; l++) {
      int r = 0;
      for (int j = 0; j < l; j++) {
        if (a[0][j] > a[1][N-1-j]) {
          r++;
        }
      }
      for (int j = 0; j < N - l; j++) {
        if (a[0][j+l] > a[1][j]) {
          r++;
        }
      }
      res[0] = max(res[0], r);
    }
    
    vector<pair<double, int> > b;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N; j++) {
        b.push_back(make_pair(a[i][j], i));
      }
    }
    sort(b.begin(), b.end());
    
    res[1] = N;
    vector<int> used(2 * N, 0);
    int m = 0;
    for (int k = 2 * N - 1; k >= 0 ; k--) {
      if (b[k].second == 1) {
        m ++;
      }
      if (b[k].second == 0) {
        if (not used[k] and m > 0) {
          used[k] = 1;
          m --;
          res[1]--;
        }
      }
    }
    
    cout << "Case #" << c << ": ";
    cout << res[0] << " " << res[1];
    cout << endl;
    

  }
}
