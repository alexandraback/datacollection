#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;

const int BUFFER_SIZE = 1 * 1024;
const double EPS      = 10e-6;
const int MAX         = 1000;
const int INF         = 1 << 30;

char path[MAX];
bool V[11 * MAX];
int x, y;

bool find_path(int r, int c, int length)
{
  if (r == 0 && c == 0 && length == 0)
    return true;

  int sum = length * (length + 1) / 2;

  if (r > 0 && r > sum) return false;
  if (r < 0 && (-r) > sum) return false;
  if (c > 0 && c > sum) return false;
  if (c < 0 && (-c) > sum) return false;

  if (length > 0) {
    path[length] = 'N';
    if (find_path(r, c - length, length - 1))
      return true;
    path[length] = 'S';
    if (find_path(r, c + length, length - 1))
      return true;

    path[length] = 'W';
    if (find_path(r + length, c, length - 1))
      return true;

    path[length] = 'E';
    if (find_path(r - length, c, length - 1)) 
      return true;
  }

  return false;
}

int main(int argc, char *argv[])
{
  int t, tc, i, j;

  scanf("%d", &t);

  for (tc = 1; tc <= t; tc++) {
    scanf("%d %d", &x, &y);

    printf("Case #%d: ", tc);
    for (i = 1; i <= 500; i++) {
      if (find_path(x, y, i)) {
        for (j = 1; j <= i; j++)
          printf("%c", path[j]);
        printf("\n");
        break;
      }
    }

  }

  return EXIT_SUCCESS;
}

