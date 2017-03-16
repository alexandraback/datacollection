#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define ll  long long 
void work();
int main()
{
  int T;
  scanf("%d", &T);
  for(int i = 1; i <=T; i++){
    printf("Case #%d: ",i);
    work();
  }
}

int logtwo(ll x){
  int ans = 0;
  while(x%2==0){
    x/=2;
    ans++;
  }
  if(x==1)
    return ans;
  return -1;
}
void work()
{
  ll P, Q;
  scanf("%lld/%lld", &P, &Q);
  ll x = __gcd(P,Q);
  P/=x;
  Q/=x;
  int t = logtwo(Q);
  if(t<0){
    printf("impossible\n");
    return;
  }
  for(int i = 1; i <=t;i++){
    if(P >=Q/2){
      printf("%d\n",i);
      return;
    }
    Q/=2;
  }
}
