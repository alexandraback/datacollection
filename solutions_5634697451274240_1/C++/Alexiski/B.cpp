#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ":";
    string s; cin >> s;
    int count = 0;
    char ch = '+';
    for (int i = s.length(); i > 0; i--)
    {
      if (s[i-1] != ch)
      {
        ch = s[i-1];
        count++;
      }
    }
    cout << count;
    cout << endl;
  }
  return 0;
}