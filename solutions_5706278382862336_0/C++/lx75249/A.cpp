#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <new>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;
long long gcd(long long a, long long b)
{
  return b==0?a:gcd(b,a%b);
}
void reduce(long long&a, long long&b)
{
  long long d=gcd(a,b);
  a/=d; b/=d;
}
vector<int> bin;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("A-small-attempt0.in","r",stdin);
  freopen("A-small-attempt0.out","w",stdout);
#endif
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    bin.clear();
    long long P,Q;
    scanf("%lld/%lld", &P, &Q);
    reduce(P,Q);
    while(P!=0 && bin.size()<40)
    {
      P<<=1;
      if(P>=Q)
      {
        bin.push_back(1);
        P -= Q;
      }
      else bin.push_back(0);
      reduce(P, Q);
    }
    printf("Case #%d: ", t);
    if (P!=0)
      printf("impossible\n");
    else
    {
      int ans=0;
      while(bin[ans] == 0)
        ans++;
      printf("%d\n", ans+1);
    }
  }
  return 0;
}
