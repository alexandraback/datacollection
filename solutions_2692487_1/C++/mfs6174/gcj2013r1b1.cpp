/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: ti
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
ifstream inf("ti.in.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;

int i,j,k,t,n,m,zz,zu,mm,d;
int shu[300];

int main()
{
  freopen("ti.out","w",stdout);
  inf>>zu;
  for (zz=1;zz<=zu;zz++)
  {
    inf>>m>>n;
    for (i=1;i<=n;i++)
      inf>>shu[i];
    sort(&shu[1],&shu[n+1]);
    mm=maxlongint;
    k=m;
    d=0;
    for (i=1;i<=n;i++)
    {
      if (k>shu[i])
      {
        k+=shu[i];
      }
      else
      {
        mm=min(mm,d+n-i+1);
        if (k==1)
          break;
        while (k<=shu[i])
        {
          d++;
          k+=k-1;
        }
        k+=shu[i];
      }
    }
    if (i>n)
      mm=min(mm,d);
    pf("Case #%d: %d\n",zz,mm);
  }
  return 0;
}
      
