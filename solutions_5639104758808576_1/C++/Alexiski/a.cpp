#include <iostream>
#include <string>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int k; string str; cin >> k >> str;
    int s = 0;
    int a = 0;
    for (int i=0; i<=k; i++)
    {
      if (s < i)
      {
        a += i-s;
        s = i;
      }
      s += str[i]-'0';
    }
    cout << "Case #" << ii+1 << ": " << a << endl;
  }
  return 0;
}
