#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long LL;

int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}

bool cleared[1001][2];
int rate[1001][2];
int N;

int rec(int star) {
  REP(i, N) {
    REP(j, 1) {
      if (!cleared[i][j] && star >= rate[i][j]) {
        cleared[i][j] = true;
        rec(star+1);
      }
    }
  }
}

int poor() {
  rec(0);
  return rec(0);
}

int solve() {
  int star = 0;
  int clearCnt = 0;
  int turn = 0;
  while (star != N*2) {
    //cout << "state: " << turn << ' ' << star << endl;
    bool cont = false;
    turn++;
    for (int i = N-1; i >= 0; i--) {
      if (!cleared[i][1] &&
          rate[i][1] <= star) {
        //cout << i << " 2" << endl;
        if (!cleared[i][0]) {
          star+=2;
        } else {
          star++;
        }
        cleared[i][0] = cleared[i][1] = true;
        cont = true;
        break;
      }
    }
    if (cont) continue;
    int next = -1;
    int nextl2 = -1;
    for (int i = N-1; i >= 0; i--) {
      if (!cleared[i][0] &&
          rate[i][0] <= star) {
        if (rate[i][1] > nextl2) {
          nextl2 = rate[i][1];
          next = i;
        }
      }
    }
    if (next == -1) return -1;
    star++;
    cleared[next][0] = true;
  }
  return turn;
}

int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
    N = nextInt();
    REP(i, N) REP(j, 2) rate[i][j] = nextInt();
    memset(cleared, 0, sizeof(cleared));

    int res = solve();
    if (res >= 0)
      printf("Case #%d: %d\n", caseCnt, res);
    else
      printf("Case #%d: Too Bad\n", caseCnt);
    //fprintf(stderr, "Case %d\n", caseCnt);
	}
	return 0;
}
