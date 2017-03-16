#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main()
{
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  int t;
  cin >> t;
  string s;
  getline(cin,s);
  for (int i =0;i < t; i++)
    {
      getline(cin,s);
      int l = s.length();
      int y = 1;
      int o = 0;
      for (int j = l-1; j >=0; j--)
	{
	  int x;
	  if (s[j] == '-') x =0; else x = 1;
	  if (x != y)
	    {
	      o++;
	      y = x;
	    }
	}
      cout << "Case #" << i+1<< ": " << o << endl;
    }
}
