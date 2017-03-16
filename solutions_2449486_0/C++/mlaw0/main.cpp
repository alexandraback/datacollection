#include <iostream>
using namespace std;

const int MAXN = 101;
const int MAXM = 101;
int T, N, M;
int lawn[MAXN][MAXM];
int rowmax[MAXN], colmax[MAXM];
bool ret;
bool cr, cc;

int main () {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N >> M;
    ret = true;
    for (int x = 0; x < N; x++) rowmax[x] = 0;
    for (int y = 0; y < M; y++) colmax[y] = 0;
    for (int x = 0; x < N; x++)
      for (int y = 0; y < M; y++) {
        cin >> lawn[x][y];
        rowmax[x] = max(rowmax[x],lawn[x][y]);
        colmax[y] = max(colmax[y],lawn[x][y]);
      }
    for (int x  = 0; x < N; x++)
      for (int y = 0; y < M; y++) 
        if (lawn[x][y] < rowmax[x] && lawn[x][y] < colmax[y])
          ret = false;
    cout << "Case #" << i << ": " << (ret ? "YES" : "NO") << '\n';
  }
  return 0;
}
