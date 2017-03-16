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
const int MAX         = 100;
const int INF         = 1 << 30;

bool palidrome(int n)
{
  int l, i, j;
  char num[10];
  sprintf(num, "%d", n);
  l = strlen(num);

  i = 0;
  j = l - 1;

  while (i < j) {
    if (num[i] != num[j])
      return false;
    i++;
    j--;
  }

  return true;
}

int main(int argc, char *argv[])
{
  int t, tc, i, A, B, sq, count;

  scanf("%d", &t);

  for (tc = 1; tc <= t; tc++) {
    scanf("%d %d", &A, &B);

    count = 0;
    for (i = A; i <= B; i++) {
      if (palidrome(i)) {
        sq = int(sqrt(i) + 0.1);
        if (palidrome(sq) && sq * sq == i)
          count++;
      }
    }

    printf("Case #%d: %d\n", tc, count);
  }

  return EXIT_SUCCESS;
}

