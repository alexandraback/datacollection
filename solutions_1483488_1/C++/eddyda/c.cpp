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

int mut(int n, int d, int left)
{
  int base = (int)pow(10.0, d);
  int prefix = n/base;
  int suffix = n%base;
  int m = prefix + suffix * (int)pow(10.0, left);
  return m;
}

int main()
{
  freopen("C-large.in", "rt", stdin);
  freopen("C-large.out", "wt", stdout);

  int T;
  int A;
  int B;
  int D;
  int m;
  cin>>T;
  for (int t=1; t<=T; t++)
  {
    int result = 0;
    cin>>A;
    cin>>B;
    D = (int)log10(B) + 1;
    for (int n=A; n<B; n++)
    {
      set<int> appear;
      for (int d=1; d<D; d++)
      {
        m = mut(n, d, D-d);
        if (m>n && m>A && m<=B && appear.find(m)==appear.end())
        {
          appear.insert(m);
          result++;
          //printf("result: %d, n: %d, m: %d\n", result, n, m);
        }
      }
    }
    printf("Case #%d: %d\n", t, result);
  }
}
