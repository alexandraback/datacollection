#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int solve(int a, int b)
{
  const int l = b - a + 1;
  bool recycle[l];
  int total = 0;

  for (int i = 0; i < l; ++i)
    recycle[i] = false;

  for (int i = 0; i < l; ++i)
  {
    if (recycle[i])
      continue;

    const int cc = a + i;
    int c = cc;
    char digits[10], n = 0;
    do
    {
      digits[n++] = c % 10;
      c /= 10;
    } while (c);
    //cerr << cc << ")";

    int d = 0;
    for (int j = 0; j < n; ++j)
    {
      c = 0;
      for (int k = 0; k < n; ++k)
        c = 10 * c + digits[(n + j - k - 1) % n];
      //cerr << " C:" << c;
      if (c > cc && c <= b)
      {
        if (!recycle[c - a])
        {
          ++d;
          //cerr << "+";
        }
        recycle[c - a] = true;
      }
    }
    d = d * (d + 1) / 2;
    //cerr << " = D:" << d << endl;
    total += d;
    //if (total < 0)
    //  cerr << "overflow!!!" << endl;
  }
  return total;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int i = 0; i < t; ++i)
  {
    int a, b;
    in >> a >> b;
    cout << "Case #" << 1 + i << ": " << solve(a, b) << endl;
  }
  return 0;
}

