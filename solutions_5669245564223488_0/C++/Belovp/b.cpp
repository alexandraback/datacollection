#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
vector<string> cars;
long long gcd(long long a, long long b)
{
    if (b == 0)
      return a;
    return gcd(b, a % b);
}
string tmp;
bool isvalid()
{
    int j;
    int mas[27];
    for (j = 0; j < 27; j++)
      mas[j] = 0;
    mas[tmp[0] - 'a']++;
    for (j = 1; j < tmp.size(); j++)
    {
        if (mas[tmp[j] - 'a'] > 0 && tmp[j - 1] != tmp[j])
          return false;
        mas[tmp[j] - 'a']++;
    }
    return true;
}
int solve()
{
    int j;
    vector<int> p;
    for (j = 0; j < cars.size(); j++)
      p.push_back(j);

    int count = 0;
    while (true)
    {
        tmp.clear();

        for (j = 0; j < p.size(); j++)
        {
            tmp += cars[p[j]];
        }
      //  cout << tmp << ' ' << isvalid() << endl;
        if (isvalid())
          count++;
        count %= 1000000007;
        if (!next_permutation(p.begin(), p.end()))
          break;
    }
    return count;
}
int main()
{
    ifstream cin("input_bsmall.in");
  ofstream cout ("output_bsmall.txt");
  int i, j, n, m, k, l, t;
  cin >> t;
  long long p, q, div;
  for (k = 1; k <= t; k++)
  {
      cars.clear();
      cin >> n;
      cars.resize(n);
      for (j = 0; j < n; j++)
        cin >> cars[j];
      cout << "Case #" << k << ": ";
      cout << solve() << endl;
  }

}
