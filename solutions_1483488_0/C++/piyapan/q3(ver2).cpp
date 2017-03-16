#include<stdio.h>
#include<iostream>
using namespace std;

int countdigit(int n, int &p)
{
 int i;

 i=0;
 p = 1;
 while(n)
 {
  p*=10;
  n/=10;
  i++;
 }

 return i;
}

void op()
{
 int A, B, n;
 int d, i, j, x, y, p, q, count;
 bool **ans;

 cin >> A >> B;
 count = 0;

 ans = new bool* [B-A+1];
 for(i=0;i<B-A+1;i++)
 {
  ans[i] = new bool[B-A+1];
  for(j=0;j<B-A+1;j++)
   ans[i][j] = false;
 }

 for(n=A;n<=B;n++)
 {
  d = countdigit(n, p);
  p/=10;
  q = n;

  y=10;
  for(i=1;i<d;i++, p/=10, y*=10, q/=10)
  {
   x = n/y+(n%y)*p;
//   printf("%d q%%10=%d\n", x, q%10);
   if(x != n && q%10 != 0 && x <= B && x >= A)
    if(ans[x-A][n-A])
    {
//     printf("sth wrong at (%d, %d)\n", x, n);
//     return(0);
    }
    else
    {
     ans[x-A][n-A] = 1;
     count++;
    }
  }
 }

 if(count%2)
  printf("sth wrong.");

 printf("%d\n", count/2);

 for(i=0;i<B-A+1;i++)
  delete[] ans[i];
 delete[] ans;
}

int main()
{
 int N, i;

 cin >> N;
 for(i=0;i<N;i++)
 {
  cout << "Case #" << i+1 << ": ";
  op();
 }
}
