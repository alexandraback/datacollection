#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n;
char s[150];

map <char, char> trans;
const char *ans = "yaeoqzjuprmlsnlgcekidsxmvpnbrtidbhtwhxwffcayokujgvzq";

int main() {
  int m = strlen(ans);
  debug("%d\n", m);
  for (int i = 0; i < m; i += 2) {
    char c1 = ans[i], c2 = ans[i + 1];
    trans[c1] = c2;
  }

  scanf("%d", &n);
  gets(s);
  for (int q = 1; q <= n; q++) {
    gets(s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
      if (s[i] == ' ') continue;
      if (trans.count(s[i]))
        s[i] = trans[s[i]];
      else
        s[i] = s[i] - 'a' + 'A';
    }
    printf("Case #%d: %s\n", q, s);
  }
  

  return 0;
}
