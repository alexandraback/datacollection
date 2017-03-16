#include <iostream>
#include <stack>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

#define A first
#define B second
#define MP make_pair

int main()
{
  int i, T, X, Y;
  cin >> T;
  
  for (int t=1; t<=T; ++t)
  {
    cin >> X >> Y;
    printf("Case #%d: ", t);
    if (X < 0)
    {
      for (i=X; i<0; ++i)
      {
        printf("EW");
      }
    }
    else if (X > 0)
    {
      for (i=0; i<X; ++i)
      {
        printf("WE");
      }
    }
    
    if (Y < 0)
    {
      for (i=Y; i<0; ++i)
      {
        printf("NS");
      }
    }
    else if (Y > 0)
    {
      for (i=0; i<Y; ++i)
        printf("SN");
    }
    printf("\n");
  }
	return 0;
}
