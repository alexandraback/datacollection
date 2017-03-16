#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

// TEMPLATE {{{
#ifdef ONLINE_JUDGE
#define OJ 1
#else
#define OJ 0
#endif

//#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& m, const T& s) { if (!OJ) cerr << "\E[91m" << s << "\E[0m"; return m; }
C_ merr;
/// END OF TEMPLATE }}}

int D[4][2] = { {0 , 1}, {1 , 0}, {0 ,-1}, {-1, 0} };

char A[7][7];
bool u[7][7];

int r,c,m;
int used;

//void dfs(int x, int y, int d, int num) {
  //int dx = D[d][0];
  //int dy = D[d][1];
  //if (num != m && A[x+dx][y+dy] != '.') {
    //return dfs(x,y,(d+1)%4, num);
  //} else {
    //A[x][y] = '*';
    //if (num == m) return;
    //return dfs(x+dx,y+dy,d,num+1);
  //}
//}

inline bool check(int x, int y) {
  return !(A[x-1][y-1] == '*' ||
           A[x-1][y  ] == '*' ||
           A[x-1][y+1] == '*' ||
           A[x  ][y-1] == '*' ||
           A[x  ][y+1] == '*' ||
           A[x+1][y-1] == '*' ||
           A[x+1][y  ] == '*' ||
           A[x+1][y+1] == '*');
}

void dfs2(int x, int y) {
  u[x][y] = 1;
  used--;
  if (check(x,y)) {
    if (A[x-1][y-1] == '.' && !u[x-1][y-1]) dfs2(x-1,y-1);
    if (A[x-1][y  ] == '.' && !u[x-1][y  ]) dfs2(x-1,y  );
    if (A[x-1][y+1] == '.' && !u[x-1][y+1]) dfs2(x-1,y+1);
    if (A[x  ][y-1] == '.' && !u[x  ][y-1]) dfs2(x  ,y-1);
    if (A[x  ][y+1] == '.' && !u[x  ][y+1]) dfs2(x  ,y+1);
    if (A[x+1][y-1] == '.' && !u[x+1][y-1]) dfs2(x+1,y-1);
    if (A[x+1][y  ] == '.' && !u[x+1][y  ]) dfs2(x+1,y  );
    if (A[x+1][y+1] == '.' && !u[x+1][y+1]) dfs2(x+1,y+1);
  }
}

bool check2(int x, int y) {
  used = r*c-m;
  memset(u,0,sizeof(u));
  dfs2(x,y);
  return used == 0;
}

void brute() {
  for (int bit = 0; bit < 1<<25; bit++) {
    int cnt = 0;
    for (int i = 0; i < 25; i++) {
      if (bit & (1<<i)) cnt++;
    }
    if (cnt != m) continue;
    memset(A,255,sizeof(A));
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        A[i][j] = '.';
      }
    }
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        int num = (i-1)*c+(j-1);
        if (bit & (1<<num)) A[i][j] = '*';
      }
    }
    bool ok = false;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        if (A[i][j] == '*') continue;
        if (check2(i,j)) {
          A[i][j] = 'c';
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) {
      for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
          cout << A[i][j];
          merr << A[i][j];
        }
        cout << endl;
        merr << '\n';
      }
      return;
    }
  }
  cout << "Impossible" << '\n';
  merr << "Impossible" << '\n';
}

int main(void) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    //bool ok = false;
    //int cnt = 0;
    cin >> r >> c >> m;;
    //for (int ttt = 0; ttt < 2; ttt++) {
    //memset(A,255,sizeof(A));
    //for (int i = 1; i <= r; i++) {
    //for (int j = 1; j <= c; j++) {
    //A[i][j] = '.';
    //}
    //}
    ////if (m) dfs(1,1,0,1);
    //if (ttt) {
    //for (int i = 1; i <= r; i++) {
    //for (int j = 1; j <= c; j++) {
    //if (cnt >= m) break;
    //A[i][j] = '*';
    //cnt++;
    //}
    //if (cnt >= m) break;
    //}
    //} else {
    //for (int j = 1; j <= c; j++) {
    //for (int i = 1; i <= r; i++) {
    //if (cnt >= m) break;
    //A[i][j] = '*';
    //cnt++;
    //}
    //if (cnt >= m) break;
    //}
    //}
    //for (int i = 1; i <= r; i++) {
    //for (int j = 1; j <= c; j++) {
    //if (A[i][j] == '*') continue;
    //if (check2(i,j)) {
    //A[i][j] = 'c';
    //ok = true;
    //break;
    //}
    //}
    //if (ok) break;
    //}
    //if (!ok && ttt) {
    //cout << "Case #" << tt+1 << ":" << endl;
    //cout << "Impossible" << endl;
    //} else if (ok) {
    //cout << "Case #" << tt+1 << ":" << endl;
    //for (int i = 1; i <= r; i++) {
    //for (int j = 1; j <= c; j++) {
    //cout << A[i][j];
    //}
    //cout << endl;
    //}
    //}
    //if (ok) break;
    //}
    cout << "Case #" << tt+1 << ":" << endl;
    merr << "Case #" << tt+1 << ":" << '\n';
    brute();
  }
  TIMESTAMP;
  return 0;
}
