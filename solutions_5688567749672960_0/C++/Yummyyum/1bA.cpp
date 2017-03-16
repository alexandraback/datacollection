#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int T;
ll N, vis[MAXN], dist[MAXN];

ll flip(ll x){
  ll res = 0;
  for( ; x > 0; x /= 10){
    res = 10 * res + x % 10;
  }
  return res;
}

void bfs(){
  vis[1] = 1;
  dist[1] = 1;
  queue<ll> Q;
  Q.push(1);
  while(Q.size()){
    ll v = Q.front(), n;
    Q.pop();
    n = flip(v);
    if(n < MAXN && !vis[n]){
      vis[n] = 1;
      dist[n] = dist[v] + 1;
      Q.push(n);
    }
    n = v + 1;
    if(n < MAXN && !vis[n]){
      vis[n] = 1;
      dist[n] = dist[v] + 1;
      Q.push(n);
    }
  }
}

int main(){
  bfs();
  cin >> T;
  for(int _t = 1; _t <= T; _t++){
    printf("Case #%d: ", _t);
    cin >> N;
    cout << dist[N] << '\n';
  }
}
