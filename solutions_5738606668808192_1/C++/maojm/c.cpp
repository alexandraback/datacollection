#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>

using namespace std;

int a[50];
long long s[1000];
long long d[50];

int main()
{
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  int t;
  cin >> t;
  int n;
  int j;
  cin >> n >> j;
  long long ss = 0;
  srand(time(0));
      cout << "Case #" << 1<< ": " <<  endl;
      n = n / 2;
      a[1] = 1;
      a[n] = 1;
      int i = 0;
      while (i < j)
	{
	  ss = 0;
	  for (int l = 2; l < n; l++)
	    a[l] = rand() % 2;
	  for (int l = 1; l <=n; l++)
	    { ss = ss * 10 + a[l];
	    }
	  bool f = false;
	  for (int l = 0; l < i; l++) if (s[l] == ss) f = true;
	  if (f == false)
	    {
	      long long u = 0;
	      for (int o = 2; o <= 10; o++)
		{
		  u = 0;
		  int p = 0;
		  for (int l = 1; l <= n; l++) u = u * o + a[l];
		  d[o] = u;
		}
	      if (f == false)
		{
		  s[i] = ss;
		  i++;
		  cout  << ss << ss ;
		  for (int l = 2; l <= 10; l++) cout<< " " << d[l];
		  cout << endl;
		}
	    }
	} 

      
}
