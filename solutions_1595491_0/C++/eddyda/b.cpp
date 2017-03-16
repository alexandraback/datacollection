#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;

int main()
{
  freopen("B-small-attempt0.in", "rt", stdin);
  freopen("B-small-attempt0.out", "wt", stdout);

  int T;
  int S;
  int p;
  int ti;
  int N;
  cin>>T;
  for (int t=1; t<=T; t++)
  {
    int result = 0;
    cin>>N;
    cin>>S;
    cin>>p;
    for (int i=0; i<N; i++)
    {
      cin>>ti;
      if (p>=2)
      {
        if (ti >= 3*p-2)
          result++;
        else if (ti == 3*p-3 || ti == 3*p-4)
        {
          if (S>0)
          {
            S--;
            result++;
          } 
        }
      }
      else if (p==1)
      {
        if (ti>=1)
          result++;
      }
      else if (p==0)
        result++;
    }
    printf("Case #%d: %d\n", t, result);
  }
}
