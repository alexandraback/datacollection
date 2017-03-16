#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(ll (i)=(n);(i)<ll(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;
/*
  1=1, i=2, j=3, k=4
*/

int qmul(int x, int y){
  static const int table[4][4] = {
    {1, 2, 3, 4},
    {2,-1, 4,-3},
    {3,-4,-1, 2},
    {4, 3,-2,-1}
  };
  if(!(abs(x) <= 4 && abs(y) <= 4 && x*y)) {
    cerr<<"Error: "<<x<<" "<<y<<endl;
  }
  return ((x*y < 0)?-1:1) * table[abs(x)-1][abs(y)-1];
}


int qpow(ll a, ll n) {
  ll t = a;
  ll ret = 1;
  for(ll i=0;(1LL<<i) <= n;++i) {
    if(n & (1LL << i)) {
      ret = qmul(ret, t);
    }
    t = qmul(t, t);
  }
  assert(abs(ret) <= 4 && ret);
  return ret;
}


int main(){
  cin >> T;
  reps(times, 1, T+1) {
    vector<int> vec;
    string str;
    ll l, x;
    cin >> l >> x;
    cin>>str;
    assert((int)sz(str)==l);

    int mul=1;
    rep(i,sz(str)){
      int q = (str[i]-'i')+2;
      vec.PB(q);
      mul = qmul(mul, q);
    }

    if(qpow(mul, x) != -1) {
      printf("Case #%lld: NO\n", times);
      continue;
    }

    ll left=x*l, right=0;;
    ll t = 1;
    rep(i, l * min(10LL, x)){
      t = qmul(t, vec[i%l]);
      if (t == 2) { // 2 means 'i'
        left = i;
        break;
      }
    }

    t = 1;
    rep(i, l * min(10LL, x)){
      int idx = l-1-(i%l);
      t = qmul(vec[idx], t);
      if (t == 4) { // 4 means 'k'
        right = l*x-1-i;
        break;
      }
    }
    printf("Case #%lld: %s\n", times, (left < right)?"YES":"NO");
  }

}
