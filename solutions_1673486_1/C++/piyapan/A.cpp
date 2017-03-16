#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
 double *p, *product, minE, e;
 int A, B, T, j, i;

 cin >> T;
 for(i=0;i<T;i++)
 {
  cin >> A >> B;

  p = new double[A+1];
  product = new double[A+1];
  product[0] = 1;

  for(j=1;j<=A;j++)
  {
   cin >> p[j];
   product[j] = p[j]*product[j-1];
  }

  //keep typing
  minE = product[A]*(B-A+1)+(1-product[A])*(2*B-A+2);
//  cout << minE << endl;

  //press backspace
  for(j=1;j<=A;j++)
  {
   e = product[A-j]*(B-A+2*j+1)+(1-product[A-j])*(2*B-A+2*j+2);
//   cout << e << endl;

   if(e < minE)
    minE = e;
  }

  //press enter
  if(B+2 < minE)
   minE = B+2;

  printf("Case #%d: %lf\n", i+1, minE);

  delete[] p;
  delete[] product;
 }
}
