#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

int main() {
  int T;
  scanf ("%d", &T);
  FOR(test,1,T+1) {
    double C, F, X;
    scanf ("%lf %lf %lf", &C, &F, &X);

    double sec = 0;
    double prod = 2;    
    while ((X / prod) > (C / prod + X / (prod + F))) {
      sec  += C / prod;
      prod += F;
    }
    sec += X / prod;
    printf("Case #%d: %.7lf\n", test, sec);
  }
  return 0;
}
