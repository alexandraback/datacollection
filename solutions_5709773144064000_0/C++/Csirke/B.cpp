#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

int main(int argc, char *argv[])
{
  int T;
  double C, F, X, totaltime, timesofar, speed;

  scanf("%d", &T);
  for(int t = 0; t < T; ++t) {
    scanf("%lf%lf%lf", &C, &F, &X);
    speed = 2;
    totaltime = X / speed;
    timesofar = 0;

    while(1) {
      timesofar += C / speed;
      speed += F;

      if(timesofar + X/speed >= totaltime) {
        printf("Case #%d: %.7lf\n", t+1, totaltime);
        break;
      }

      totaltime = timesofar + X/speed;
    }
  }

  return 0;
}
