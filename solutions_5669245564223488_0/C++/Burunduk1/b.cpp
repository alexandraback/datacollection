/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.11
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define zero(a) memset(a, 0, sizeof(a))
#define fill(a, x) memset(a, x, sizeof(a))
#define IS(a, i) (((a) >> (i)) & 1)

typedef long long ll;

const int MOD = (int)1e9 + 7;

int n, p[26], was[26], cnt[26], fact[27];
char s[1001];

inline int mul( int a, int b ) { return (ll)a * b % MOD; }
inline void add( int a, int b ) { if ((a += b) >= MOD) a -= MOD; }

void solve()
{
  scanf("%d", &n);
  fill(p, -1), zero(cnt), zero(was);

  int bad = 0;
  forn(i, n)
  {
    scanf("%s", s);
    int n = strlen(s);
    forn(i, n)
      was[s[i] -= 'a'] = 1;

    int one = 1;
    forn(i, n - 1)
      if (s[i] != s[i + 1])
        one = 0, bad |= (p[s[i]] != -1), p[s[i]] = s[i + 1];
    if (one)
      cnt[s[0]]++;
  }
  forn(i, 26)
    if (was[i])
    {
      int v = i;
      forn(j, 26)
        if (v != -1)
          v = p[v];
      bad |= (v != -1);
    }

  if (bad)
    printf("0\n");
  else
  {
    int num = 0;
    forn(i, 26)
      num += (was[i] && p[i] == -1);

    int ans = fact[num];
    forn(i, 26)
      ans = mul(ans, fact[cnt[i]]);
    printf("%d\n", ans);
  }
}

int main()
{
  fact[0] = 1;
  forn(i, 26)
    fact[i + 1] = mul(fact[i], i + 1);

  int tn;
  scanf("%d", &tn);
  forn(i, tn)
  {
    printf("Case #%d: ", i + 1);
    //fprintf(stderr, "Case #%d : ", i + 1);
    solve();
    //fprintf(stderr, "OK\n");
  }
  return 0;
}
