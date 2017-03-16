#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;
double num[2][1010];
int n;
int march(double a[], double b[])
{
  int now=n;
  int ans=0;
  for(int i=n;i>=1;i--)
  {
    while(a[i]<b[now] && now>0)
      now--;
    if (now>0 && a[i]>b[now])
    {
      ans++;
      now--;
    }
  }
  return ans;
}
int main()
{
  freopen("D-large.in","r",stdin);
  freopen("D-out","w",stdout);
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%lf", num[0]+i);
    for(int i=1;i<=n;i++)
      scanf("%lf", num[1]+i);
    sort(num[0]+1,num[0]+n+1);
    sort(num[1]+1,num[1]+n+1);
    printf("Case #%d: %d %d\n", i,
        march(num[0], num[1]),
        n-march(num[1], num[0]));
  }
  return 0;
}
