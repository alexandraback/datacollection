#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 22;
int num[MAX], n, sum;

const int LIM = 110000 * MAX;
int seen[LIM];

bool isset(int num, int ind) {
  return (bool) (num & (1<<ind));
}

int sumall(int set) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (isset(set, i)) sum += num[i];
  }
  return sum;
}

int print(int set) {
  bool first = true;
  for (int i = 0; i < n; i++) {
    if (isset(set, i)) {
      if (first) {
        first = false;
      } else {
        printf(" ");
      }
      printf("%d", num[i]);
    }
  }
  printf("\n");
}

void solve() {
  int lim = (1<<n);
  for (int i = 1; i < lim; i++) {
    int sum = sumall(i);
    if (seen[sum]) {
      print(seen[sum]);
      print(i);
      return;
    } else {
      seen[sum] = i;
    }
  }
  printf("Impossible\n");
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    scanf("%d", &n);
    sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
      sum += num[i];
    }
    //printf("%d %d\n", sum, LIM);
    for (int i = 0; i <= sum; i++) {
      seen[i] = 0;
    }
    printf("Case #%d:\n", t);
    solve();
  }
  return 0;
}
