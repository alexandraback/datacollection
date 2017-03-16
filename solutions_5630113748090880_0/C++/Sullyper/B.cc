#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int N;

int grid[100][100];

bool check(int i) {
  if (i == 0) return true;
  for (int j = 0; j < N; j++) {
    if (grid[i][j] <= grid[i-1][j]) return false;
  }
  return true;
}

void add(int i, vector<int>& v) {
  for (int j = 0; j < N; j++) grid[i][j] = v[j];
}

void print(vector<int>& cols) {
    for (int k = 0; k < cols.size(); k++) 
     cout << cols[k] << " - "; cout << "\n";
    for (int k = 0; k < N; k++) {
      for (int l = 0; l < N; l++) {
        cout << grid[k][l] << " "; } cout << "\n"; }
}

bool fct(vector<vector<int> >& vecs, int i, int j, vector<int>& cols) {;
  if (cols.size() > N) return false;
  if (j == vecs.size()) {
    int missing = -1;
    for (int k = 0; k < cols.size(); k++) {
      int col = k + (missing != -1 ? 1 : 0);
      if (grid[0][col] != vecs[cols[k]][0]) {
        if (missing != -1) return false;
        missing = col;
        col++;
      }
      for (int l = 0; l < N; l++) {
        if (grid[l][col] != vecs[cols[k]][l]) {
          return false;
        }
      }
    }
    if (missing == -1) missing = N-1;
    //print(cols);
    for (int l = 0; l < N; l++) cout << grid[l][missing] << " ";
    return true;
  }
  if (i == N) {
    cols.push_back(j);
    if (fct(vecs, i, j+1, cols)) return true;
    cols.pop_back();
    return false;
  }
  add(i, vecs[j]);
  if (check(i) && fct(vecs, i+1, j+1, cols)) return true;
  cols.push_back(j);
  if (fct(vecs, i, j+1, cols)) return true;
  cols.pop_back();
  return false;
}

void solve() {
  cin >> N;
  vector<vector<int> > vecs;
  for (int i = 1; i < 2*N; i++) {
    vecs.push_back(vector<int>());
    for (int j = 0; j < N; j++) {
      int n; cin >> n;
      vecs.back().push_back(n);
    }
  }
  sort(vecs.begin(), vecs.end());
  vector<int> cols;
  fct(vecs, 0, 0, cols);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}
