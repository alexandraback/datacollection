#include <iostream>
#include <cstdio>
#include <cassert>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <string>
//#include <>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())
#define eprintf(...) fprintf (stderr, __VA_ARGS__)

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

const int maxn = 50;
char a[maxn][maxn];

int n, m, k;

void clear() {  
}

void read() {
  n = getInt();
  m = getInt();
  k = n * m - getInt();
  fori(i,0,n)
    fori(j,0,m)
      a[i][j] = '*';
}

bool solve() {
  eprintf("%d %d %d\n", n, m, k);
  a[0][0] = 'c';
  int size = n * m;
  if (k == 1)
    return true;
  if (n == 1) {
    fori(j,1,k)
      a[0][j] = '.';
    return true;
  }
  if (m == 1) {
    fori(i,1,k)
      a[i][0] = '.';
    return true;
  }
  if (k < 4)
    return false;

  int sumLen = (k - 4) / 2;
  int sn = sumLen / 2, sm = sumLen - sn;
  if (sn > n - 2) {
    sm += sn - (n - 2);
    sn = n - 2;
  }
  if (sm > m - 2) {
    sn = min(sn + sm - (m - 2), n - 2);
    sm = m - 2;
  }
  int rem = k - 4 - 2 * (sn + sm);
  int S = sn * sm;
  if (S < rem)
    return false;

  fori(i,0,sn+2)
    a[i][0] = a[i][1] = '.';
  fori(j,0,sm+2)
    a[0][j] = a[1][j] = '.';
  a[0][0] = 'c';

  fori(i, 2, sn+2) {
    if (rem == 0)
      break;
    fori(j, 2, sm+2) {
      if (rem == 0)
        break;
      rem--;
      a[i][j] = '.';
    }
  }
  assert(rem == 0);
  return true;
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);

    printf("\n");
    bool good = solve();

    if (!good)
      printf("Impossible\n");
    else {  
      fori(i,0,n) {
        fori(j,0,m)
          printf("%c", a[i][j]);
        printf("\n");
      }
    }
  }
}
