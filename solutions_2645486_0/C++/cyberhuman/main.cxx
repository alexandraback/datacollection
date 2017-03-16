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
    int e, r, n;
    in >> e >> r >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      in >> v[i];

    vector<long long> gain(1 + e);
    for (int i = 0; i < n; ++i)
    {
      //cerr << i << ": ";
      vector<long long> next(1 + e);
      for (int j = r; j <= e; ++j)
      {
        for (int k = 0; k <= j; ++k)
          next[j] = max(next[j], gain[min(e, e - k + r)] + v[i] * k);
      }
      //for (int j = 0; j <= e; ++j)
      //  cerr << next[j] << " ";
      //cerr << endl;
      gain = next;
    }
    long long m = 0;
    for (int j = 0; j <= e; ++j)
      m = max(m, gain[j]);

    cout << "Case #" << 1 + ti << ": " << m;
    
    cout << endl;
  }
  return 0;
}

