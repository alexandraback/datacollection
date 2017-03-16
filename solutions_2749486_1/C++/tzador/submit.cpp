#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int sumup(int n) {
  return n * (n + 1) / 2 ;
}
int dist(int x, int y) {
  return abs(x) + abs(y);
}
char path[1000000];
void walk(int x, int y, int n);
bool subwalk(int x, int y, int n, char dir) {
  int p = sumup(n - 1);
  if (dist(x, y) <= p) {
    path[n - 1] = dir;
    walk(x, y, n - 1);
    return true;
  }
  return false;
}
void walk(int x, int y, int n) {
  if (n == 0)
    return;
  if (subwalk(x - n, y, n, 'E'))
    return;
  if (subwalk(x + n, y, n, 'W'))
    return;
  if (subwalk(x, y - n, n, 'N'))
    return;
  if (subwalk(x, y + n, n, 'S'))
    return;
  for (int i = 0; i < n; i++)
    path[i] = 'X';
}
char* solve(int x, int y) {
  int d = dist(x, y);
  int n = 1;
  while (sumup(n) < d || d % 2 != sumup(n) % 2) {
    n++;
  }
  walk(x, y, n);
  path[n] = '\0';
  return path;
}
bool validate(int x, int y, char* path) {
  int s = 1;
  int cx = 0;
  int cy = 0;
  while (path[s - 1] != '\0') {
    char p = path[s - 1];
    if (p == 'N')
      cy += s;
    if (p == 'S')
      cy -= s;
    if (p == 'E')
      cx += s;
    if (p == 'W')
      cx -= s;
    s++;
  }
  if (cx == x && cy == y) {
    return true;
  } else {
    printf("!!!!!!!!!!!!!!!!!!!!!!%d %d ERROR %d %d %s\n", x, y, cx, cy, path);
    return false;
  }
}
int main() {
  char output_buf[1000]; strcpy(output_buf, "codejam/2013/1C/B//solution.cpp"); char *output_pos = strstr(output_buf, "solution.cpp"); strcpy(output_pos, "large.out"); freopen(output_buf, "w", stdout);
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    int x, y;
    scanf("%d %d\n", &x, &y);
    char *sol = solve(x, y);
    printf("Case #%d: %s\n", t, sol);
    if (!validate(x, y, sol))
      fprintf(stderr, "Wrong %d %d: %s\n", x, y, sol);
  }
}
