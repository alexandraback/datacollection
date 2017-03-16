#include<bits/stdc++.h>

using namespace std;
int mat[6][6];

int b, m;

int visiting[10];
int visited[10];

long long topo(int x) {
  long long paths = 0;
  if (x == b - 1) return 1LL;
  if (visiting[x]) {
    return 2 * m;
  }
  ++visiting[x];
  for (int i = 0; i < b; ++i) {
    if (mat[x][i]) {
      paths += topo(i);
      if (paths > m) return 2 * m;
    }
  }
  --visiting[x];
  return paths;
}

bool go() {
  memset(visiting, 0, sizeof visiting);
  memset(visited, 0, sizeof visited);
  long long bla = topo(0);
  return (bla == m);
}

bool tenta(int x, int y) {
  if (x == b - 2 && y == b - 1) {
    mat[x][y] = 0;
    if (go()) {
      return true;
    } 
    mat[x][y] = 1;
    if (go()) {
      return true;
    }     
    return false;
  }
  mat[x][y] = 0;
  if (y < b - 1) {
    if (tenta(x, y + 1)) return true;
  } else {
    if (tenta(x + 1, 0)) return true;
  }
  if (x != y) {
    mat[x][y] = 1;
    if (y < b - 1) {
      if (tenta(x, y + 1)) return true;
    } else {
      if (tenta(x + 1, 0)) return true;
    }
  }
  return false;
  
  
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
      cout << "Case #" << (i + 1) << ":";
      cin >> b >> m;
      memset(mat, 0, sizeof mat);
      if (tenta(0, 0)) {
         cout << " POSSIBLE\n";
         for (int k = 0; k < b; ++k) {
          for (int j = 0; j < b; ++j) {
            cout << mat[k][j];
          }
          cout << endl;
        }
      } else {
        cout << " IMPOSSIBLE\n";
      } 
  }
  return 0;
}
