#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#include <utility>
#include <queue>
#include <cassert>
#include <ctime>
using namespace std;

#define PB push_back
#define SZ size()
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define ITR(i, j, n) for(int i = j; i < (int)n; i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Pii pair <int, int>
#define Fr first
#define Sc second
#define Long long long
#define get(a) scanf("%d", &a)

int n, m, k, test, caseno = 1;

int main()
{
  READ("B-small-attempt0.in");
  WRITE("answer.out");
  scanf("%d", &test);

  while(caseno <= test) {
    scanf("%d %d %d", &n, &m, &k);

    int ret = 0;
    REP(i, n) {
      REP(j, m) {
        //cout << i << ' ' << j << ' ' << (i & j) << endl;
        if((i & j) < k)
          ret++;
      }
    }
    printf("Case #%d: %d\n", caseno++, ret);
  }

  return 0;
}
