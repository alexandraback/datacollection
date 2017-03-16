#include <cassert>
#include <iostream>
#include <random>
#include <set>
using namespace std;

int FindDivisor(string const& s, int b)
{
  vector<int> v{2, 3, 5, 7, 11, 13};
  for (int p : v)
  {
    int res = 0;
    int current = 1;
    for (int i = s.size() - 1; i >= 0; --i)
    {
      if (s[i] == '1')
        res = (res + current) % p;
      current = (current * b) % p;
    }
    if (res == 0)
      return p;
  }
  return -1;
}

int main()
{
  int cases;
  int N, J;
  cin >> cases;
  assert(cases == 1);
  cin >> N >> J;

  cout << "Case #1:" << endl;

  std::default_random_engine generator;
  std::bernoulli_distribution distribution(0.5);

  auto GenerateCoin = [&]() -> string
  {
    string res = "1";
    for (int i = 0; i < N - 2; ++i)
      if (distribution(generator))
        res += "1";
      else
        res += "0";
    return res + "1";
  };

  set<string> seen;
  while (J > 0)
  {
    string coin = GenerateCoin();
    if (seen.count(coin))
      continue;

    vector<int> proof;

    for (int i = 2; i <= 10; ++i)
    {
      int p = FindDivisor(coin, i);
      if (p != -1)
        proof.push_back(p);
      else
        break;
    }

    if (proof.size() == 9)
    {
      seen.insert(coin);
      cout << coin;
      for (int p : proof)
        cout << " " << p;
      cout << endl;
      --J;
    }
  }
}
