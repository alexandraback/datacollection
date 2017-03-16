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
    int x, y;
    in >> x >> y;

    int count = 0;
    cout << "Case #" << 1 + ti << ": ";
    int dir = 0 < x ? 1 : -1;
    while (x)
    {
      cout << (0 < dir ? "E" : "W");
      //cout << "x=" << x << ",dir=" << dir << endl;
      x -= dir;
      if (0 < dir)
        dir = -dir - 1; else
        dir = -dir + 1;
      ++count;
    }
    if (0 > dir)
      dir = -dir;
    if (0 < y)
      dir = -dir;
    while (y)
    {
      cout << (0 < dir ? "N" : "S");
      //cout << "y=" << y << ",dir=" << dir << endl;
      y -= dir;
      if (0 < dir)
        dir = -dir - 1; else
        dir = -dir + 1;
      ++count;
    }
    
    cout << endl;
    cerr << "count=" << count << endl;
  }
  return 0;
}

