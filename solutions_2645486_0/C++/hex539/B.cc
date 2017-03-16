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
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;typedef long long ll;typedef long double real;void run();int main(){ios::sync_with_stdio(0);run();}/*}}}*/

pair<ll,ll> evt[20000];
ll spend[20000];

void run(){
  int tsts; cin>>tsts; for (int tst=1; tst<=tsts; ++tst){
    ll bound,regain,n; cin>>bound>>regain>>n;
    for (int i=0; i<n; i++) cin>>evt[i].first, evt[i].second=i;
    sort(evt,evt+n);
    ll res=0;

    map<ll,ll> enact,require;
    enact[0]=bound;
    enact[n]=0;

    require[n]=0;

    for (int i=n; i--;){
      ll pos=evt[i].second;
      ll ang=evt[i].first;

      auto it=enact.lower_bound(pos); --it;
      auto jt=require.upper_bound(pos);
      ll need=jt->second;

      ll maft=max(0ll,jt->second-(jt->first-pos)*regain);
      ll dx=pos-it->first;

      ll current=min(bound, it->second+dx*regain);
      ll delta=(current-maft);
      if (delta>=0){
        res+=delta*evt[i].first;

        require[pos]=current;
        enact[pos]=current-delta;
      }
    }

    cout<<"Case #"<<tst<<": "<<res<<endl;
  }
}

