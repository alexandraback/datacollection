#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define mem(a, val) memset((a), val, sizeof(a))
#define inf    1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi acos(-1.0)
#define sqr(a) ((a)*(a))
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef vector< pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

char
  *s[] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
  };

char
  *a[] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
  };

char f[128];
bool used[128] = {};

int main() {
/*  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);/**/

  rep(i, 3)
    while(*s[i]) {
      f[*s[i]] = *a[i];
      used[*a[i]] = true;
      ++s[i], ++a[i];
    }
  f['z'] = 'q';
  f['q'] = 'z';
/*  FOR(i, 'a', 'z') printf("%c: %c\n", i, f[i]);
  FOR(i, 'a', 'z') printf("%c: %d\n", i, used[i]);*/

  string s;
  int T;
  scanf("%d\n", &T);
  rep(t, T) {
    getline(cin, s);
    fe(i, s) s[i] = f[s[i]];
    printf("Case #%d: %s\n", t + 1, s.c_str());
  }

  return 0;
}
