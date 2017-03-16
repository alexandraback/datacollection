#include <iostream>
#include <cstdio>
using namespace std; 

int n, s, p; 

int solve ()
{
  scanf ("%d%d%d", &n, &s, &p);
  int res = 0; 
  int i ; 
  for (i = 0; i < n; i ++)
  {
    int temp; 
    scanf ("%d", &temp);
    
    if (temp/3 + ((temp%3) > 0) >= p)
      res ++; 
    else
    {
      int can = 0; 
      
      if (temp % 3 == 0)
      {
	if (temp >= 3 && (temp / 3 + 1) >=p)
	  can = 1;
      }
	else
      if (temp % 3 == 2)
      {
	if (temp >= 2 && (temp / 3 + 2) >= p)
	  can = 1;
      }
      
      if (can && s) s--, res ++;
      
    }
    
  }
  
  return res;
}

int main ()
{
  int t;
  scanf ("%d", &t);
  
  for (int i = 1; i <= t; i++)
    printf ("Case #%d: %d\n",i, solve ());
  
  
  
  return 0;
  
}