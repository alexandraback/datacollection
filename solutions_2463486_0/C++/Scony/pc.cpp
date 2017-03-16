#include <iostream>
#include <stdio.h>
#include <math.h>

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
  if(ispal(in))
    {
      long long sq = sqrt(in);
      if(sq*sq == in && ispal(sq))
	return true;
    }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      long long a,b;
      cin >> a >> b;
      
      long long cnt = 0;
      for(long long i = a; i <= b; i++)
	if(isfns(i))
	  cnt++;

      cout << "Case #" << tc << ": ";
      cout << cnt << endl;
    }
  return 0;
}
