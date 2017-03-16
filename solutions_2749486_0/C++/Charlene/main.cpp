
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <sstream>
#include <cmath>
using namespace std;

int X, Y;
void init()
{
  cin >> X >> Y;
}

string deal()
{
  string ret = "";
  while (X != 0)
  {
    if (X > 0) { X--; ret += "WE"; }
    if (X < 0) { X++; ret += "EW"; }
  }
  while (Y != 0)
  {
    if (Y > 0) { Y--; ret += "SN"; }
    if (Y < 0) { Y++; ret += "NS"; }
  }
  return ret;
}

int main()
{
  freopen("/Users/yingjiang/Downloads/B-small-attempt1-1.in.txt", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/3B-small.out", "w", stdout);

  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test)
  {
    init();
    cout << "Case #" << test << ": " << deal() << endl;
  }
  return 0;
}