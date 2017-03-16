#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iostream>
#include <cstring>

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

void solve() {
  string s;
  cin >> s;
  while (s.back() == '+')
    s.pop_back();
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    int j = i;
    while (j + 1 < s.size() && s[j + 1] == s[i]) {
      j++;
    }
    res += 1;
    i = j;
  }
  printf("%d\n", res);
}

int main() {
  int tc = read();
  for (int i = 1; i <= tc; i++) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}