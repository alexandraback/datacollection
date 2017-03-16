#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define REPN(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define RREPN(i, a, b) for(int i = (int)(b); i >= (int)(a); i--)
#define REP(i, n) REPN(i, 0, n)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

const int inf = INT_MAX / 3;
const double eps = 1e-8;

bool novow(char c) {
  return !(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

int main() {

  int T;
  scanf("%d", &T);

  REPN(tc, 1, T + 1) {
    char buf[1000009];
    int N;
    scanf("%s %d", buf, &N);

    int len = strlen(buf);
    int res = 0;
    int c = 0;
    int b = 0;
    REP(i, len) {
      c = novow(buf[i]) ? c + 1 : 0;
      if(c >= N) {
        res += ((i + 1) - b - (c - 1)) * (len - (i + 1) + 1);
        // printf("%d %d %d %d\n", res, ((i + 1) - b - (c - 1)) + (len - (i + 1)), c, b);      
        b = i + 1 - c + 1;
        c--;
      } else {
        // printf("0\n");
      }
    }

    printf("Case #%d: %d\n", tc, res);
  }

  return 0;
}
