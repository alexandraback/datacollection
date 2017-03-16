#include <iostream>
#include <cmath>
using namespace std;
#define DMax 1000

int P[DMax];
int D;
int PMax;

void read()
{
  cin >> D;
  PMax=-1;
  for(int i=0;i<D;i++)
    {
      cin >> P[i];
      if(P[i]>PMax)
	PMax=P[i];
    }
}

int minutes(int mins)
{
  int sum=mins;
  for(int i=0;i<D;i++)
      sum+= (int)ceil(1.0*P[i]/mins) -1;
  return sum;
}

int main()
{
  int n;
  cin >> n;
  for(int t=1;t<=n;t++)
    {
      int min = 2000000000;
      read();
      for(int p=1;p<=PMax;p++)
	{
	  int mins = minutes(p);
	  if(mins<min)
	    min=mins;
	}
      cout << "Case #" << t <<": " << min << endl;
    }
  return 0;
}
