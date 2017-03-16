#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int digits(int a)
{
  int ret = 0; 
  while ( a )
    ret ++, a/=10;
  
  return ret;
}


int solve()
{
  int a, b; 
  
  scanf ("%d%d", &a, &b);
  
    int res = 0; 
    int i, j;
    for (i = max(a, 10); i<=b; i++)
    {
      int k = digits (a);
      int other = i;
      int tens = 1; 
      for (j = 0; j < k - 1; j ++)
	tens *= 10; 
      
      set <int> opa;
      
      for (j = 0; j < k - 1; j ++)
      {
	int o = other % 10; 
	other = o * tens + other / 10;
	
	if (o != 0 && other > i && other >= a && other <= b)
	{
	  if(opa.find (other) == opa.end())
	  {
	    res ++;
	    opa.insert (other);
	  }
	} 
      }
      
    }
    
    return res; 
  
}
int main ()
{
  
  int t; 
  scanf ("%d", &t);
  
  int i; 
  for (i=1; i <=t; i ++)
    printf ("Case #%d: %d\n", i, solve ());
  
}