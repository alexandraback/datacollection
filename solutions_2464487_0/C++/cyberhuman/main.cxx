#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <limits>
#include <gmpxx.h>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  cout << fixed << setprecision(6);
  ifstream in(argv[1]);
  int tt;
  in >> tt;
  for (int ti = 0; ti < tt; ++ti)
  {
    mpz_class zr, zt;
    in >> zr >> zt;
    mpz_class zrr(1 - 2 * zr);
    mpf_class fy(zrr * zrr + 8 * zt, 500);
    fy = (sqrt(fy) + zrr) * .25;
    cout << "Case #" << 1 + ti << ": ";
    mpz_class zy(floor(fy));
    cout << zy;
    cout << endl;
  }
  return 0;
}

