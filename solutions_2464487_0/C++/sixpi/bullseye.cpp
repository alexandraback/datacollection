#include "common.h"
#include <gmpxx.h>

using namespace std;

mpz_class max_rings(mpz_class &r, mpz_class &t)
{
  mpz_class n = ( sqrt((4*r*r - 4*r + 1) + (8 * t)) - (2 * r - 1) ) / 4;

  return n;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    exit(1);
  }

  ifstream ifs(argv[1]);

  int T;
  ifs >> T;

  mpz_class r, t;
  for (int i = 0; i < T; ++i)
  {
    ifs >> r >> t;

    cerr << r << " " << t << endl;

    cout << "Case #" << (i+1) << ": " << max_rings(r, t) << endl;
  }

  return 0;
}
