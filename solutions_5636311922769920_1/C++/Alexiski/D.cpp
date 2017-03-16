#include <iostream>
using namespace std;

long long int number(int i, int k, int c)
{
  long long int res = 0;
  for (int j=0; j<c; j++)
  {
    res *= k;
    res += min(i + j, k - 1);
  }
  return res + 1;
}

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ":";
    int k, c, s; cin >> k >> c >> s;
    if (s*c >= k)
    {
      for (int i = 0; i < k; i += c)
      {
        cout << " " << number(i, k, c);
      }
    }
    else 
      cout << " IMPOSSIBLE";
    cout << endl;
  }
  return 0;
}