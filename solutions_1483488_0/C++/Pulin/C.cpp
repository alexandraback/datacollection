 
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  int T;
  cin>>T;
  long long A,B;
  long long count;
  for(int k=0;k<T;k++)
  {
    cin>>A>>B;
    count=0;
    int N=0;
    for(int i=A;i!=0;i/=10)
    {
      N++;
    }
    long long d=pow(10,N-1);
    for(long long i=A;i<=B;i++)
    {
      long long x=i;
      for(int j=1;j<N;j++)
      {
	x=(x%d)*10+x/d;
	if(x==i)
	{
	  break;
	}
	else if(x<i)
	{
	  continue;
	}
	if(x>i && x<=B)
	{
	  count++;
	}
      }      
    }
    cout<<"Case #"<<k+1<<": "<<count<<endl;
  }
  return 0;  
}
