#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;

int t;
int n, k;

char s[MAXN];
int g[10][10];

// 0  1  2  3  4  5  6  7
// 1 -1  i -i  j -j  k -k

int get(char x) {
  if (x == 'i') return 2;
  else if (x == 'j') return 4;
  else return 6;  
}

string rev(int x) {
  string ans;
  int inv = 0;
  if (x & 1) {
    x ^= 1;
    inv ^= 1;
  }
  if (x == 0) ans = "1";
  else if (x == 2) ans = "i";
  else if (x == 4) ans = "j";
  else if (x == 6) ans = "k";
  if (inv)
    ans = "-" + ans;

  return ans;
}

void init() {
  g[0][0]=1,g[0][2]=2,g[0][4]=4,g[0][6]=6;
  g[2][0]=2,g[2][2]=1,g[2][4]=6,g[2][6]=5;
  g[4][0]=4,g[4][2]=7,g[4][4]=1,g[4][6]=2;
  g[6][0]=6,g[6][2]=4,g[6][4]=3,g[6][6]=1;
}

int mult(int x, int y) {
  if (x & 1) {
    x ^= 1;
    y ^= 1;
  }
  int inv = 0;
  if (y & 1) {
    y ^= 1;
    inv ^= 1;
  }
  return g[x][y]^inv;
}
         
int suff[MAXN];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out","w",stdout);
  #endif
  
  init();

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d%d\n%s", &n, &k, &s);
    for (int i = n; i < n * k; i++)
      s[i] = s[i - n];

    n = n * k;
    suff[n] = 0;
    for (int i = n - 1; i >= 0; --i)
      suff[i] = mult(suff[i + 1], get(s[i]));

    int pref = 0;
    int state = 0;
    for (int i = 0; i < n; i++) {
      pref = mult(pref, get(s[i]));
      if (pref == get('i')) {
        if (!state) state = 1;
      }
      else if (pref == get('k')) {
        if (state == 1) ++state;  
      }
    }
    bool verygj = 0;
    if (pref == 1 && state == 2) {
      verygj = true;
    }
    printf("Case #%d: ", cases);
    puts(verygj ? "YES" : "NO");
  }

  return 0;
}