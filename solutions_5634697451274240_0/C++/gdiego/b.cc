#include <string>
#include <iostream>
using namespace std;
int solve(string s)
{
  int solution = 0;
  for (int x = 0; x < s.size(); x++)
  {
    if (s[x] == '-' && s[x+1] != '-')
    {
      solution += 2;
    }
  }

  if (s[0] == '-')
  {
    solution--;
  }

  return solution;
}
int main()
{
  int n;
  string str;
  cin >> n;
  for (int x = 1; x <= n; x++)
  {
    cin >> str;
    cout << "Case #" << x << ": " << solve(str) << endl;
  }

  return 0;
}

