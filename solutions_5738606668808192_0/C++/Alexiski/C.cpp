#include <iostream>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ":";
    cout << endl;
    int n, j; cin >> n >> j;
    for (int ind = 0; ind < j; ind ++)
    {
      cout << "1";
      for (int i = 0; i < (n/2 - 1); i ++)
      {
        cout << ((ind & (1 << i)) ? "11" : "00");
      }
      cout << "1";
      
      for (int i = 2; i <= 10; i ++)
      {
        cout << " " << i+1;
      }
      cout << endl;
    }
  }
  return 0;
}