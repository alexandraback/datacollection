#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll brute(ll v[], ll n, ll E, ll now, ll R){
  ll i, j, k, res = 0, tmp;
  now = min(E, now+R);

  if(n==0) return res;
  rep(i,now+1){
    tmp = brute(v+1, n-1, E, now-i, R);
    tmp += v[0] * i;
    res = max(res, tmp);
  }

  return res;
}

int main(){
  ll i,j,k,l,m,E,R,N,res;
  ll v[11000];
  ll mn[11000], mx[11000], t, cor;
  
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
//    fprintf(stderr, "progress %d\n", size);
    printf("Case #%d: ", ++count);

    scanf("%lld%lld%lld",&E,&R,&N);
    rep(i,N) scanf("%lld",v+i);

//    cor = brute(v,N,E,E,R);

    res = 0;
    if(R >= E){
      rep(i,N) res += E * v[i];
    } else {
      rep(i,N+1) mn[i] = 0, mx[i] = E;

      for(;;){
        k = 0;
        rep(i, N) if(v[k] < v[i]) k = i;
        if(v[k] == 0) break;

        res += (mx[k] - mn[k]) * v[k];
        v[k] = 0;

        t = mn[k];
        REP(i,k+1,N){
          t += R;
          mx[i] = min(mx[i], t);
        }

        t = mx[k];
        for(i=k-1;i>=0;i--){
          t -= R;
          mn[i] = max(mn[i], t);
        }
      }
      
    }

    printf("%lld\n",res,cor);
  }

  return 0;
}
