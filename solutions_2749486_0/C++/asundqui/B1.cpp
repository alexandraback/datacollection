#include <iostream>
#include <string>
using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int case_num = 1; case_num <= T; ++case_num)
  {
    int X, Y;
    cin >> X >> Y;

    string pogo;

    while (X > 0)
    {
      pogo += "WE";
      --X;
    }
    while (X < 0)
    {
      pogo += "EW";
      ++X;
    }
    while (Y > 0)
    {
      pogo += "SN";
      --Y;
    }
    while (Y < 0)
    {
      pogo += "NS";
      ++Y;
    }

    cout << "Case #" << case_num << ": " << pogo << endl;
  }

  return 0;
}
