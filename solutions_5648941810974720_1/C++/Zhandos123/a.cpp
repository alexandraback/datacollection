//#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define LL long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 2e3 + 7;      
const int mod = 1e9 + 7;

int n;
char s[N];
int cnt[1000], ans[11];

void solve() {
  scanf("\n%s", s);
  n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  memset(ans, 0, sizeof ans);

  forn(i, n) cnt[s[i]]++;

  ans[0] = cnt['Z'];
  cnt['E'] -= cnt['Z'];
  cnt['R'] -= cnt['Z'];
  cnt['O'] -= cnt['Z'];
  cnt['Z'] = 0;

  ans[6] = cnt['X'];
  cnt['S'] -= cnt['X'];
  cnt['I'] -= cnt['X'];
  cnt['X'] = 0;

  ans[8] = cnt['G'];
  cnt['E'] -= cnt['G'];
  cnt['I'] -= cnt['G'];
  cnt['H'] -= cnt['G'];
  cnt['T'] -= cnt['G'];
  cnt['G'] = 0;

  ans[2] = cnt['W'];
  cnt['T'] -= cnt['W'];
  cnt['O'] -= cnt['W'];
  cnt['W'] = 0;

  ans[3] = cnt['T'];
  cnt['H'] -= cnt['T'];
  cnt['R'] -= cnt['T'];
  cnt['E'] -= cnt['T'];
  cnt['E'] -= cnt['T'];
  cnt['T'] = 0;

  ans[4] = cnt['R'];
  cnt['F'] -= cnt['R'];
  cnt['O'] -= cnt['R'];
  cnt['U'] -= cnt['R'];
  cnt['R'] = 0;

  ans[5] = cnt['F'];
  cnt['I'] -= cnt['F'];
  cnt['V'] -= cnt['F'];
  cnt['E'] -= cnt['F'];
  cnt['F'] = 0;

  ans[1] = cnt['O'];
  cnt['N'] -= cnt['O'];
  cnt['E'] -= cnt['O'];
  cnt['O'] = 0;

  ans[7] = cnt['S'];
  cnt['E'] -= cnt['S'];
  cnt['V'] -= cnt['S'];
  cnt['E'] -= cnt['S'];
  cnt['N'] -= cnt['S'];
  cnt['S'] = 0;

  ans[9] = cnt['I'];
  forn(i, 10) 
    forn(j, ans[i])
      printf("%d", i);
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("A-large (2).in", "r", stdin);
  freopen("A-large (2).out", "w", stdout);
  #endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
      printf("Case #%d: ", i);
      solve();
      printf("\n");
    }
  return 0;
}
