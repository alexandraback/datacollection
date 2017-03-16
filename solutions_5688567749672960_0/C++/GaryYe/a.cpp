#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;
const int MAX_N = 1e6;
int T;
ll N;
ll dist[MAX_N + 1];

ll reverse(ll x){
  ll r = 0;
  while(x > 0){
    r = (r * 10) + (x % 10);
    x /= 10;
  }
  return r;
}

queue<ll> q;
void check(ll x, ll d){
  if(x > MAX_N)
    return;
  if(dist[x] == -1){
    dist[x] = d + 1;
    q.push(x);
  }
}

int main(){
  for(int i = 0; i <= MAX_N; i++)
    dist[i] = -1; 
  dist[0] = 0;
  q.push(0);
  while(!q.empty()){
    ll t = q.front(); q.pop();
    ll r = reverse(t);
    check(r, dist[t]);
    check(t + 1, dist[t]);
  }
  scanf("%d", &T);
  for(int cn = 1; cn <= T; cn++){
    scanf("%lld", &N);
    printf("Case #%d: %lld\n", cn, dist[N]);
  }
  return 0;
}
