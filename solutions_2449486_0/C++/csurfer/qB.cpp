#include<vector>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>

using namespace std;

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define INF (int)1e9
#define LINF (long long)1e18
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?(-(x)):(x))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define foreach(v,c) for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)

int main()
{
  int tc;s(tc);
  int tco = tc;
  while(tc--)
  {
    int n,m;s(n);s(m);
    int arr[n][m];
    REP(i,n)REP(j,m)cin>>arr[i][j];
    
    bool flag = true;
    REP(i,n)
    REP(j,m)
    {
      bool rowWise, colWise;
      rowWise = colWise = true;
      //RowWise
      for(int k=0;k<m;k++)
      {
        if(k!=j && arr[i][k]>arr[i][j])
        {
          rowWise = false;
          break;
        }
      }

      //ColumnWise
      for(int k=0;k<n;k++)
      {
        if(k!=i && arr[k][j]>arr[i][j])
        {
          colWise = false;
          break;
        }
      }

      if(rowWise==false && colWise==false)
      {
        flag = false;
        break;
      }
    }

    if(flag)
      cout<<"Case #"<<tco-tc<<": YES"<<endl;
    else
      cout<<"Case #"<<tco-tc<<": NO"<<endl;
  }
  return 0;
}

