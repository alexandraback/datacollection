#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

typedef vector<int> vi;

void dfs(const vector<vi>& NL, const vector<int>& layer, vector<int>& color,
         int x, int c) {
  if (color[x] != -1) {
    assert(color[x] == c);
    return;
  }
  color[x] = c;

  for (int i = 0; i < NL.size(); i++) {
    if (i == x) continue;
    if (layer[x] == layer[i]) {
      dfs(NL, layer, color, i, 1 - c);
    } else if (NL[x][layer[i]] != NL[i][layer[x]]) {
      dfs(NL, layer, color, i, c);
    }
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;

    vector<vector<int> > L(2 * N - 1, vector<int>(N));
    for (int i = 0; i < 2 * N - 1; i++) {
      for (int j = 0; j < N; j++) {
        cin >> L[i][j];
      }
    }

    int pivot = -1;
    vector<vi> NL;
    vector<int> layer;
    for (int i = 0; i < N; i++) {
      sort(L.begin(), L.end(), [&](const vi& a, const vi& b) {
        return a[i] < b[i];
      });

      if (L.size() == 1 || L[0][i] != L[1][i]) {
        pivot = i;
        NL.push_back(L[0]);
        layer.push_back(i);
        L.erase(L.begin(), L.begin() + 1);
      } else {
        NL.push_back(L[0]);
        NL.push_back(L[1]);
        layer.push_back(i);
        layer.push_back(i);
        L.erase(L.begin(), L.begin() + 2);
      }
    }

    vector<int> color(2 * N - 1, -1);
    for (int i = 0; i < 2 * N - 1; i++) {
      if (color[i] == -1) {
        dfs(NL, layer, color, i, 0);
      }
/*
cout<< layer[i] << "," << color[i] << ": ";
for (int j = 0; j < N; j++) {
cout << NL[i][j] << ' ';
}
cout << endl;
*/
    }

    vector<vi> M(N, vi(N));
    for (int i = 0; i < 2 * N - 1; i++) {
      for (int j = 0; j < N; j++) {
        int a = layer[i];
        int b = j;
        if (color[i] == 1) {
          swap(a, b);
        }
        M[a][b] = NL[i][j];
      }
    }
/*
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << M[i][j] << ' ';
      }
      cout << endl;
    }
*/

    cout << "Case #" << t << ":";
    for (int i = 0; i < N; i++) {
      int a = pivot;
      int b = i;
      if (color[pivot * 2] == 0) {
        swap(a, b);
      }
      cout << ' ' << M[a][b];
    }
    cout << endl;
  }
  return 0;
}
