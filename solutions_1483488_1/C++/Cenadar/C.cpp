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

char s[20];
string s1, s2;

int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
set<int> a;

int main() {
/*  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);/**/

  int T, A, B;
  scanf("%d\n", &T);
  rep(tt, T) {
    scanf("%d%d", &A, &B);
    sprintf(s, "%d", A);
    int len = strlen(s);

    int ans = 0;
    int k;

    FOR(i, A, B - 1) {
      a.clear();
      FOR(j, 1, len) {
        k = i % pow10[j] * pow10[len - j] + i / pow10[j];
        if (k > i && k <= B) a.insert(k);
      }
      ans += a.size();
    }

    printf("Case #%d: %d\n", tt + 1, ans);
  }

  return 0;
}
