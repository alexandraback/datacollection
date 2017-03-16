#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int B;
unsigned long M;

void read()
{
  cin >> B >> M;
}

int R[50][50];

bool correct()
{
  unsigned long A[B];
  A[B-1]=1;
  for(int i=B-2;i>=0;i--)
    {
      A[i]=0;
      for(int j=i+1;j<B;j++)
	A[i]+=A[j]*R[i][j];
    }
  return A[0]==M;
}

bool solve()
{
  unsigned long test = 1L<<(B-2);
  if(test<M)
    return false;
  for(int i=1;i<B;i++)
    {
      for(int j=0;j<=i;j++)
	R[i][j]=0;
      for(int j=i+1;j<B;j++)
	R[i][j]=1;
    }
  for(int i=0;i<B;i++)
    R[0][i]=0;
  unsigned long N=M-1;
  R[0][B-1]=1;
  int indx=B-2;
  while(N!=0)
    {
      R[0][indx--]=N%2;
      N/=2;
    }
  if(!correct())
    cout << "Wrong\n";
  return true;
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
