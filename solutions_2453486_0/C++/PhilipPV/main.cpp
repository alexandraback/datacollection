#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

int main() {
  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    char data[2][4][4];
    bool isP = false;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        char c = 0;
        while (c != '.' && c != 'O' && c != 'X' && c != 'T') cin.get(c);
        data[0][i][j] = c;
        data[1][3 - j][i] = c;
        if (c == '.') isP = true;
      }
    }

    bool isX = false;
    bool isY = false;

    for (int v = 0; v < 2; ++v) {
      int cnt[1024];
      char p[4][4];
      memcpy(p, data[v], sizeof(p));
      for (int i = 0; i < 4; ++i) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < 4; ++j) ++cnt[p[i][j] + 512];
        if (cnt['X' + 512] + cnt['T' + 512] == 4) isX = true;
        if (cnt['O' + 512] + cnt['T' + 512] == 4) isY = true;
      }

      memset(cnt, 0, sizeof(cnt));
      for (int i = 0; i < 4; ++i) {
        ++cnt[p[i][i] + 512];
      }
      if (cnt['X' + 512] + cnt['T' + 512] == 4) isX = true;
      if (cnt['O' + 512] + cnt['T' + 512] == 4) isY = true;
    }

    if (!(isX ^ isY)) {
      cout << (isP ? "Game has not completed" : "Draw");
    } else if (isX) cout << "X won";
    else if (isY) cout << "O won";

    cout << endl;
  }


  return 0;
}