#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 110;
const double inf = 1e20;
const double eps = 1e-7;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int ds = 4;
int strop[MAXN][MAXN], pod[MAXN][MAXN];

inline bool releq(double a, double b) { return abs(a/b-1.) < eps; }
inline bool abseq(double a, double b) { return abs(a-b) < eps; }
inline bool eq(double a, double b) { return abseq(a, b) || releq(a, b); }
inline bool lt(double a, double b) { return !eq(a, b) && a < b; }
inline bool lte(double a, double b) { return eq(a, b) || a < b; }
inline bool gt(double a, double b) { return !eq(a, b) && a > b; }
inline bool gte(double a, double b) { return eq(a, b) || a > b; }

struct coor {
  int x, y;

  coor( void ) {}
  coor( const int &x0, const int &y0 ) : x( x0 ), y( y0 ) {}
  coor( const coor &C ) : x( C.x ), y( C.y ) {}

  inline friend coor operator+( coor A, const coor &B ) { A.x += B.x; A.y += B.y; return A; }
  inline friend coor operator-( coor A, const coor &B ) { A.x -= B.x; A.y -= B.y; return A; }
  inline friend coor operator+=( coor &A, const coor &B ) { A.x += B.x; A.y += B.y; return A; }
  inline friend coor operator-=( coor &A, const coor &B ) { A.x -= B.x; A.y -= B.y; return A; }
};

bool operator <(const coor &A, const coor &B) {
  if (A.x != B.x) return A.x < B.x;
  if (A.y != B.y) return A.y < B.y;
  return 0;
}

double price[MAXN][MAXN];
set< pair< double, coor > > S;
int n, m, h;

inline bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

double koliko(int x, int y, int nx, int ny, double kad) {
  if (strop[nx][ny] - pod[nx][ny] < 50) return inf;
  if (strop[x][y] - pod[nx][ny] < 50 ) return inf;
  if (strop[nx][ny] - pod[x][y] < 50 ) return inf;

  double visina_vode = h - kad*10.0;
  double tvoja_donja = max(visina_vode, 1.*pod[nx][ny]);
  double moja_donja = max(visina_vode, 1.*pod[x][y]);
  double cekam_sebe = 0;
  double cekam_tebe = 0;
  double cekam = 0;

  if (strop[nx][ny] - moja_donja < 50) {
    cekam_sebe = 50 + moja_donja - strop[nx][ny];
  }
  if (strop[nx][ny] - tvoja_donja < 50) {
    cekam_tebe = 50 + tvoja_donja - strop[nx][ny];
  }
  cekam = max(cekam_sebe, cekam_tebe) / 10;
  visina_vode = h - (kad+cekam)*10.0;
  tvoja_donja = max(visina_vode, 1.*pod[nx][ny]);
  moja_donja = max(visina_vode, 1.*pod[x][y]);
  double voda = max(moja_donja - pod[x][y], 0.0);

  if (lt(voda, 20)) return 10.0 + cekam;
  if (voda >= 20) return 1.0 + cekam;
  voda -= 10;
  return cekam + 10-voda + voda*.1;
}

bool smijem(int x, int y, int nx, int ny) {
  if (strop[nx][ny] - pod[nx][ny] < 50) return 0;
  if (strop[x][y] - pod[nx][ny] < 50 ) return 0;
  if (strop[nx][ny] - pod[x][y] < 50 ) return 0;
  double visina_vode = h;
  double tvoja_donja = max(visina_vode, 1.*pod[nx][ny]);
  double moja_donja = max(visina_vode, 1.*pod[x][y]);
  if (strop[nx][ny] - moja_donja < 50) return 0;
  if (strop[nx][ny] - tvoja_donja < 50) return 0;
  return 1;
}

void prije_pada(int x, int y) {
  if (!valid(x, y)) return;
  if (eq(price[x][y], 0.0)) return;
  price[x][y] = 0.0;
  S.insert(make_pair(0, coor(x, y)));

  for (int i = 0; i < ds; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (smijem(x, y, nx, ny)) {
      prije_pada(nx, ny);
    }
  }
}


int main() {
  int numCases = 1;
  scanf("%d", &numCases);
  for (int caseIt = 0; caseIt < numCases; ++caseIt) {
    printf("Case #%d: ", caseIt+1);
    scanf("%d%d%d", &h, &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &strop[i][j]);
        price[i][j] = inf;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &pod[i][j]);
      }
    }

    S.clear();
    prije_pada(0, 0);

    while (!S.empty()) {
      int x = S.begin()->second.x;
      int y = S.begin()->second.y;
      S.erase(S.begin());
      //      if (x == n-1 && y == m-1) break;

      for (int i = 0; i < ds; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!valid(nx, ny)) continue;
        double vrijeme = koliko(x, y, nx, ny, price[x][y]);
        if (vrijeme + price[x][y] < price[nx][ny]) {
          S.erase(make_pair(price[nx][ny], coor(nx, ny)));
          price[nx][ny] = vrijeme + price[x][y];
          S.insert(make_pair(price[nx][ny], coor(nx, ny)));
        }
      }
    }

    // printf("\n");
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     printf("%10g ", price[i][j]);
    //   }
    //   printf("\n");
    // }

    printf("%g\n", price[n-1][m-1]);
    //    printf("\n");
  }

  return 0;
}

