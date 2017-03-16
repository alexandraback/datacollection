#include <functional>/*{{{*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;typedef long long ll;typedef long double real;void run();int main(){
#ifndef snarl
freopen("_.in","r",stdin); freopen("_.out","w",stdout);
#endif
ios::sync_with_stdio(0);run();}/*}}}*/

bool pal(ll n){
  static int dig[15];
  int digs=0;
  do{
    dig[digs++]=n%10;
    n/=10;
  } while (n);
  for (int i=0; i<digs-1-i; i++){
    if (dig[i]!=dig[digs-1-i]) return false;
  }
  return true;
}

vector<ll> all;

void run(){
  int tsts; cin>>tsts;

  all.push_back(-2);
  for (ll i=1; i<=10000000ll; i++)
    if (pal(i) and pal(i*i))
      all.push_back(i*i);
//      cout<<i<<"\t\t"<<i*i<<endl;
  all.push_back(1ll<<62ll);

  for (int tst=1; tst<=tsts; ++tst){
    ll x,y; cin>>x>>y;
    int u=lower_bound(all.begin(),all.end(),y)-all.begin(); while (all[u  ]<=y) ++u;
    int v=lower_bound(all.begin(),all.end(),x)-all.begin(); while (all[v-1]>=x) --v;

    cout<<"Case #"<<tst<<": "<<u-v<<endl;
  }
}

