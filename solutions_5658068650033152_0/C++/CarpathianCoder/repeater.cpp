#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAX_N 100
#define MAX_LENGTH 100
#define BUFFER_SIZE 100

using namespace std;

char str[BUFFER_SIZE + 10];
bool point[MAX_N][MAX_N];

char *trim_line(char *str)
{
  return strtok(str, "\r\n");
}

bool compare_vectors(const vector< pair<int, int> > &x, const vector< pair<int, int> > &y)
{
  if (x.size() != y.size()) {
    return false;
  }
  for (size_t i = 0; i < x.size(); i++) {
    if (x[i].first != y[i].first) {
      return false;
    }
  }
  return true;
}

int solve_problem(int num_case)
{
  char *p;
  int n, m, k;

  if (fgets(str, sizeof(str), stdin) == NULL)
    return 1;
  trim_line(str);
  p = strtok(str, " ");
  n = atoi(p);
  p = strtok(NULL, " ");
  m = atoi(p);
  p = strtok(NULL, " ");
  k = atoi(p);

  int total = n * m;
  int mask = 1 << total;
  int result = total;
  for (int i = 1; i <= mask; i++) {
    memset(point, 0, sizeof(point));
    int num_bits = 0;
    for (int j = 0, b = i; j < total; j++, b >>= 1) {
      if (b & 1) {
        point[j / m][j % m] = true;
        ++num_bits;
      }
    }
    int num_good = 0;
    for (int j = 0; j < total; j++) {
      int bad = false;
      int x = j / m;
      int y = j % m;
      bool ok = false;
      for (int l = x; l >= 0; l--)
        if (point[l][y]) {
          ok = true;
          break;
        }
      if (!ok) {
        bad = true;
      }
      ok = false;
      for (int l = x; l < n; l++)
        if (point[l][y]) {
          ok = true;
          break;
        }
      if (!ok) {
        bad = true;
      }
      ok = false;
      for (int l = y; l >= 0; l--)
        if (point[x][l]) {
          ok = true;
          break;
        }
      if (!ok) {
        bad = true;
      }
      ok = false;
      for (int l = y; l < m; l++)
        if (point[x][l]) {
          ok = true;
          break;
        }
      if (!ok) {
        bad = true;
      }
      if (!bad)
        ++num_good;
    }
    if (num_good >= k) {
      result = min(result, num_bits);
    }
  }

  //printf("%d %d %d\n", n, m, k);
  printf("Case #%d: %d\n", num_case, result);

  return 0;
}

int main()
{
  int num_tests;

  if (fgets(str, sizeof(str), stdin) == NULL)
    return 1;
  num_tests = atoi(str);

  for (int i = 0; i < num_tests; i++)
    solve_problem(i + 1);

  return 0;
}
