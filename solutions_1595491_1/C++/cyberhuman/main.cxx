#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int i = 0; i < t; ++i)
  {
    int n, s, p;
    in >> n >> s >> p;
    int tt[n];
    for (int j = 0; j < n; ++j)
      in >> tt[j];
    sort(tt, tt + n, greater<int>());

    int c = 0;
    for (int j = 0; j < n; ++j)
    {
      int m, tp = tt[j];
      if (tp < 2 || tp > 28 || !((tp - 1) % 3) || !s || (tp + 4) / 3 > p)
        m = (tp + 2) / 3; else
      {
        m = (tp + 4) / 3;
        --s;
      }
      //cerr << "TP=" << tp << ", M=" << m << ", S=" << s << endl;
      if (m >= p)
        ++c;
    }

    cout << "Case #" << 1 + i << ": " << c << endl;
  }
  return 0;
}

