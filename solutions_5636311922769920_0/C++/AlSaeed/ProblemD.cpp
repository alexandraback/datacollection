#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int K,C,S;

void read()
{
  cin >> K >> C >> S;
}

void solve(vector<unsigned long>& rst)
{
  int limit = K/C +(K%C!=0);
  if(S<limit)
    return;
  int k=0;
  for(int i=0;i<limit;i++)
    {
      unsigned long e = 0;
      for(int j=0;j<C && k<K;j++)
	{
	  e*=K;
	  e+=k;
	  k++;
	}
      rst.push_back(e+1);
    }
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #"<<t<<":";
      vector<unsigned long> rst;
      solve(rst);
      if(rst.size()==0)
	cout << " IMPOSSIBLE";
      else for(int i=0;i<rst.size();i++)
	cout << " " << rst[i];
      cout << endl;
    }
  return 0;
}
