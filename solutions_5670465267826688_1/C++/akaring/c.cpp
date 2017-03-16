#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

lint X;
int L, arr[10005], lps[10005], rps[10005];

int mul(int x, int y) {
  if (abs(x) == 1 || abs(y) == 1) {
    return x * y;
  }
  if (abs(x) == abs(y)) {
    return (x < 0) == (y < 0) ? -1 : 1;
  }
  return ((x < 0) == (y < 0) ? 1 : -1) * (abs(y) == (abs(x) - 1) % 3 + 2 ? 1 : -1) * (9 - abs(x) - abs(y));
}

const VI vals = {-4, -3, -2, -1, 1, 2, 3, 4};

int findl(int o, int rhs) {
  static map<PII, int> mp;
  auto pa = MP(o, rhs);
  auto iter = mp.find(pa);
  if (iter == mp.end()) {
    for (int lhs: vals) {
      if (mul(lhs, rhs) == o) {
        mp.insert(MP(pa, lhs));
        return lhs;
      }
    }
    return 0;
  }
  return iter->Y;
}

int findr(int o, int lhs) {
  static map<PII, int> mp;
  auto pa = MP(o, lhs);
  auto iter = mp.find(pa);
  if (iter == mp.end()) {
    for (int rhs: vals) {
      if (mul(lhs, rhs) == o) {
        mp.insert(MP(pa, rhs));
        return rhs;
      }
    }
    return 0;
  }
  return iter->Y;
}

map<int, VI> l_idx, r_idx;

bool check_1(int lhs, int rhs) {
  VI &lid = l_idx[findr(2, lhs)];
  VI &rid = r_idx[findl(4, rhs)];
  for (int l: lid) {
    for (int r: rid) {
      if (r <= l) {
        break;
      }
      if (findr(lps[r - 1], lps[l]) == 3) {
        return true;
      }
    }
  }
  return false;
}

bool check_2(int lhs, int mids, int rhs) {
  VI &lid = l_idx[findr(2, lhs)];
  VI &rid = r_idx[findl(4, rhs)];
  for (int l: lid) {
    for (int r: rid) {
      if (mul(mul(rps[l + 1], mids), lps[r - 1]) == 3) {
        return true;
      }
    }
  }
  return false;
}

bool solve() {
  static char str[10005];
  scanf("%d%lld%s", &L, &X, str);
  REP (i, L) {
    arr[i + 1] = str[i] == 'i' ? 2 : (str[i] == 'j' ? 3 : 4);
  }

  l_idx.clear();
  r_idx.clear();

  arr[0] = 1;
  l_idx[lps[0] = 1].PB(0);
  r_idx[rps[L + 1] = 1].PB(L + 1);
  REP (i, L) {
    l_idx[lps[i + 1] = mul(lps[i], arr[i + 1])].PB(i + 1);
    r_idx[rps[L - i] = mul(arr[L - i], rps[L - i + 1])].PB(L - i);
  }

  /*
  for (int i = 1; i <= L; ++i) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  printf("\n");

  for (int i = 1; i <= L; ++i) {
    printf("lps[%d] = %d\n", i, lps[i]);
  }
  printf("\n");

  for (int i = 1; i <= L; ++i) {
    printf("rps[%d] = %d\n", i, rps[i]);
  }
  printf("\n");
  */

  int u[4];
  u[0] = 1;
  u[1] = accumulate(arr + 1, arr + L + 1, 1, mul);
  u[2] = mul(u[1], u[1]);
  u[3] = mul(u[2], u[1]);

  REP (l, 4) {
    REP (r, 4) {
      if (l + r + 1 > X) {
        continue;
      } else if (l + r + 1 == X) {
        if (check_1(u[l], u[r])) {
          return true;
        }
      } else {
        int m = (X - l - r - 2) % 4;
        if (check_2(u[l], u[m], u[r])) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %s\n", index, solve() ? "YES" : "NO");
  }
  return 0;
}
