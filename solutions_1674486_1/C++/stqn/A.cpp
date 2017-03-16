#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

  int T;
  cin >> T;
  for (int x = 1; x <= T; ++x) {
    int N;
    cin >> N;
    vector<vector<int> > inher(N);
    for (int i = 0; i < N; ++i) {
      int M;
      cin >> M;
      inher[i].resize(M);
      for (int j = 0; j < M; ++j) {
        cin >> inher[i][j];
        --inher[i][j];
      }
    }
    bool flg = false;
    for (int i = 0; i < N; ++i) {
      vector<bool> ved(N);
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (ved[node]) {
          flg = true;
          break;
        }
        ved[node] = true;
        for (int j = 0; j < inher[node].size(); ++j) {
          q.push(inher[node][j]);
        }
      }
    }
    cout << "Case #" << x << ": " << (flg ? "Yes" : "No") << endl;
  }

  return 0;

}
