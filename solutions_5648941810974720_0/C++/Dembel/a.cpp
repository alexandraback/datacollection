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

const char words[10][20] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int maskW[10];
char s[4000];
int cnt[30];

int ansL;
char ans[4000];

bool brute(int cur, int curMask) {
  dbg("cur %d curMask %d\n", cur, curMask);
  for (int i = 0; i < 26; ++i) {
    if (cnt[i]) {
      dbg("%c%d ", 'A' + i, cnt[i]);
    }
  }
  dbg("\n");
  if (cur == 10) {
    if (curMask == 0) {
      return true;
    }
    return false;
  }

  if ((curMask & maskW[cur]) != curMask) {
    return false;
  }

  if (brute(cur + 1, curMask)) {
    return true;
  }

  ans[ansL++] = cur + '0';

  bool ok = true;
  for (int i = 0; words[cur][i]; ++i) {
    int c = words[cur][i] - 'A';
    cnt[c]--;
    if (cnt[c] == 0) {
      curMask ^= (1 << c);
    }
    if (cnt[c] < 0) {
      ok = false;
    }
  }

  if (ok && brute(cur, curMask)) {
    return true;
  }

  ansL--;
  for (int i = 0; words[cur][i]; ++i) {
    int c = words[cur][i] - 'A';
    cnt[c]++;
  }
  return false;
}

void solve() {
  scanf("%s", s);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; s[i]; ++i) {
    cnt[s[i] - 'A'] ++;
  }
  int mask = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i]) {
      mask |= (1 << i);
    }
  }

  dbg("mask = %d\n", mask);

  for (int i = 0; i < 10; ++i) {
    maskW[i] = 0;
    for (int j = 0; words[i][j]; ++j) {
      maskW[i] |= (1 << (words[i][j] - 'A'));
    }
  }
  for (int i = 8; i >= 0; --i) {
    maskW[i] |= maskW[i + 1];
  }

  ansL = 0;
  assert(brute(0, mask));
  ans[ansL] = 0;
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

