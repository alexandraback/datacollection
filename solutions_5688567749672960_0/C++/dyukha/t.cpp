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
#include <cstring>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif
#define next next_sadasddsa

using namespace std;

typedef long long int int64;
typedef long double ldb;
typedef pair<int,int> pii;

inline void printInt(int a) { printf("%d", a); }
inline void printDbl(double a) { printf("%.10lf", a); }
inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

const int maxn = 1500 * 1000;
int a[maxn], rev[maxn];
int ans[maxn];

int reverse(int x) {
  int res = 0;
  while (x > 0) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

void solve() {
  int n = getInt();
  printf("%d\n", ans[n]);
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  srand(time(0));
  fori(i,0,maxn)
    rev[i] = reverse(i);
  fori(i,0,maxn)
    ans[i] = i;
  fori(i,1,maxn) {
    int r = rev[i];
    if (r > i && r < maxn) {
      ans[r] = min(ans[i]+1, ans[r]);
    }
    ans[i+1] = min(ans[i]+1, ans[i+1]);
  }
  int T = getInt();
  fori(i,0,T) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}