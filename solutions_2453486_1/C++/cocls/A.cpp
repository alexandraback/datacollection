#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(){
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int test_n;
  scanf("%d", &test_n);
  char state[4][5];
  for (int t = 0; t < test_n; ++t) {
    printf("Case #%d: ", t+1);
    for (int i = 0; i < 4; ++i) {
      scanf("%s", state[i]);
    }
    // check row
    bool xwon = false;
    bool owon = false;
    for (int i = 0; i < 4; ++i) {
      bool xline = true;
      bool oline = true;
      for (int j = 0; j < 4; ++j) {
	if (state[i][j] != 'X' && state[i][j] != 'T') {
	  xline = false;
	}
	if (state[i][j] != 'O' && state[i][j] != 'T') {
	  oline = false;
	}
      }
      if (xline) {
	xwon = true;
	break;
      }
      if (oline) {
	owon = true;
	break;
      }
    }
    if (xwon) {
      printf("X won\n");
      continue;
    }
    if (owon) {
      printf("O won\n");
      continue;
    }
    // check column
    for (int i = 0; i < 4; ++i) {
      bool xline = true;
      bool oline = true;
      for (int j = 0; j < 4; ++j) {
	if (state[j][i] != 'X' && state[j][i] != 'T') {
	  xline = false;
	}
	if (state[j][i] != 'O' && state[j][i] != 'T') {
	  oline = false;
	}
      }
      if (xline) {
	xwon = true;
	break;
      }
      if (oline) {
	owon = true;
	break;
      }
    }
    if (xwon) {
      printf("X won\n");
      continue;
    }
    if (owon) {
      printf("O won\n");
      continue;
    }
    // check main diagonal
    xwon = true;
    owon = true;
    for (int i = 0; i < 4; ++i) {
      if (state[i][i] != 'X' && state[i][i] != 'T') {
	xwon = false;
      }
      if (state[i][i] != 'O' && state[i][i] != 'T') {
	owon = false;
      }
    }
    if (xwon) {
      printf("X won\n");
      continue;
    }
    if (owon) {
      printf("O won\n");
      continue;
    }
    // check the other diagonal
    xwon = true;
    owon = true;
    for (int i = 0; i < 4; ++i) {
      if (state[i][3-i] != 'X' && state[i][3-i] != 'T') {
	xwon = false;
      }
      if (state[i][3-i] != 'O' && state[i][3-i] != 'T') {
	owon = false;
      }
    }
    if (xwon) {
      printf("X won\n");
      continue;
    }
    if (owon) {
      printf("O won\n");
      continue;
    }
    // check if draw
    bool draw = true;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
	if (state[i][j] == '.') {
	  draw = false;
	}
      }
    }
    if (draw) {
      printf("Draw\n");
    } else {
      printf("Game has not completed\n");
    }
  }
  
  return 0;
}
