#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
 int N, i, j, d, p, m, S, max, tmp;

 cin >> m;
 for(i=0;i<m;i++)
 {
  cin >> N;
  cin >> S;
  cin >> p;

  max = 0;
  for(j=0;j<N;j++)
  {
   cin >> d;
   if((d%3==0 && d/3 >= p) || (d>0 && d%3!=0 && d/3+1 >= p))
   {
    max++;
   }
   else if(d>=2 && d <= 28 && (d-2)/3+2 >= p && S > 0)
   {
    //cout << "x" << d << " ";
    max++;
    S--;
   }
  }

  cout << "Case #" << i+1 << ": " << max << endl;
 }
}
