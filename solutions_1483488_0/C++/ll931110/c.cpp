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
#define maxn 2000000
using namespace std;

int T;
int best[maxn + 3];
int p10[8];

int main() {
  p10[0] = 1;
  for (int i = 1; i < 8; i++) p10[i] = p10[i - 1] * 10;
  for (int i = 1; i <= maxn; i++) {
    best[i] = i;
    int num = 0,x = i;
    while (x) {
      num++;
      x /= 10;
    }
    x = i;
    for (int j = 0; j < num; j++) {
      int last = x % 10;  x /= 10;  x += p10[num - 1] * last;
      best[i] = max(best[i],x);
    }
  }
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) {
    int a,b;
    scanf("%d %d", &a, &b);
    long long ret = 0;
    map<int,int> mp;
    for (int i = a; i <= b; i++) {
      ret += mp[best[i]];
      mp[best[i]]++;
    }
    printf("Case #%d: %lld\n", it, ret);
  }
}
