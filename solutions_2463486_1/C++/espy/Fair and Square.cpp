#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std; 

typedef long long LL;

LL t, res, a, b;
vector <LL> v;

bool check (LL num) {
  LL pal = 0, tmp = num;
  while (tmp > 0) {
    pal = pal * 10 + tmp % 10;
    tmp /= 10;
  }
  return (num == pal);
}

void gen_pal(LL num, LL now, LL len) {
  if (now == len / 2 + len % 2) {
    LL tmp = num;
    if (len % 2) tmp /= 10;
    while (tmp > 0) {
      num = num * 10 + tmp % 10;
      tmp /= 10;
    }
    if (check(num * num)) v.push_back(num * num);
    return;
  }
  for (int i = 0; i < 10; i++) {
    if (i == 0 && now == 0) continue;
    gen_pal(num * 10 + i, now + 1, len);
  }
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
  scanf ("%lld", &t);
  v.push_back(1); v.push_back(4); v.push_back(9);
  for (LL i = 2; i < 9; i++) 
    gen_pal(0, 0, i);
  for (LL c = 0; c < t; c++) {
    scanf ("%lld%lld", &a, &b);
    res = 0;
    for (int i = 0; i < v.size(); i++) if (v[i] >= a && v[i] <= b) res++;
    printf ("Case #%lld: %lld\n", c + 1, res);
  }
	return 0;
}