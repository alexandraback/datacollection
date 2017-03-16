#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
int main()
{
  int i,j,k;
  int T;
  double r,t;
  double p;
  int value;
 
  ifstream fp1 ("data.in");
  ofstream fp2;
  fp2.open("data.out");
  fp1 >> T;
  for(k=1;k<=T;k++)
  {
    fp1 >> r;
    fp1 >> t;
    p=(-(2*r-1)+sqrt((2*r-1)*(2*r-1)+8*t))/4;
    value=p;
    value=value+10000;
    while(2*value*value+value*(2*r-1)>t)
    {
      value=value-1;
    }
    fp2 << "Case #" << k<<": "<< value	<<endl ;
  }
  fp1.close();
  fp2.close();
  return 0;
}