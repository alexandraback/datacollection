#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

#define ll long long

void docase(int icase) {
  ll r, t;
  scanf("%lld %lld", &r, &t);

  ll a = r * 2 + 1;
  ll low = 0, mid, high = t;
  ll maxn = 0;
  ll sum;

  while (low <= high) {
    mid = (low + high) / 2;

    sum = (a + (a + (mid - 1) * 4)) * mid;
    sum /= 2;
    
    if (sum <= t) {
      low = mid + 1;
      maxn = max(maxn, mid);
    } else {
      high = mid - 1;
    }
  }

  printf("Case #%d: %lld\n", icase, maxn);
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
    docase(i + 1);

  return 0;
}
