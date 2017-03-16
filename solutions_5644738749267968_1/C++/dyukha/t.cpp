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

const int maxn = 1000;
double a[maxn], b[maxn];
int n;

void clear() {
}

void read() {
  n = getInt();
  fori(i,0,n)
    a[i] = getDbl();
  fori(i,0,n)
    b[i] = getDbl();
}

void solve() {
  sort(a, a+n);
  sort(b, b+n);
  int la = 0, lb = 0, ra = n-1, rb = n-1;
  int cheat = 0;
  fori(i,0,n) {
    if (a[la] > b[lb]) {
      cheat++;
      la++;
      lb++;
    } else {
      la++;
      rb--;
    }
  }
  la = 0, lb = 0, ra = n-1, rb = n-1;
  int fair = 0;
  fori(i,0,n) {
    if (a[ra] > b[rb]) {
      fair++;
      ra--;
      lb++;
    } else {
      ra--;
      rb--;
    }
  }
  printf("%d %d\n", cheat, fair);
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
