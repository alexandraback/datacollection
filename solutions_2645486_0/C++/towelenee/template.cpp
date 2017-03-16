#include<cassert>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>

#define eps 1e-12

#define sqr(a) ((a)*(a))
#define mp(a,b) make_pair(a,b) 
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define taskname ""
#ifdef DEBUG
#define deb(x) cerr<<#x<<'='<<x<<endl
#else
#define deb(x) 
#endif
typedef long long ll;

using namespace std;

const int N = (int)1e7 + 100;
ll old[N],nw[N];
int main()         
{
  assert(freopen(taskname"in","r",stdin));
  assert(freopen(taskname"out","w",stdout));
  int test_n;
  scanf("%d",&test_n);
  forn(test_id,test_n)
  {
    printf("Case #%d: ",test_id+1);
    int e,r,n;
    scanf("%d %d %d",&e,&r,&n);
    forn(i,e + 1)
      old[i] = nw[i] = 0;
    forn(i,n){
      ll a;
      scanf("%I64d",&a);
      forn(j,e+1)
        if((old[j] > old[j + 1]) || (j == e)){
          for(int k = 0;k <= j;k++){
            nw[min(j - k + r, e)] = max(nw[min(j - k + r, e)], old[j] + k * a);
          }
        }
      forn(j,e+1){
        old[j] = nw[j];
        nw[j] = 0;
      }
    }
    ll mx = 0;
    forn(j,e + 1)
      mx = max(old[j],mx);
    printf("%I64d\n",mx);
  }
  return 0;
}

