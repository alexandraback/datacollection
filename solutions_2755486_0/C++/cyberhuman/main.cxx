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
    int N;
    in >> N;
    vector<int> d(N), n(N), w(N), e(N), s(N), dd(N), dp(N), ds(N);
    vector<int> wall(2000);
    const int center = 1000;
    int count = 0;
    for (int i = 0; i < N; ++i)
      in >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
    while (true)
    {
      int day = -1;
      for (int i = 0; i < N; ++i)
        if (0 < n[i] && (0 > day || day > d[i]))
          day = d[i];
      if (0 > day)
        break;
      for (int i = 0; i < N; ++i)
        if (0 < n[i] && day == d[i])
          for (int pp = w[i]; pp < e[i]; ++pp)
            if (wall[pp + center] < s[i])
            {
              ++count;
              break;
            }
      for (int i = 0; i < N; ++i)
        if (0 < n[i] && day == d[i])
        {
          for (int pp = w[i]; pp < e[i]; ++pp)
            if (wall[pp + center] < s[i])
              wall[pp + center] = s[i];
          --n[i];
          d[i] += dd[i];
          w[i] += dp[i];
          e[i] += dp[i];
          s[i] += ds[i];
        }
    }
    
    cout << "Case #" << 1 + ti << ": ";
    cout << count;
    cout << endl;
  }
  return 0;
}

