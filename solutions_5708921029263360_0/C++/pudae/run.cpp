#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
#include <tuple>

using namespace std;

std::vector<tuple<int, int, int>> solve1(int j, int p, int s, int k)
{
  std::vector<tuple<int, int, int>> ret;

  int cntA[10][10] = {0, };
  int cntB[10][10] = {0, };
  int cntC[10][10] = {0, };
  for (int j2 = 0; j2 < j; ++j2)
  {
    for (int p2 = 0; p2 < p; ++p2)
    {
      for (int s2 = 0; s2 < s; ++s2)
      {
        if (cntA[j2][p2] < k && cntB[p2][s2] < k && cntC[j2][s2] < k)
        {
          ret.push_back({j2 + 1, p2 + 1, s2 + 1});
          ++cntA[j2][p2];
          ++cntB[p2][s2];
          ++cntC[j2][s2];
        }
      }
    }
  }
  return ret;
}

int main()
{
  int t = 0;
  cin >> t;

  for (int i = 1; i <= t; ++i)
  {
    int j = 0; cin >> j;
    int p = 0; cin >> p;
    int s = 0; cin >> s;
    int k = 0; cin >> k;

    cout << "Case #" << i << ": ";
    if (j <= p && j <= s)
    {
      if (p <= s)
      {
        auto ret = solve1(j, p, s, k);
        cout << ret.size() << "\n";
        for (auto v : ret)
          cout << get<0>(v) << " " << get<1>(v) << " " << get<2>(v) << endl;
      }
      else
      {
        auto ret = solve1(j, s, p, k);
        cout << ret.size() << "\n";
        for (auto v : ret)
          cout << get<0>(v) << " " << get<2>(v) << " " << get<1>(v) << endl;
      }
    }
    else if (p <= j && p <= s)
    {
      if (j <= s)
      {
        auto ret = solve1(p, j, s, k);
        cout << ret.size() << "\n";
        for (auto v : ret)
          cout << get<1>(v) << " " << get<0>(v) << " " << get<2>(v) << endl;
      }
      else
      {
        auto ret = solve1(p, s, j, k);
        cout << ret.size() << "\n";
        for (auto v : ret)
          cout << get<2>(v) << " " << get<0>(v) << " " << get<1>(v) << endl;
      }
    }
    else // if (s <= j && s <= p)
    {
      if (j <= p)
      {
        auto ret = solve1(s, j, p, k);
        cout << ret.size() << "\n";
        for (auto v : ret)
          cout << get<1>(v) << " " << get<2>(v) << " " << get<0>(v) << endl;
      }
      else
      {
        auto ret = solve1(s, p, j, k);
        cout << ret.size() << "\n";
        for (auto v : ret)
          cout << get<2>(v) << " " << get<1>(v) << " " << get<0>(v) << endl;
      }
    }
  }

  return 0;
}
