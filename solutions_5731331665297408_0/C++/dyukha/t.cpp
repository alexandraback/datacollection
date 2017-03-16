#include <iostream>
#include <cstdio>
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

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

int n;

bool a[8][8];
char s[8][6];
char conc[41];

void clear() {
}

void read() {
  int m;
  scanf("%d%d", &n, &m);
  fori(i,0,n) {
    scanf("%s", s[i]);
  }
  fori(i,0,n)
    fori(j,0,n)
      a[i][j] = 0;
  fori(i,0,m) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    a[x][y] = a[y][x] = true;
  }
}

void solve() {
  string res = (char)('z' + 1) + (string)"";
  int p[8];
  int st[8];
  int h = -1;
  conc[n*5] = 0;
  fori(i,0,n)
    p[i] = i;
  do {
    fori(i,0,n)
      fori(j,0,5)
        conc[i*5 + j] = s[p[i]][j];
    if (conc >= res)
      continue;
    h = 0;
    st[h] = p[0];
    bool flag = true;
    fori(i,1,n) {
      while (h >= 0) {
        if (a[st[h]][p[i]])
          break;
        h--;
      }
      if (h < 0) {
        flag = false;
        break;
      }
      st[++h] = p[i];
    }
    if (!flag)
      continue;
    res = conc;
  } while(next_permutation(p, p + n));
  printf("%s\n", res.c_str());
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
    solve();
  }
}
