#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline T middle(const T &a, const T &b) {
  return (a + b) / 2;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const li INF = 55 + ((li) 2e18);
const int N = 100;

li tens[N];

void Init() {
  tens[0] = 1;
  for (int i = 1; i < 20; ++i) {
    tens[i] = tens[i - 1] * 10;
  }
}

bool known[20][2];
li zp[20][2];
pt pp[20][2];
int palr[20][2];

li Rec(const string &a, const string &b, int fm, int n, int already) {
  li &tg = zp[fm][already];
  pt &ppg = pp[fm][already];
  bool &kg = known[fm][already];
  int &pag = palr[fm][already];
  if (!kg) {
    if (fm >= n) {
      kg = true;
      tg = 0;
      ppg = {-1, -1};
      return tg;
    }
    if (a[fm] == '?') {
      if (b[fm] == '?') {
        for (int i = 0; i < 10; ++i) {
          int jstart = already ? 0 : i;
          for (int j = jstart; j < 10; ++j) {
            li cur = (j - i) * tens[n - fm - 1];
            int na = (already > 0 || i < j) ? 1 : 0;
            li v = Rec(a, b, fm + 1, n, na);
            if (v == INF) {
              continue;
            }
            cur += v;
            if (!kg || tg > cur) {
              kg = true;
              tg = cur;
              ppg = {i, j};
              pag = na;
            }
          }
        }
      } else {
        int j = b[fm] - '0';
        int iend = already ? 10 : (j + 1);
        for (int i = 0; i < iend; ++i) {
          li cur = (j - i) * tens[n - fm - 1];
          int na = (already > 0 || i < j) ? 1 : 0;
          li v = Rec(a, b, fm + 1, n, na);
          if (v == INF) {
            continue;
          }
          cur += v;
          if (!kg || tg > cur) {
            kg = true;
            tg = cur;
            ppg = {i, j};
            pag = na;
          }
        }
      }
    } else if (b[fm] == '?') {
      int i = a[fm] - '0';
      int jstart = already ? 0 : i;
      for (int j = jstart; j < 10; ++j) {
        li cur = (j - i) * tens[n - fm - 1];
        int na = (already > 0 || i < j) ? 1 : 0;
        li v = Rec(a, b, fm + 1, n, na);
        if (v == INF) {
          continue;
        }
        cur += v;
        if (!kg || tg > cur) {
          kg = true;
          tg = cur;
          ppg = {i, j};
          pag = na;
        }
      }
    } else {
      int i = a[fm] - '0';
      int j = b[fm] - '0';
      //printf("i %d, j %d, already %d\n", i, j, already);
      if (already == 0 && i > j) {
        kg = true;
        tg = INF;
        ppg = {-1, -1};
        return tg;
      }
      li cur = (j - i) * tens[n - fm - 1];
      int na = (already > 0 || i < j) ? 1 : 0;
      li v = Rec(a, b, fm + 1, n, na);
      if (v != INF) {
        cur += v;
        if (!kg || tg > cur) {
          kg = true;
          tg = cur;
          ppg = {i, j};
          pag = na;
        }
      }
    }
    if (!kg) {
      kg = true;
      tg = INF;
      ppg = {-1, -1};
    }
  }
  return tg;
}

bool Collect(int n, pair<li, li> &res) {
  int a = 0;
  li na = 0, nb = 0;
  for (int i = 0; i < n; ++i) {
    if (pp[i][a].first == -1) {
      return false;
    }
    na = na * 10 + pp[i][a].first;
    nb = nb * 10 + pp[i][a].second;
    a = palr[i][a];
  }
  res.first = na;
  res.second = nb;
  return true;
}

pair<li, li> Solve(const string &a, const string &b) {
  memset(known, 0, sizeof known);
  memset(pp, -1, sizeof pp);
  int n = len(a);
  fprintf(stderr, "ab ret %lld\n", Rec(a, b, 0, n, 0));
  pair<li, li> ab;
  if (!Collect(n, ab)) {
    ab = {-1, -1};
  }

  memset(known, 0, sizeof known);
  memset(pp, -1, sizeof pp);
  fprintf(stderr, "ba ret %lld\n", Rec(b, a, 0, n, 0));
  pair<li, li> ba;
  if (!Collect(n, ba)) {
    ba = {-1, -1};
  }

  assert(ab.first >= 0 || ba.first >= 0);

  if (ab.first >= 0) {
    if (ba.first >= 0) {
      if (ab.second - ab.first == ba.second - ba.first) {
        if (ab.first == ba.first) {
          if (ab.second < ba.second) {
            return ab;
          } else {
            swap(ba.first, ba.second);
            return ba;
          }
        } else {
          if (ab.first < ba.first) {
            return ab;
          } else {
            swap(ba.first, ba.second);
            return ba;
          }
        }
      } else {
        if (ab.second - ab.first < ba.second - ba.first) {
          return ab;
        } else {
          swap(ba.first, ba.second);
          return ba;
        }
      }
    } else {
      return ab;
    }
  } else {
    swap(ba.first, ba.second);
    return ba;
  }
}

string Print(li x, int n) {
  char buf[32];
  sprintf(buf, "%lld", x);
  string s(buf);
  while (len(s) < n) {
    s = "0" + s;
  }
  return s;
}

void HandleCase() {
  char js[32], cs[32];
  scanf("%s %s\n", js, cs);
  assert(strlen(js) == strlen(cs));
  string sj(js);
  string sc(cs);

  int n = len(sj);

  pair<li, li> res = Solve(sj, sc);

  cout << Print(res.first, n) << ' ' << Print(res.second, n) << '\n';  
}

int main() {
  Init();

  int tests;
  scanf("%d\n", &tests);
  for (int test = 1; test <= tests; ++test) {
    printf("Case #%d: ", test);
    HandleCase();
  }
  return 0;
}
