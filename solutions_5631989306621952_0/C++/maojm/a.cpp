#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[10];

void check(int p)
{
  while (p != 0)
    {
      a[p % 10] = 1;
      p = p / 10;
    }
}


int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
    {
        string s;
      cin >> s;
      cout << "Case #" << i + 1<< ": ";
      int l = s.length();
      string ss = "";
      for (int j = 0; j < l; j++)
	{
	  if (j == 0) ss+= s[j];
	  else {
	    if (s[j] >= ss[0]) ss = s[j] + ss; else ss = ss + s[j]; 
	  }
	}
      cout << ss << endl;
    }
}
