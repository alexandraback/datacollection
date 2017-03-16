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
#define MAX 15
using namespace std;
int val(int c,int w)
{
  if(w==1) return c;
  int v=0,l=w-1+(c%w);
  REP(i,1,c+1) v+=(i%w==0);
  return v+val(l,w-1);
}
int main()
{
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
   printf("Case #%d: ",t+1);
   int r,c,w;
   scanf("%d %d %d",&r,&c,&w);
   printf("%d\n",r*val(c,w));
  }
 return 0;
}
