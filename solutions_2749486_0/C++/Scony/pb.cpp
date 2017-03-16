#include <iostream>
#include <list>

int abs(int x)
{
  return x >= 0 ? x : -x;
}

using namespace std;

int main(int argc, char ** argv)
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      cout << "Case #" << tc << ": ";
      int x, y;
      int mx = 0, my = 0;
      cin >> x >> y;
      string s = "";
      if(x < 0)
	for(int i = 0; i < abs(x); i++)
	  s += "EW";
      else
	for(int i = 0; i < abs(x); i++)
	  s += "WE";
      if(y < 0)
	for(int i = 0; i < abs(y); i++)
	  s += "NS";
      else
	for(int i = 0; i < abs(y); i++)
	  s += "SN";

      cout << s << endl;
    }
	
  return 0;
}
