#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    int n, m;
    cin >> n >> m;
    
    VVI M(n, VI(m));
    VI min_row(n, 0), min_col(m, 0);
    
    //If we cut lower than these values we're screwed-up
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> M[i][j];
        min_row[i] = max(min_row[i], M[i][j]);
        min_col[j] = max(min_col[j], M[i][j]);
      }
    }
    
    bool ok = true;
    for (int i = 0; i < n and ok; ++i) {
      for (int j = 0; j < m and ok; ++j) {
        if (min_row[i] > M[i][j] and min_col[j] > M[i][j]) ok = false;       
      }
    }
    
    cout << "Case #" << cas << ": " << (ok ? "YES" : "NO") << endl;
  }
}