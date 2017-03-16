#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

const int MOD=1000000007;

int n, m, k, ans;
int a[22][22];
bool vi[22][22];
int dir[4][2]={0,1,1,0,0,-1,-1,0};

bool dfs(int x, int y){
  if (a[x][y])
    return 0;
  if (vi[x][y])
    return 0;
  if (x==1 || x==n || y==1 || y==m)
    return 1;
  vi[x][y]=1;
  Rep(l,0,3){
    int x1=x+dir[l][0], y1=y+dir[l][1];
    if (x1<1 || y1<1 || x1>n || y1>m)
      continue;
    if (dfs(x1,y1))
      return 1;
  }
  return 0;
}

bool go_to_border(int x, int y){
  memset(vi,0,sizeof vi);
  if (dfs(x,y))
    return 1;
  return 0;
}

void dfs(int x, int y, int put){
  if (put>ans)
    return;
  if (x==n+1){
    int blocked=put;
    Rep(x,1,n)
      Rep(y,1,m)
      if (!a[x][y] && !go_to_border(x,y))
        blocked++;
    if (blocked>=k)
      ans=min(ans, put);
    return;
  }
  if (y==m+1){
    dfs(x+1,1,put);
    return;
  }
  dfs(x,y+1,put);
  a[x][y]=1;
  dfs(x,y+1,put+1);
  a[x][y]=0;
}

int main(){
  freopen("c.in","r",stdin);
     freopen("b.out","w",stdout);

  int T;
  cin>>T;
  Rep(tt,1,T){
    cout<<"Case #"<<tt<<": ";
    cin>>n>>m>>k;
    ans=1000;
    dfs(1,1,0);
    cout<<ans<<endl;
  }

  return 0;
}
