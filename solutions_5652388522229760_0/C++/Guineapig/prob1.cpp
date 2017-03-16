#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> digits(int N)
{
  vector<int> res;
  if (N > 0)
  {
    while (N > 0)
    {
      res.push_back(N % 10);
      N /= 10;
    }
  }
  else
  {
    res.push_back(0);
  }
  reverse(res.begin(), res.end());
  return res;
}


int solve(int N)
{
  bool digits_seen[10];
  for (int i=0 ; i < 10 ; i++)
    digits_seen[i] = false;

  for (int k=1 ; ; k++)
  {
    int kN = k * N;

    vector<int> ds = digits(kN);
    for (int i=0 ; i < ds.size() ; i++)
      digits_seen[ds[i]] = true;

    bool all_seen = true;
    for (int i=0 ; i < 10 ; i++)
      if (!digits_seen[i])
      {
        all_seen = false;
        break;
      }

    if (all_seen)
      return kN;
  }
}


int main(int, char**)
{
  int T;
  cin >> T;

  for (int i_t=0 ; i_t < T ; i_t++)
  {
    int N;
    cin >> N;

    if (N > 0)
    {
      int res = solve(N);
      cout << "Case #" << (i_t + 1) << ": " << res << endl;
    }
    else
    {
      cout << "Case #" << (i_t + 1) << ": INSOMNIA" << endl;
    }
  }
}