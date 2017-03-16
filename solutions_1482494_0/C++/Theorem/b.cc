#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int values[2000][2];

struct pts {
  int stars;
};

long long score(int i, int current) {
  // none valid.
  if (values[i][0] < 0 && values[i][1] < 0) return -1;

  // first one valid
  if (values[i][1] < 0) {
    if (current < values[i][0]) return -1;
    else return values[i][0] + 1;
  }

  // second one valid
  if (values[i][0] < 0) {
    if (current < values[i][1]) return -1;
    return (1 + values[i][1]) * 100000000LL;
  }

  // two valid.
  if (current >= values[i][1]) return (1 + values[i][1]) * 100000000LL + (values[i][0] + 1);
  if (current >= values[i][0]) return values[i][0] + 1 + (values[i][1] + 1) * 10000;
  return -1;
}

void solve (int a_case) {

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> values[i][0] >> values[i][1];

  int stars = 0;

  int x = 0;
  while (stars < N*2) {

    int best = -1;
    for (int i = 0; i < N; ++i) {
      if ((best < 0 && score(i, stars) >= 0) || (best >= 0 && score(best, stars) < score(i, stars))) {
        best = i;
      }
    }

    if (best >= 0) {
      long long s = score(best, stars);
      if (s % 100000000LL) stars++, values[best][0] = -1;
      if (s / 100000000LL) stars++, values[best][1] = -1;
      ++x;
    } else {
      break;
    }
  }

  if (stars == N*2)
    printf("Case #%d: %d\n", a_case, x);
  else
    printf("Case #%d: Too Bad\n", a_case);
}

int main ()
{
  int n;
  string dummy;

  cin >> n;
  getline(cin, dummy);
  for (int i = 0; i < n; ++i) solve(i+1);

  return 0;
}



