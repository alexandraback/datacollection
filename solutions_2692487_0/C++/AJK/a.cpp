#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
  long i,j,k;
  long T;
  long A,N,As,y;
  long AA[1000];
  long yy[1000];
    
  ifstream fp1 ("data.in");
  ofstream fp2;
  fp2.open("data.out");
  fp1 >> T;
  for(k=1;k<=T;k++)
  {
    fp1 >> A;
    fp1 >> N;
    for(i=0;i<N;i++)
    {
      fp1 >> AA[i];
    }
    std::sort(AA,AA+N);
    cout << AA[0] <<"   ";
    for(i=0;i<=N;i++)
    {
      As=A;
      yy[i]=N-i;
      if (As==1)
      {
	yy[i]=N;
      }
      else
      {
	for(j=0;j<i;j++)
	{
	  while(As<=AA[j])
	  {
	    cout << "k="<< k << " i="<<i << " As=" << As << " "  ;
	    As=2*As-1;
	    yy[i]=yy[i]+1;
	  }
	  As=As+AA[j];
	  cout << endl;
	}
      }
    }
    y=10000;
    for(i=0;i<=N;i++)
    {
      if(yy[i]<y)
      {
	y=yy[i];
      }
    }
    fp2 << "Case #" << k<<": "<< y <<endl;
  }
  fp1.close();
  fp2.close();
  return 0;
}