#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <assert.h>     /* assert */
#include <limits>
#include <set>
#include <map>

using namespace std;

typedef unsigned long UL;

bool is_pow_2( UL x)
{
  return !(x == 0) && !(x & (x - 1));
}

long gcd ( UL a, UL b )
{
  UL c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

UL get_len( UL x)
{
  UL t = 0;
  while (x >>= 1) 
    ++t;
 return t; 
}

void proc_case()
{
  UL a, b, c;
  
  scanf("%lu/%lu\n", &a, &b);
  
  c = gcd(a,b);
  a /= c;
  b /= c;
  
  UL p = pow( 2, 40);
 
   
  if (( ! is_pow_2(b) ) || ( a > b) )
  {
    cout << "impossible" << endl;
    return;
  }
  
  
  UL f = p / b;
  UL af = a*f;
  
  UL len = 40 - get_len(af);
  
  //cout << a << " " << b << " " << p << " " << len << endl;
  
  cout << len << endl;
  
}


int main()
{
  int t;
  scanf("%d\n", &t);
  for (int i=0; i < t; i++)
  {
    cout << "Case #" << i+1 << ": " ;
    proc_case();
  }
}