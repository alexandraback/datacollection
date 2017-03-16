#include<stdio.h>
#include<iostream>
#include<list>
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

bool findinList(list<int> &data, int x)
{
 list<int>::iterator it;

 for(it=data.begin();it!=data.end();it++)
  if(*it == x)
   return true;

 return false;
}

void op()
{
 int A, B, n;
 int d, i, j, x, y, p, q, count;
 list <int> selected;

 cin >> A >> B;
 count = 0;

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
    if(findinList(selected, x))
    {
//     printf("sth wrong at (%d, %d)\n", x, n);
//     return(0);
    }
    else
    {
     selected.push_back(x);
     count++;
    }
  }

  selected.clear();
 }

 if(count%2)
  printf("sth wrong.");

 printf("%d\n", count/2);
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
