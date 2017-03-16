#include <stdio.h>
#include <string.h>

#define MAX 1001

int p[MAX][3];

double calc(int n) {
  int sum = 0;
  int step = 0;
  int i;
  bool flag = false;
  while (sum < 2 * n) {
  flag = false;
  for (i = 0;i < n; ++i) {
    if (p[i][2] < 2 && p[i][1] <= sum) {
      ++step;
      sum += 2 - p[i][2];
      p[i][2] = 2;
      flag = true;
      break;
    }
  }
  if (flag) continue;
  int tmp = -1;
  int index = -1;
  for (i = 0;i < n; ++i) {
    if (p[i][2] < 1 && p[i][0] <= sum && p[i][1] > tmp) {
      tmp  = p[i][1]; 
      index = i;
    }
  }
  if (tmp != -1) {
      ++step;
      sum += 1;
      p[index][2] = 1;
      flag = true;
  }
  if (!flag) break;
  }
  if (sum != 2 * n) return -1;
  return step;
}

int main() {
  int t, n;
  scanf("%d", &t);
  for (int i = 1;i <= t; ++i) {
    scanf("%d", &n);
    for (int j = 0;j < n; ++j) {
      scanf("%d %d", &p[j][0], &p[j][1]);
      p[j][2] = 0;
    }
    int r = calc(n);
    if (r == -1) {
      printf("Case #%d: Too Bad\n", i);
    } else {
      printf("Case #%d: %d\n", i, r);
    }
  }
}
