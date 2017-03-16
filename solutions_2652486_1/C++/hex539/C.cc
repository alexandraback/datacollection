#include <functional>/*{{{*/
#include <unordered_set>
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

ll val[15];
ll res[15];
ll prod[15];
real chance=-1;
ll r,n,m,k;
int useful[20];
unordered_set<ll> important;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int bad=0;
void dfs(int left,int last=2,ll tot=1){
  if (80<=bad or chance>1e-10L) return;

  if (left--){
    bool did=false;
    int consider[9];
    for (int i=0; i<=m-last; i++) consider[i]=i+last;
    random_shuffle(consider,consider+m-last);

//    for (int i=last; i<=m; i++){
    for (int z=0; z<=m-last; ++z){
      int i=consider[z];
      if (useful[i] or i==m and not did){
        dfs(left,val[left]=i,tot*i);
        did=true;
      }
    }
    return;
  }

  if (chance>=-0.5L){
    ll tot=1; for (int i=k; i--;) tot=tot/gcd(tot,prod[i])*prod[i];
    for (int i=n; i--;) if (tot%val[i]) return;

    tot=1; for (int i=n; i--;) tot*=val[i];
    for (int i=k; i--;) if (tot%prod[i]) return;
  }

  map<int,real> prob[13];

  prob[0][1]=8;
  for (int i=0; i<n; i++){
    for (auto j: prob[i]){
      prob[i+1][j.first *      1] += 0.5L*j.second;
      if (important.count(j.first*val[i]))
      prob[i+1][j.first * val[i]] += 0.5L*j.second;
    }
  }

  real final=1e20L;
  for (int i=0; i<k and final>=chance; i++) final*=prob[n][prod[i]];
  if (final>=chance){
    for (int i=0; i<n; i++) res[i]=val[i];
    chance=final;
  }

  ++bad;
}

void run(){
  {int u; cin>>u; cout<<"Case #1:"<<endl;}

  cin>>r>>n>>m>>k;
  for (int i=0; i<r; i++){
    memset(useful,0,sizeof useful);
    important.clear();

    for (int j=0; j<k; j++){
      cin>>prod[j];
      for (int q=1; q*q<=prod[j]; q++)
        if (prod[j]%q==0)
          important.insert(q),
          important.insert(prod[j]/q);

      for (int q=2,z=prod[j]; q<=m; q++){
        if (z%q==0){
          int t=0; do ++t,z/=q; while (z%q==0);
          useful[q]=max(useful[q],t);
        }
      }
    }
    for (int i=2; i<=m; i++) useful[i]=true;
    chance=-1; bad=0;
    dfs(n);
    for (int i=0; i<n; i++) cout<<res[i]; cout<<endl;
    // cout<<"("<<chance<<")"<<endl;
  }
}

