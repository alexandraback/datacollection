#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define s(x) scanf("%d", &x)
#define ld long double

ld read() {
  double res;
  scanf("%lf", &res);
  return res;
}

int main() {
  int T; s(T);
  for (int i=1; i <= T; i++) {
    printf("Case #%d: ", i);
    ld C = read();
    ld F = read();
    ld X = read();
    
    int MaxCookieFarms = (int)(X / C);
    ld MinTime = X / 2;
    ld timeToAcquire = 0;
    ld currentSpeed = 2;
    for (int cf=1; cf <= MaxCookieFarms; cf++) {
      timeToAcquire += C / currentSpeed;
      currentSpeed += F;
      ld timeToFinish = timeToAcquire + X / currentSpeed;
      MinTime = min(MinTime, timeToFinish);
    }
    printf("%.7lf\n", (double)MinTime);
  }
}
