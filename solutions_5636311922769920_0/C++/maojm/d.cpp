#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main()
{
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);
  int t;
  cin >> t;
  int k,c,s;
  for (int i =0;i < t; i++)
    {
      cin >> k >> c >> s;
      cout << "Case #" << i+1<< ": ";
      if (s < ((k + c - 1)/c)) cout << "IMPOSSIBLE\n";
      else{
	for (int i = 0; i < (k+c-1)/c; i++)
	{
	  long long  s = 0;
	  for (int j = i* c+1; j < (i+1) *c+1; j++)
	    {
	      int y = j;
	      if (y >k) y= 1;
	      s = s * k + y-1;
	      //cout << y << " " << s << endl;
	    }
	  if (i != 0) cout << " "  << s+1; else cout << s+1;
	}
	cout << endl;
      }
    }
}
