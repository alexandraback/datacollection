#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>

using namespace std;

string ll2str(long long in)
{
  char buff[32];
  sprintf(buff,"%lld",in);
  return string(buff);
}

bool ispal(long long in)
{
  string topal = ll2str(in);
  int l = 0;
  int r = topal.length() - 1;
  while(l < r)
    {
      if(topal[l] != topal[r])
	return false;
      l++;
      r--;
    }
  return true;
}

bool isfns(long long in)
{
  if(ispal(in) && ispal(in*in))
    return true;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  list<long long> points;
  for(long long i = 1; i*i <= 100000000000000; i++)
    if(isfns(i))
      points.push_back(i*i);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      long long a,b;
      cin >> a >> b;

      long long cnt = 0;
      for(list<long long>::iterator i = points.begin(); i != points.end(); i++)
	if(a <= *i && *i <= b)
	  cnt++;

      cout << "Case #" << tc << ": ";
      cout << cnt << endl;
    }
  return 0;
}
