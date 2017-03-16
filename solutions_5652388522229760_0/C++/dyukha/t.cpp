#include <bits/stdc++.h>

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

void clear() {
}

void read() {
}

int solve() {
  int n = getInt();
  if (n == 0)
    return -1;
  int cnt = 0;
  bool was[10];
  fori(i,0,10)
    was[i] = false;
  int m = 0;
  fori(t,1,1000) {
    m += n;
    int num = m;
    while (num > 0) {
      int d = num % 10;
      if (!was[d]) {
        was[d]++;
        cnt++;
        if (cnt == 10)
          return m;
      }
      num /= 10;
    }
  }
  assert(false);
  return -1;
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  /*fori(n,0,1000001) {
    if (n % 100000 == 0)
      cerr << n << endl;
    int cnt = 0;
    bool was[10];
    fori(i,0,10)
      was[i] = false;
    int m = 0;
    bool good = false;
    fori(t,0,100) {
      if (good)
        break;
      m += n;
      int num = m;
      while (num > 0) {
        int d = num % 10;
        if (!was[d]) {
          was[d]++;
          cnt++;
          if (cnt == 10)
            good = true;
        }
        num /= 10;
      }
    }
    if (!good)
      printf("%d\n", n);
  }*/
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);
    int res = solve();
    if (res == -1)
      printf("INSOMNIA\n");
    else
      printf("%d\n", res);
  }
  return 0;
}
