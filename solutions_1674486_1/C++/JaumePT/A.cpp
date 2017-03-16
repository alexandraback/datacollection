#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int T, cas;
  cin >> T;
  cas = 1;
  while (cas <= T) {
    int N;
    cin >> N;
    vector<int> cont(N, 0);
    vector< vector<int> > inh(N);
    for (int i = 0; i < N; ++i) {
      int M;
      cin >> M;
      inh[i] = vector<int>(M);
      for (int j = 0; j < M; ++j) {
        int x;
        cin >> x;
        x--;
        inh[i][j] = x;
        cont[x]++;
      }
    }
    
    bool trobat = false;
    for (int i = 0; i < N and not trobat; ++i) {
      if (cont[i] == 0) {
        vector<bool> vist(N, false);
        queue<int> q;
        q.push(i);
        vist[i] = true;
        while (not q.empty() and not trobat) {
          int x = q.front();
          q.pop();
          for (int j = 0; j < inh[x].size() and not trobat; ++j) {
            int y = inh[x][j];
            if (vist[y]) trobat = true;
            else {
              vist[y] = true;
              q.push(y);
            }
          }
        }
      }
    }
    cout << "Case #" << cas << ": ";
    if (trobat) cout << "Yes" << endl;
    else cout << "No" << endl;
    ++cas;
  }
}