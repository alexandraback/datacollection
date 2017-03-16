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
using namespace std;

int r,n,m,k,T;
int arr[15];
set<int> s;

bool check(int a,int b,int c) {
  s.clear();
  int pass[3];
  pass[0] = a;  pass[1] = b;  pass[2] = c;
  for (int mask = 0; mask < (1 << n); mask++) {
    int prod = 1;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) prod *= pass[i];
    s.insert(prod);
  }
  for (int i = 0; i < k; i++)
    if (s.find(arr[i]) == s.end()) return false;
  return true;
}

void solveSet(int it) {
  for (int i = 0; i < k; i++) {
    scanf("%d", &arr[i]);
  }
  for (int a = 2; a <= m; a++)
    for (int b = a; b <= m; b++)
      for (int c = b; c <= m; c++)
        if (check(a,b,c)) {
	  printf("%d%d%d\n", a, b, c);
	  return;
	}
}

void solveCase(int it) {
  scanf("%d %d %d %d", &r, &n, &m, &k);
  printf("Case #%d:\n", it);
  for (int i = 0; i < r; i++) solveSet(i);
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
