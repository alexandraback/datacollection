#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#define LL long long
#define vi vector<int>
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()
#define it iterator
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define REPX(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DEP(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define REX(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end();i++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define st string
#define ffo find_first_of
#define su substr
#define vs vector<st>
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define li list<int>
#define em empty
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define qi queue<int>
#define MAX 10000010
using namespace std;
int v[MAX]; qi q;
LL rev(LL i)
{
  LL v=0;
  while(i)
  {
    v=v*10+(i%10);
    i/=10;
  }
  return v;
}
inline int valid(int i)
{
  return i && i<MAX;
}
void bfs()
{
  v[1]=1;
  q.push(1);
  while(!q.empty())
  {
    int i=q.front();
    q.pop();
    if(valid(i+1) && !v[i+1]) { v[i+1]=v[i]+1; q.push(i+1); }
    int j=rev(i);
    if(valid(j) && !v[j]) { v[j]=v[i]+1; q.push(j); }
  }
}
LL func(LL n)
{
  if(n<MAX) return v[n];
  LL m=rev(n);
  if(m<n) return 1+func(m);
  return 1+func(n-1);
}
int main()
{
  bfs();
  int tc; scanf("%d\n",&tc);
  REP(t,0,tc)
  {
    LL n; scanf("%lld",&n);
    printf("Case #%d: ",t+1);
    if(n>=MAX) printf("%lld\n",func(n));
    else printf("%d\n",v[n]);
  }
  return 0;
}

