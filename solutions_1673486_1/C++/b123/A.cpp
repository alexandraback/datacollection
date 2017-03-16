#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>

using namespace std;

typedef unsigned long long Ullong;
typedef unsigned int uint;

int main()
{

  unsigned int T, A, B;

  cin >> T;

  for (uint t = 0; t < T; t++)
  {
    cin >> A >> B;

    double P[A];

    for (uint a = 0; a < A; a++)
      cin >> P[a];

    double E[A];

    for (uint N = 0; N < A; N++)
    {
      double pp = 1;
      for (uint n = 0; n < A-N; n++)
        pp *= P[n];
      E[N] = pp*(2*N+B-A+1) + (1-pp)*(2*N+2*B-A+2);
    }

    double ans = B + 2;

    for (uint N = 0; N < A; N++)
      if (ans > E[N])
        ans = E[N];

    cout << "Case #" << t+1 << ": ";
    printf("%.6f",ans);
    cout << endl;
  }
  return 0;
}

