#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int B,M;

void read()
{
  cin >> B >> M;
}

int R[6][6];

bool solved()
{
  int S[B];
  S[B-1]=1;
  for(int i=B-2;i>=0;i--)
    {
      S[i]=0;
      for(int j=i+1;j<B;j++)
	S[i]+=S[j]*R[i][j];
    }
  return S[0]==M;
}

bool solve(int n,int m)
{
  if(n==B-1)
    return solved();
  if(m==B)
    return solve(n+1,n+2);
  R[n][m]=0;
  if(solve(n,m+1))
    return true;
  R[n][m]=1;
  if(solve(n,m+1))
    return true;
  return false;
}

bool solve()
{
  for(int i=0;i<B;i++)
    for(int j=0;j<B;j++)
      R[i][j]=0;
  return solve(0,1);
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #" << t << ": ";
      if(solve())
	{
	  cout << "POSSIBLE" << endl;
	  for(int i=0;i<B;i++)
	    {
	      for(int j=0;j<B;j++)
		cout << R[i][j];
	      cout << endl;
	    }
	}
      else
	cout <<"IMPOSSIBLE"<< endl;
    }
  return 0;
}
