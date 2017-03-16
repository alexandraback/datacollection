#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <bitset>
#define phb push_back
#define ppb pop_back
#define mkp make_pair
#define frs first
#define scn second
using namespace std;

const int kInf = numeric_limits< int >::max() / 10;

int Z, E, R, N;
int V[20];
int f[20][10];

void read();
void soups_on(int);

int main() {
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi)
    read(), soups_on(zi);

  return 0;
}

void read() {
  cin >> E >> R >> N;
  for (int i = 0; i < N; ++i)
    cin >> V[i];
}

void soups_on(int zi) {
  fill(&f[0][0], &f[20][0], -kInf);
  f[0][E] = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 1; j <= E; ++j)
      if (f[i][j] > -kInf) {
        for (int k = 0; k <= j; ++k) {
          int nj = min(j - k + R, E);
          f[i + 1][nj] = max(f[i + 1][nj], f[i][j] + V[i] * k);
        }
      }

  int res = -kInf;
  for (int i = 1; i <= E; ++i)
    res = max(res, f[N][i]);
  cout << "Case #" << zi << ": " << res << "\n";
}
