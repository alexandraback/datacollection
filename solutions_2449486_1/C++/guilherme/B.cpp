#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<functional>
#include<sstream>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define allv(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).rend()
#define _foreach(it,b,e) for(__typeof__(b); it!=(e);++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3fll;//dois L's
const double eps = 1e-9;
const int maxn = 1234;

int n,m;
int tab[maxn][maxn];
int row[maxn];
int col[maxn];
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      scanf("%d %d",&n,&m);
      for(int i=0;i<maxn;i++)
	row[i]=col[i]=-99999;
      for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
	  scanf(" %d",&tab[i][j]);
	  row[i]=max(row[i],tab[i][j]);
	  col[j]=max(col[j],tab[i][j]);
	}
      bool ok = true;
      for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
	  if(tab[i][j]<row[i] && tab[i][j]<col[j])ok=false;
	}
      printf("Case #%d: %s\n",pp,ok?"YES":"NO");
    }
  return 0;
}
