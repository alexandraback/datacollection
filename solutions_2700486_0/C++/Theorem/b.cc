#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int height (int n) { return n*2-1; }
int total (int n) { return height(n)*n; }

int get_n (int x, int y) { return 1 + (x+y)/2; }

unsigned long long int fact (unsigned long long int n) {
  unsigned long long int f = 1;
  for (unsigned long long int i = 2; i <= n; ++i) f *= i;
  return f;
}

unsigned long long int comb (unsigned long long int p, unsigned long long int k) {
  unsigned long long int n = p + k;

  return fact(n) / fact(p) / fact(k);
}

#define dprintf(...) printf(__VA_ARGS__)
#define dprintf(...) 

void solve (int a_case) {
  int X, Y, N;
  cin >> N >> X >> Y;

  X = abs(X);
  Y = abs(Y);

  int n = get_n(X, Y);
  int start = X == 0 ? total(n) : (total(n-1) + 1 + Y);
  int end   = X == 0 ? total(n) : (total(n-1) + height(n) + Y);

  double p;

  if (N < start) p = 0;
  else if (N > end) p = 1;
  else {
    unsigned long long int fallers = N - total(n-1);
    double combos = 0.0; // fallers*2;//comb() (1 << fallers);
    double failers = 0.0;

    dprintf("  Falling: %d\n", fallers);

    unsigned long long MAXIMUM = std::min(fallers, (unsigned long long int)height(n)-1);
    unsigned long long MINIMUM = fallers - MAXIMUM;

    if (MAXIMUM < MINIMUM) {
     int t = MAXIMUM;
     MAXIMUM = MINIMUM;
     MINIMUM = t;
    }

    dprintf("max %llu min %llu\n", MAXIMUM, MINIMUM);
    for (unsigned long long int i = MINIMUM; i <= MAXIMUM; ++i) {
      dprintf("  this %llu other %llu\n", i, fallers - i);
      combos += comb(i, fallers - i);
    }


    for (int i = 0; i <= Y; ++i) {
      unsigned long long int this_side = i;
      unsigned long long int other_side = fallers - this_side;


      dprintf("  This side: %llu. Other side: %llu\n", this_side, other_side);

      if (other_side < height(n)) {
        dprintf("     = %llu\n", comb(this_side, other_side));
        failers += comb(this_side, other_side);
      }
    }

    dprintf("  Prob = 1 - %lf / %lf = %lf\n", failers, combos, 1 - failers/combos);
    p = (N + 1 - start) * 1.0 / (end + 1 - start);
    p = 1 - failers/combos;
  }
 
  dprintf("Case #%d: (%d, %d): %d (%d). %d -> %d = %lf\n\n\n", a_case, X, Y, n, total(n), start, end, p);

  printf("Case #%d: %lf\n", a_case, p);
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

