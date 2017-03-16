#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maximum = 1000000;

int sum[maximum];

int calc(int);

void solve (int a_case) {
  int directions[maximum];

  int X, Y;
  cin >> X >> Y;

  int x = X, y = Y;
  int jumps = calc(abs(X)+abs(Y));
  int j = jumps;

  while (j || (x||y)) {
    int xs[4], ys[4];
    xs[0] = x-j, ys[0] = y;
    xs[1] = x+j, ys[1] = y;
    xs[2] = x,   ys[2] = y-j;
    xs[3] = x,   ys[3] = y+j;

    int best = 0;
    for (int i = 0; i < 4; ++i) {
      if (abs(xs[i])+abs(ys[i]) < abs(xs[best])+abs(ys[best])) best=i;
    }


    x = xs[best];
    y = ys[best];

    if (j == 1)
    fprintf(stderr, "%d walk %d === %d %d\n", j, best, x, y);

    directions[j] = best;
    --j;
  }



  printf("Case #%d: ", a_case);
  for (int i = 1; i <= jumps; ++i) {
    char s[] = "EWNS";
    printf("%c", s[directions[i]]);
  }

  puts("");
}


void make () {
  sum[0] = 0;
  fprintf(stderr, "making\n");
  for (int i = 1; sum[i-1] < 100*maximum; ++i) {
    sum[i] = sum[i-1] + i;
  }
}

int calc (int s) {
  fprintf(stderr, "how many jumps?\n");
  int current[2] = { 3, 1 };
  int delta[2]   = { 1, 1 };

  fprintf(stderr, "-- %d\n", s);
  while (sum[current[s%2]] < s) {
    fprintf(stderr, "current: %d (%d)\n", current[s%2], sum[current[s%2]]);
    current[s%2] += delta[s%2];
    delta[s%2] = 4 - delta[s%2];
  }

  int jumps = current[s%2];

  fprintf(stderr, "jumps(%d): %d (%d)\n", s, jumps, sum[jumps]);
  return jumps;
}

int main ()
{
  int n;
  string dummy;

  make();

  cin >> n;
  getline(cin, dummy);
  for (int i = 0; i < n; ++i) solve(i+1);

  return 0;
}

