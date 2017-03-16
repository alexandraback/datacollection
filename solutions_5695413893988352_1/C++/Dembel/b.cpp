#include <bits/stdc++.h>

using namespace std;

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

char s[40], t[40];
char cur[80];
char ans[80];

void solve() {
  scanf("%s%s", s, t);
  int len = strlen(s);
  dbg("len %d\n", len);
  bool eq = true;
  for (int i = 0; i < len; ++i) {
    if (!(s[i] == '?' || t[i] == '?' || s[i] == t[i])) {
      eq = false;
    }
  }

  if (eq) {
    dbg("%s %s ", s, t);
    for (int i = 0; i < len; ++i) {
      if (s[i] == '?') {
        s[i] = (t[i] == '?' ? '0' : t[i]);
      }
    }
    dbg("-> %s %s\n", s, s);
    printf("%s %s\n", s, s);
    return;
  }

  cur[len] = 0;
  cur[2 * len + 1] = 0;

  char *newS = cur;
  char *newT = cur + len + 1;

  ll ansDiff = -1;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (s[i] != '?' && s[i] != '0' + j) { continue; }
      newS[i] = '0' + j;

      for (int k = 0; k < 10; ++k) {
        dbg("i %d j %d k %d\n", i, j, k);
        if (j == k) { continue; }
        if (t[i] != '?' && t[i] != '0' + k) { continue; }
        newT[i] = '0' + k;

        char cS = '0';
        char cT = '9';
        if (j < k) { swap(cS, cT); }
        for (int p = i + 1; p < len; ++p) {
          newS[p] = (s[p] == '?' ? cS : s[p]);
          newT[p] = (t[p] == '?' ? cT : t[p]);
        }

        ll valS = atoll(newS);
        ll valT = atoll(newT);
        ll curDiff = valS - valT;
        if (curDiff < 0) { curDiff *= -1; }

        cur[len] = ' ';
        dbg("i %d j %d k %d : %s\n", i, j, k, cur);

        if (ansDiff == -1 || ansDiff > curDiff || (ansDiff == curDiff && strcmp(ans, cur) > 0)) {
          ansDiff = curDiff;
          strcpy(ans, cur);
        }
        cur[len] = 0;
      }
    }
    
    if (!(s[i] == '?' || t[i] == '?' || s[i] == t[i])) { break; }

    char ch;
    if (s[i] == '?') {
      ch = (t[i] == '?' ? '0' : t[i]);
    } else {
      ch = s[i];
    }
    newS[i] = newT[i] = ch;
  }

  dbg("ansDiff = %lld\n", ansDiff);
  dbg("%s %s -> %s\n", s, t, ans);
  printf("%s\n", ans);
}

int main()
{
#ifdef DBG1
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  assert(freopen("err.txt", "w", stderr));
#endif

  int tt;
  assert (scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    dbg("Case %d\n", ii);
    printf("Case #%d: ", ii);
    solve();
    fflush(stdout);
  }

  return 0;
}

