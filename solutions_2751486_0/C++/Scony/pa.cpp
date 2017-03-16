#include <iostream>
#include <list>

using namespace std;

int main(int argc, char ** argv)
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      cout << "Case #" << tc << ": ";
      string s;
      int n;
      cin >> s >> n;
      int wndS = n;
      int wndL;
      int lb = 0;
      int sum = 0;

      for(wndL = 0; wndL < s.length()-wndS+1; wndL++)
	{
	  bool ok = true;
	  for(int i = wndL; i < wndL + wndS; i++)
	    if(s[i] == 'a' ||
	       s[i] == 'e' ||
	       s[i] == 'i' ||
	       s[i] == 'o' ||
	       s[i] == 'u')
	      {
		ok = false;
		break;
	      }
	  if(ok)
	    {
	      sum += 1;
	      sum += wndL - lb;
	      sum += s.length() - (wndL + wndS);
	      sum += (wndL - lb) * (s.length() - (wndL + wndS));
	      lb = wndL + 1;
	    }
	}
      cout << sum << endl;
    }
	
  return 0;
}
