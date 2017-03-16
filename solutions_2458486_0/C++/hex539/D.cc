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
using namespace std;typedef unsigned long long ll;typedef long double real;void run();int main(){
ios::sync_with_stdio(0);run();}/*}}}*/

ll fact[30]={1};
ll plan[1<<20];
int have[1<<20][20];
vector<int> box[300];
int lock[300];

void run(){
  for (int i=1; i<=20; i++) fact[i]=fact[i-1]*i;

  int tsts; cin>>tsts; for (int tst=1; tst<=tsts; ++tst){
    for (int i=300; i--;) box[i].clear(), lock[i]=0;
    memset(plan,-1,sizeof plan);
    memset(have,0,sizeof have);
    int hag[30][30]={};

    int k,n; cin>>k>>n;
    vector<int> init;
    for (int i=0; i<k; i++){
      int kx; cin>>kx; init.push_back(kx);
    }

    map<int,int> locks;
    for (int i=0; i<n; i++){
      int ki; cin>>lock[i]>>ki; locks[lock[i]];
      for (int j=0; j<ki; j++){
        int u; cin>>u; box[i].push_back(u);
      }
    }

    int kypes=0;
    for (map<int,int>::iterator it=locks.begin(); it!=locks.end(); ++it) it->second=kypes++;
    for (auto i: init) if (locks.count(i)) have[0][locks[i]]++;

    for (int i=0; i<n; i++){
      for (int j: box[i])
        if (locks.count(j))
          hag[i][locks[j]]++;
      hag[i][lock[i]=locks[lock[i]]]--;
    }
 
    for (int mask=1,msb=1,msi=0; mask<(1<<n); mask++, msb=(mask==msb*2?(msi++,msb*2):msb)){
      for (int i=kypes; i--;) have[mask][i]=have[mask&~msb][i]+hag[msi][i];
    }

    plan[0]=0;
    for (int mask=0; mask<(1<<n); mask++){
      int moves=__builtin_popcount(mask);
      if (!~plan[mask]) continue;

      ll off=0;
      for (int i=0; i<n; i++)
        if ((1<<i)&mask)
          continue;
        else{
          if (have[mask][lock[i]]){
            plan[mask|(1<<i)]=min(plan[mask|(1<<i)],off*fact[n-1-moves]+plan[mask]);
          }
          ++off;
        }
    }

    cout<<"Case #"<<tst<<":";
    if (!~plan[(1<<n)-1]) cout<<" IMPOSSIBLE\n"; else{
      int val[100]={};
      bool got[100]={};
      for (int i=0; i<n; i++){
        while (got[val[i]]) ++val[i];
        while (fact[n-i-1]<=plan[(1<<n)-1]){
          val[i]++;
          plan[(1<<n)-1]-=fact[n-i-1];
          while (got[val[i]]) ++val[i];
        }
        got[val[i]]=true;
      }
      for (int i=0; i<n; i++) cout<<" "<<val[i]+1;
      cout<<endl;
    }
  }
}

