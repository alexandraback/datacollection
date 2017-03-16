#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

double p[100005],prod[100005];
int T,A,B;

double solve() {
  scanf("%d %d", &A, &B);
  for (int i = 1; i <= A; i++) scanf("%lf", &p[i]);
  prod[0] = 1.0;
  for (int i = 1; i <= A; i++) prod[i] = prod[i - 1] * p[i];
  // Case 1
  double ans = min(prod[A] * (B - A + 1) + (1 - prod[A]) * (B - A + 1 + B + 1),1 + 1.0 * (B + 1));
  for (int del = 1; del <= A; del++)
    ans = min(ans,prod[A - del] * (2 * del + B - A + 1) + (1 - prod[A - del]) * (2 * del + B - A + 1 + B + 1));
  return ans;
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) printf("Case #%d: %.6lf\n", it, solve());
}
