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
const int maxn = 12345;
huge ret;
huge e,r, val[maxn];
int n;
huge best(int a, int b, huge st, huge ed){//start, must end
  assert(a<b+2);
  if(a>b) return 0;
  if(a==b) {
    huge fica = max(0ll,ed);
    assert(fica<=st);
    //   printf("st%lld ed%lld %lld %d\n",st,ed,fica, a);
    return (st-fica)*val[a];
  }
  huge pos = a;
  for(int i=a;i<=b;i++){
    if(val[i]>val[pos])pos=i;
  }
  huge chego = min(e,(pos-a)*r + st);
  huge fica = max(0ll, ed - (b-pos)*r); 
  huge tem = max(0ll,chego-fica);

  //  printf("a%d b%d st%lld ed%lld g%lld %lld %lld \n",a,b,st,ed,tem*val[pos],chego, fica);
  return best(a,pos-1,st, max(0ll,chego-r)) + tem*val[pos] + best(pos+1,b,min(e,fica+r),ed);
 }
/*huge mel[1000][1000];
huge solve(int a, huge b){
  if(a==n)return 0;
  if(mel[a][b]==-1){
    huge ret = 0;
    for(int i=0;i<=b;i++){
      ret = max(ret, val[a]*i + solve(a+1,min(b-i+r,e)));
      
    }
    mel[a][b]=ret;
  }
  return mel[a][b];
  }*/
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      //   memset(mel,-1,sizeof(mel));
      ret = 0;
      scanf("%lld %lld %d",&e,&r,&n);
      for(int i=0;i<n;i++)
	scanf(" %lld",&val[i]);
      huge ret = best(0,n-1,e,0);
      //  huge ret2 = solve(0,e);
      // assert(ret==ret2);
      printf("Case #%d: %lld\n",pp,ret);
      //        printf("Case #%d: %lld\n",pp,solve(0,e));

    }
  return 0;
}
