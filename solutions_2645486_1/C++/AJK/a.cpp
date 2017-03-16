#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
int main()
{
  int i,j,k;
  int T,E,R,N;
  int v[100000];
  int Energy;
  int minenergy;
  int Gain;

  ifstream fp1 ("data.in");
  ofstream fp2;
  fp2.open("data.out");
  fp1 >> T;
  for(k=1;k<=T;k++)
  {
    fp1 >> E;
    fp1 >> R;
    fp1 >> N;
    Energy=E;
    Gain=0;
    for (i=0;i<N;i++)
    {
      fp1 >> v[i];
    }
    for(i=0;i<N;i++)
    {
      minenergy=0;
      for(j=i+1;j<N;j++)
      {
	if (v[j]>v[i])
	{
	  minenergy=max(minenergy,E-R*(j-i));
	}
      }
      if (Energy>minenergy)
      {
	Gain=Gain+v[i]*(Energy-minenergy);
	Energy=minenergy+R;
      }
      else
      {
	Energy=Energy+R;
      }
      Energy=min(Energy,E);
    }
    
    fp2 << "Case #" << k<<": "<< Gain <<endl;
  }
  fp1.close();
  fp2.close();
  return 0;
}