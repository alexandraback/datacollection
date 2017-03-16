#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

const string numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const char pivots[] = {'Z', 'O', 'W', 'H', 'U', 'F', 'X', 'S', 'G', 'N'};
const int order[] = {0, 6, 5, 4, 2, 7, 1, 8, 3, 9};

void solve() {
  string s;
  cin >> s;
  vi cnt(26, 0);
  for (char c: s) {
    cnt[c - 'A'] += 1;
  }
  vi ans;
  for (int i = 0; i < 10; i++) {
    int c = -1;
    for (int j = 0; j < 10; j++) {
      if (order[j] == i) {
        c = j;
        break;
      }
    }
    assert(c != -1);
    int ch = pivots[c] - 'A';
    while (cnt[ch] > 0) {
      ans.pb(c);
      for (char alp: numbers[c]) {
        cnt[alp - 'A'] -= 1;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    assert(cnt[i] == 0);
  }
  sort(all(ans));
  for (int x: ans)
    printf("%d", x);
  printf("\n");
}

int main() {
  int t = read();
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
    eprintf("Done with %d..\n", i);
    fflush(stdout);
  }
  return 0; 
}