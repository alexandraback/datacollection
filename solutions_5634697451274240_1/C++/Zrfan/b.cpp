#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int ii = 1; ii <=t; ++ii)
  {
    cout << "Case #" << ii << ": ";
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 1; i < str.size(); ++i)
    {
      if (str[i] != str[i - 1])
        ans ++;
    }
    if (str[str.size()-1] == '-')
      ans ++;
    cout << ans << endl;
  }
  return 0;
}
