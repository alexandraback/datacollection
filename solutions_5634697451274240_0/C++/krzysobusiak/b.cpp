#include <iostream>
#include <string>

using namespace std;

int solve(string s)
{
  int i = s.length() - 1;
  while (i >= 0 && s[i] == '+')
    i--;
  
  if (i < 0)
    return 0;
  
  int k = 1;
  while (i >= 1)
  {
    if (s[i] != s[i-1])
      k++;
    i--;
  }
  
  return k;
}  

int main()
{
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    string s;
    cin >> s;
    cout << "Case #" << i << ": " << solve(s) << endl;
  }
  return 0;
}
