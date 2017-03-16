#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N,J;

void read()
{
  cin >> N >> J;
}

long doIt(long t)
{
  if(t==0)
    return 0;
  return (doIt(t/4)<<4)+(t%4)*5;
}

void solve()
{
  long p = (1L<<(N/2-1));
  for(int n=0;n<J;n++)
    {
      long m = doIt(p+2*n+1);
      while(m!=0)
	{
	  cout << m%2;
	  m/=2;
	}
      for(int b=2;b<=10;b++)
	cout << " " << (1+b*b);
      cout << endl;
    }
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #"<<t<<":\n";
      solve();
    }
  return 0;
}
