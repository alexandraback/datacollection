#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
bool v[10];

bool sat(ll x) {
  ll j = x;
  while( j> 0) {
    v[j % 10] = true;
    j /= 10;
  }
  for(int i=0; i<10; i++) 
    if(!v[i]) return false;
  return true ;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    ll n;
    cin >> n;
    for(int i=0; i<10; i++) 
      v[i] = false;

    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", tc);
      continue;
    }

    ll ret = n;
    while(!sat(ret)) {
      ret += n;
    }
    printf("Case #%d: %Ld\n",tc,ret);


  }

  return 0;
}