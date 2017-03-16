#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long uint;

int main()
{
  uint t = 0;
  cin >> t;

  for ( uint i = 1; i <= t; i++ ) {
    double c, f, x;
    cin >> c >> f >> x;

    double time = 0.0;
    double cps = 2.0;
    uint farms = 0;

    while ( x / cps > (c / cps) + (x / (cps + f)) ) {
      time += c / cps;
      farms++;
      cps = 2.0 + f * farms;
    } // while

    time += x / cps;
    printf("Case #%ld: %.8f\n", i, time);
  } // for i

  return 0;
} // main
