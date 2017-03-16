#include <iostream>
#include <vector>

using namespace std;


unsigned long long translate_linear(int K, int C, vector<int> coords)
{
  unsigned long long unit = 1;
  unsigned long long res = 1;
  for (int i=C-1 ; i >= 0 ; i--)
  {
    res += unit * coords[i];
    unit *= K;
  }
// cout << "-----------------------------------" << endl;
// for (int i=0 ; i < coords.size() ; i++)
//   cout << coords[i] << " ";
// cout << endl << res << endl;
  return res;
}


vector<unsigned long long> solve(int K, int C, int S)
{
  int min_S = (K + C - 1) / C;
  vector<unsigned long long> res;
  if (S >= min_S)
  {
    for (int i=0 ; i < min_S ; i++)
    {
      vector<int> coords(C);
      for (int j=0 ; j < C ; j++)
      {
        int coord = i * C + j;
        if (coord >= K)
          coord = 0;
        coords[j] = coord;
      }
      res.push_back(translate_linear(K, C, coords));
    }
  }
  return res;
}


int main(int, char **)
{
  int T;
  cin >> T;

  for (int i_t=0 ; i_t < T ; i_t++)
  {
    int K, C, S;
    cin >> K >> C >> S;

    vector<unsigned long long> res = solve(K, C, S);

    cout << "Case #" << (i_t + 1) << ":";
    if (res.size() == 0)
    {
      cout << " IMPOSSIBLE";
    }
    else
    {
      for (int i=0 ; i < res.size() ; i++)
        cout << " " << res[i];
    }
    cout << endl;
  }

  return 0;
}