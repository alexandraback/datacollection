#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int op(int caseNum)
{
 double D, *t, *d, tn, a, f;
 int nA, N, i;

 cin >> D >> N >> nA;
 t = new double [N];
 d = new double [N];
 for(i=0;i<N;i++)
  cin >> t[i] >> d[i];

 tn = t[N-1];
 if(d[i] != D && N == 2)
 {
  double v = (d[1]-d[0])/(t[1]-t[0]);
  tn = (D-d[0])/v;
 }

 printf("Case #%d:\n", caseNum);
 for(i=0;i<nA;i++)
 {
  cin >> a;

  f = sqrt(2*D/a);
  if(f < tn)
   printf("%.7lf\n", tn);
  else
   printf("%.7lf\n", f);
 }
}

int main()
{
 int i, N;

 cin >> N;
 for(i=0;i<N;i++)
  op(i+1);
}
