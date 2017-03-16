#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
#define maxn 10005
using namespace std;

int maxi[maxn],mini[maxn],c[maxn];
int E,R,n;
int T;
long long ret;

inline void recurse(int low,int high) {
  if (low > high) return;
  int pos = low;
  for (int i = low; i <= high; i++)
    if (c[i] > c[pos]) pos = i;
  ret += 1LL * (maxi[pos] - mini[pos]) * c[pos];
  if (low == high) return;
  int eval = maxi[pos];
  for (int i = pos - 1; i >= low; i--) {
    eval -= R;
    if (eval < 0) break;
    mini[i] = max(mini[i],eval);
  }
  eval = mini[pos];
  for (int i = pos + 1; i <= high; i++) {
    eval += R;
    if (eval > E) break;
    maxi[i] = min(maxi[i],eval);
  }
  recurse(low,pos - 1);
  recurse(pos + 1,high);
}

void solveCase(int it) {
  scanf("%d %d %d", &E, &R, &n);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < n; i++) maxi[i] = E,mini[i] = 0;
  ret = 0;
  recurse(0,n - 1);
  printf("Case #%d: %lld\n", it, ret);
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
