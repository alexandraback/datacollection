#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;

int t;
int n;

long long k;

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
  g[0][0]=0,g[0][2]=2,g[0][4]=4,g[0][6]=6;
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

int first[10];         
int pref[MAXN];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out","w",stdout);
  #endif
  
  init();

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d%lld\n%s", &n, &k, &s);
    for (int i = 0; i < 10; i++)
      first[i] = -1;

    pref[0] = get(s[0]);
    for (int i = 1; i < n; i++) {
      pref[i] = mult(pref[i - 1], get(s[i]));
    }
    for (int i = 0; i < n; i++) {
      if (first[pref[i]] == -1) {
        first[pref[i]] = i;
      }
    }

    int total = 0;
    int val = pref[n - 1];
    long long deg = k;
    while (deg) {
      if (deg & 1) total = mult(total, val);
      deg >>= 1;
      val = mult(val, val);
    }
    //cout<<pref[n-1]<<"^"<<k<<"="<<total<<endl;
    bool verygj = (total == 1);
    int state = 0, cur = 0, pos = 0;

    k = min(k, 0ll + 100000);
    while (k) {
      int need = 9;
      int c=0;
      for (int w = 0; w < 8; w++) {
        if (mult(cur, w) == 2) {
          need = w;
          ++c;
        }
      }
      //cout<<rev(cur)<<"*"<<rev(need)<<"="<<rev(2)<<endl;
      if (first[need] != -1) {
        state = 1;
        pos = first[need];
        cur = need;
        break;
      }
      k--;
      cur = mult(cur, pref[n-1]);
    }
    if (!state) {
      verygj = false;
    }
    else {
      //cout<<"state 1 is easy\n";
      //cout<<pos<<endl;
      for (int i = pos + 1; i < n; i++) {
        cur = mult(cur, get(s[i]));
        if (cur == 6) {
          state = 2;
          break;  
        }
      }
      --k;
      if (state < 2) {
        while (k) {
          int need = 9;
          for (int w = 0; w < 8; w++) {
            if (mult(cur, w) == 6) {
              need = w;
              break;  
            }
          }
      
          if (first[need] != -1) {
            state = 2;
            break;
          }
          k--;
          cur = mult(cur, pref[n-1]);
        }
        if (state < 2) verygj = false;
      }
    }
    printf("Case #%d: ", cases);
    puts(verygj ? "YES" : "NO");
  }

  return 0;
}