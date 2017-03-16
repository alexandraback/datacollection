#include <bits/stdc++.h>
#define REP(x, n) for (int x = 0; x < (int)(n); x++)
#define RREP(x, n) for (int x = (int)(n)-1; x >= 0; --x)
#define FOR(x, m, n) for (int x = (int)m; x < (int)(n); x++)
#define EACH(itr, cont) \
  for (typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X) (X).begin(), (X).end()
#define mem0(X) memset((X), 0, sizeof(X))
#define mem1(X) memset((X), 255, sizeof(X))

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

bool good(int val, string s) {
  int N = s.length(), dig;
  RREP(i, N) {
    dig = val % 10, val /= 10;
    if (s[i] != '?' && s[i] != dig + '0') return false;
  }
  return val == 0;
}

PLL solve_slow(string a, string b) {
  int x = -1, y = -1, dif = 9999;
  REP(A, 1000) REP(B, 1000) {
    if (good(A, a) && good(B, b)) {
      if (abs(A - B) < dif)
        x = A, y = B, dif = abs(A - B);
      else if (abs(A - B) == dif) {
        if (A < x)
          x = A, y = B;
        else if (A == x && B < y)
          y = B;
      }
    }
  }
  return PLL(x, y);
}

PLL check(string a, string b) {
  int N = a.length(), d = -1, i = 0;
  REP(i, N) if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
    d = i;
    break;
  }
  fprintf(stderr, "Dif @ %d\n", d);
  if (d < 0) {
    REP(i, N) {
      if (a[i] == '?' && b[i] == '?')
        a[i] = '0', b[i] = '0';
      else if (a[i] == '?')
        a[i] = b[i];
      else if (b[i] == '?')
        b[i] = a[i];
    }
  } else {
    bool smaller = a[d] < b[d];
    REP(i, d) if (a[i] == '?' || b[i] == '?') {
      if (a[i] == '?' && b[i] == '?') {
        if (smaller) {
          a[i] = '1', b[i] = '0';
        } else
          a[i] = '0', b[i] = '0';
        smaller = false;
      } else if (a[i] == '?') {
        if (smaller) {
          if (b[i] != '9')
            a[i] = b[i] + 1, smaller = false;
          else
            a[i] = '9';
        } else
          a[i] = b[i];
      } else {
        if (smaller) {
          if (a[i] != '0')
            b[i] = a[i] - 1, smaller = false;
          else
            b[i] = '0';
        } else
          b[i] = a[i];
      }
    }
    FOR(i, d + 1, N) {
      if (a[i] == '?') a[i] = '0';
      if (b[i] == '?') b[i] = '9';
    }
  }
  fprintf(stderr, "%s %s\n", a.c_str(), b.c_str());
  return PLL(stoll(a), stoll(b));
}

void doStuff() {
  string a, b;
  cin >> a >> b;
  fprintf(stderr, "Input: %s %s (%lu)\n", a.c_str(), b.c_str(), a.length());
  PLL normal_slow = solve_slow(a, b);
  // PLL normal = check(a, b);
  // LL dif = abs(normal.first - normal.second);
  // PLL inv = check(b, a);
  // LL dif2 = abs(inv.first - inv.second);
  // if (dif > dif2)
  //   normal = PLL(inv.second, inv.first);
  // else if (dif == dif2) {
  //   if (inv.second < normal.first ||
  //       (inv.second == normal.first && inv.first < normal.second))
  //     normal = PLL(inv.second, inv.first);
  // }

  // fprintf(stderr, "%s %s\n", a.c_str(), b.c_str());
  int ten = 1;
  RREP(i, a.length()) {
    a[i] = '0' + (normal_slow.first / ten) % 10;
    b[i] = '0' + (normal_slow.second / ten) % 10;
    ten *= 10;
  }
  // if (normal.first != normal_slow.first ||
  //     normal_slow.second != normal.second) {
  //   fprintf(stderr, "Input: %s %s (%lu)\n", a.c_str(), b.c_str(),
  //   a.length());
  //   fprintf(stderr, "Fast %lld %lld\n", normal.first, normal.second);
  //   fprintf(stderr, "Slow %lld %lld\n", normal_slow.first,
  //   normal_slow.second);
  //   // assert(false);
  // }
  printf("%s %s\n", a.c_str(), b.c_str());
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t, T) printf("Case #%d: ", t + 1), doStuff();
  return 0;
}