#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

#define NUM_GENERATIONS 40
#define BUFFER_SIZE 100

using namespace std;

char str[BUFFER_SIZE + 10];

char *trim_line(char *str)
{
  return strtok(str, "\r\n");
}

template<typename T>
T gcd(T x, T y)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (x < y)
    swap(x, y);
  while (y > 0) {
    T r = x % y;
    x = y;
    y = r;
  }
  return x;
}

template<typename T>
int get_msb(T n)
{
  int k = 0;
  for (; n > 0; n >>= 1)
    k++;
  return k;
}

int solve_problem(int num_case)
{
  char *p;
  long long a, b;

  if (fgets(str, sizeof(str), stdin) == NULL)
    return 1;
  trim_line(str);
  p = strtok(str, "/");
  a = atoll(p);
  p = strtok(NULL, "/");
  b = atoll(p);

  long long g = gcd(a, b);
  a /= g;
  b /= g;
  int k = get_msb(b);
  --k;
  if (a > b || b != (1LL << k) || k > NUM_GENERATIONS) {
    printf("Case #%d: Impossible\n", num_case);
  } else {
    long long f = (1LL << NUM_GENERATIONS) / b;
    a *= f;
    b *= f;
    k = get_msb(a) - 1;
    printf("Case #%d: %d\n", num_case, NUM_GENERATIONS - k);
  }

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
