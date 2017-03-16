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


bool palidrome(long long n)
{
  int l, i, j;
  char num[20];
  sprintf(num, "%lld", n);
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
  int t, tc, ans;
  long long i, A, B;
  vector<long long> FS;

  for (i = 1; i <= 12000000; i++) {
    if (palidrome(i) && palidrome(i * i)) {
      FS.push_back(i * i);
    }
  }

  scanf("%d", &t);

  for (tc = 1; tc <= t; tc++) {
    scanf("%lld %lld", &A, &B);

    ans = 0;
    for (int j = 0; j < int(FS.size()); j++)
      if (FS[j] >= A && FS[j] <= B)
        ans++;

    printf("Case #%d: %d\n", tc, ans);
  }

  return EXIT_SUCCESS;
}

