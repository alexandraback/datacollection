#include <bits/stdc++.h>

#define F first
#define S second
#define llong long long
#define ullong unsigned long long
#define pb push_back
#define mp make_pair
#define y1 asdasd

using namespace std;

const int MXN = (int)2e6 + 10;
const int INF = (int)1e9 + 7;
const double EPS = (double)1e-9;

int T;
llong n;
map <llong, int> d;
queue <llong> q;

inline int get(llong x){
  return d.count(x) ? d[x] : INF;
}

inline llong rev(llong x){
  llong res = 0LL;
  while(x){
    res = res * 10LL + (x % 10LL);
    x /= 10LL;
  }
  return res;
}

inline void bfs(){
  llong v, tmp;
  while(!q.empty()){
    v = q.front();
    q.pop();
    tmp = rev(v);
    if(v + 1LL <= n && get(v) + 1 < get(v + 1)){
      d[v + 1LL] = get(v) + 1;
      q.push(v + 1LL);
    }
    if(tmp <= n && get(v) + 1 < get(tmp)){
      d[tmp] = get(v) + 1;
      q.push(tmp);
    }
  }
}

int main(){
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &T);
  for(int test = 1; test <= T; ++test){
    scanf("%lld", &n);
    q.push(1LL);
    d[1LL] = 1LL;
    bfs();
    printf("Case #%d: %d\n", test, d[n]);
    d.clear();
  }
  return 0;
}
