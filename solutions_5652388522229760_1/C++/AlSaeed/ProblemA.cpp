#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

unsigned long N;

void read()
{
  cin >> N;
}

bool d[10];

bool done()
{
  for(int i=0;i<10;i++)
    if(!d[i])
      return false;
  return true;
}

unsigned long solve()
{
  if(N==0)
    return -1;
  unsigned long rst = 0;
  for(int i=0;i<10;i++)
    d[i]=0;
  while(!done())
    {
      rst+=N;
      unsigned long m = rst;
      while(m!=0)
	{
	  d[m%10]=true;
	  m/=10;
	}
    }
  return rst;
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #"<<t<<": ";
      unsigned long s = solve();
      if(s==-1)
	cout << "INSOMNIA";
      else
	cout << s;
      cout << endl;
    }
  return 0;
}
