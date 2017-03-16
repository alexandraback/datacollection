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
#define ulli unsigned long long int

int s[100] = {0};

int main()
{
  freopen("A-large.in", "rt", stdin);
  freopen("A-large.out", "wt", stdout);

  int T;
  ulli r;
  ulli t;
  cin>>T;
  for (int c=1; c<=T; c++)
  {
    printf("Case #%d:", c);
    cin>>r>>t;
    bool done = false;
    ulli k = 1;
    ulli upper = 0;
    ulli lower = 1;
    ulli tk = 0;
    //binary search, double go up
    // t(k) = 2*k^2 + (2r - 1)*k
    while (true)
    {
      //cout<<k<<endl;
      tk = 2 * k * k + (2 * r - 1) * k;
      if (tk < t) k *= 2;
      else if (tk == t)
      {
        done = true;
        break;
      }
      else break; 
    }

    if (done)
    {
      printf(" %llu\n", k);
      continue;
    }

    upper = k;
    lower = k/2;
    
    ulli mid = 0;
    while(lower + 1 < upper)
    {
      //cout<<lower<<" "<<upper<<endl;
      mid = lower + (upper - lower)/2;
      tk = 2 * mid * mid + (2 * r - 1) * mid;
      if (tk < t) lower = mid;
      else if (tk == t)
      {
        done = true;
        break;
      }
      else upper = mid;
    }
 
    if (done)
    {
      printf(" %llu\n", mid);
      continue;
    }

    printf(" %llu\n", lower);
  }
}
