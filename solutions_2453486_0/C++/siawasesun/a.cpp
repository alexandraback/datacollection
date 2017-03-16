#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <inttypes.h>

// Macro
#define foreach(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define mp make_pair
#define ALL(a) (a).begin(), (a).end()
#define OSS ostringstream
#define ISS istringstream
#define CAST(x,type)  *({OSS oss; oss << (x); ISS iss(oss.str()); static type _r; iss >> _r; &_r; })
#define ARRAY_SIZE(x) (sizeof(x) / sizeof( (x)[0]) )

using namespace std;

void CommonInit() {
}

enum GameState {
  kXWon = 0,
  kOWon = 1,
  kDraw = 2,
  kNotCompleted = 3,
};

const char kResultStrings[4][256] = {
  "X won",
  "O won",
  "Draw",
  "Game has not completed",
};

struct Problem {
  char B[4][4];

  void Input() {
    char tmp;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%c", &B[i][j]);
      }
      scanf("%c", &tmp);
    }
    scanf("%c", &tmp);
  }

  GameState Solve() {
    // check each raw.
    for (int y = 0; y < 4; ++y) {
      bool allX = true;
      bool allO = true;
      for (int x = 0; x < 4; ++x) {
        if (B[y][x] == 'T') continue;
        if (B[y][x] != 'X') allX = false;
        if (B[y][x] != 'O') allO = false;
      }
      if (allX) return kXWon;
      if (allO) return kOWon;
    }

    // check each col.
    for (int x = 0; x < 4; ++x) {
      bool allX = true;
      bool allO = true;
      for (int y = 0; y < 4; ++y) {
        if (B[y][x] == 'T') continue;
        if (B[y][x] != 'X') allX = false;
        if (B[y][x] != 'O') allO = false;
      }
      if (allX) return kXWon;
      if (allO) return kOWon;
    }

    // check each diagonal.
    {
      bool allX = true;
      bool allO = true;
      for (int i = 0; i < 4; ++i) {
        if (B[i][i] == 'T') continue;
        if (B[i][i] != 'X') allX = false;
        if (B[i][i] != 'O') allO = false;
      }
      if (allX) return kXWon;
      if (allO) return kOWon;
    }
    {
      bool allX = true;
      bool allO = true;
      for (int i = 0; i < 4; ++i) {
        if (B[3 - i][i] == 'T') continue;
        if (B[3 - i][i] != 'X') allX = false;
        if (B[3 - i][i] != 'O') allO = false;
      }
      if (allX) return kXWon;
      if (allO) return kOWon;
    }

    // check draw or continue
    bool containsDot = false;
    for (int x = 0; x < 4; ++x) {
      for (int y = 0; y < 4; ++y) {
        if (B[y][x] == '.') containsDot = true;
      }
    }
    return (containsDot) ? kNotCompleted : kDraw;
  }
};

int main() {
  int T;
  scanf("%d\n", &T);
  CommonInit();
  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);
    Problem p;
    p.Input();

    GameState s = p.Solve();
    printf("%s\n", kResultStrings[s]);
  }

  return 0;
}
