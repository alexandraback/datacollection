#include <iostream>
#include <vector>
using namespace std;

bool can(int m, vector<int> coin, int v) {
  for (int i = 0; i < 31; ++i) {
    if (coin[i]) m |= (1 << i);
  }

  vector<int> M(v + 1, 0);
  M[0] = 1;
  for (int i = 0; i < 31; ++i) {
    if ((m >> i)&1) {
      for (int j = v; j >= 0; --j) {
        if (M[j] and j + i <= v) M[j + i] = 1;
      }
    }
  }

  for (int i = 1; i <= v; ++i) if (M[i] == 0) return false;
  return true;
}

int solve() {
  int c, d, v;
  cin >> c >> d >> v;
  vector<int> coin(31, 0);
  for (int i = 0; i < d; ++i) {
    int x;
    cin >> x;
    coin[x] = 1;
  }

  int res = v - d;

  for (int i = 1; i < (1 << 17); ++i) {
    if (i&1) continue;

    bool ok = true;
    for (int j = 0; j <= 30 and ok; ++j) if (coin[j] and ((i >> coin[j])&1) == 0) ok = false;

    if (can(i, coin, v)) {
      int aux = 0;
      for (int j = 1; j < 17; ++j) {
        if (((i >> j)&1) and not coin[j]) ++aux;
      }
      if (res > aux) {
        res = aux;
/*
        for (int j = 0; j < 17; ++j) {
          if ((i >> j)&1) cerr << j << " ";
        }
        cerr << endl;*/
      }
    }
  }
  
  return res;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
