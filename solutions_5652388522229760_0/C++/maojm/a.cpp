#include <iostream>
#include <cstdio>

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
      int x;
      cin >> x;
      cout << "Case #" << i + 1<< ": ";
      if (x == 0) cout << "INSOMNIA\n";
      else
	{
	  memset(a,0,sizeof(a));
	  int n = 0;
	  while (true)
	    {
	      n = n + x;
	      check(n);
	    
	  int s= 0;
	  for (int j= 0; j < 10; j++) s += a[j];
	   if (s == 10) break;
	    }cout << n << endl;
	    
	}
    }
}
