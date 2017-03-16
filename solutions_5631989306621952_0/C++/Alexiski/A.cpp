#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ": ";
    string s1, s2; cin >> s1;
    for (int i=0; i<s1.length(); i++)
    {
      if (i)
      {
        if (s1[i] < s2[0])
          s2 = s2 + s1[i];
        else
          s2 = s1[i] + s2;
      }
      else
        s2 = s1[i];
    }
    cout << s2 << endl;
  }
  return 0;
}