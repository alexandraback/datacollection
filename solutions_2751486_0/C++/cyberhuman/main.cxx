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
    string name;
    int n;
    in >> name >> n;

    int len = 0, width = name.length() - (n - 1);
    vector<int> jname(width);
    for (size_t i = 0; i < name.length(); ++i)
    {
      int cons = name[i] != 'a' && name[i] != 'o' && name[i] != 'e' && name[i] != 'u' && name[i] != 'i';
      len = cons ? len + cons : 0;
      if (n <= len)
        jname[i - (n - 1)] = 1;
    }

    long long nvalue = (long long)width * (width + 1) / 2;
    len = 0;
    for (size_t i = 0; i < jname.size(); ++i)
    {
      if (!jname[i])
        ++len; else
      {
        nvalue -= (long long)len * (len + 1) / 2;
        len = 0;
      }
    }
    nvalue -= (long long)len * (len + 1) / 2;
    /* 0000111100011000
     * 000022200002000  3 1
     * 00024420002200   4 2
     *
     * 0000111100011000 4 2
     * 000122210012100  5 3
     * 00134431013310   6 4
     * 0147874114641    7 5=12
     * 15bffb525aa5     12
     * xxxxxxxxxxx      11
     * xxxxxxxxxx       10
     * xxxxxxxxx        9
     * xxxxxxxx         8
     * xxxxxxx          7
     * xxxxxx           6
     * xxxxx            5
     * xxxx             4
     * xxx              3
     * xx               2
     * x                1
     */

    cout << "Case #" << 1 + ti << ": ";
    cout << nvalue;
    cout << endl;
  }
  return 0;
}

