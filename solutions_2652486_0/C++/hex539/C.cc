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

ll prod[10];
ll val[5];
ll res[5];
real chance=-1;
ll r,n,m,k;

void dfs(int left,int last=2){
  if (left--){
    for (int i=last; i<=m; i++){
      val[left]=i;
      dfs(left,i);
    }
    return;
  }

  real prob[6][3126]={};
  prob[0][1]=1;
  for (int i=0; i<n; i++){
    for (int j=1; j<=3125; j++){
      prob[i+1][j *      1] += 0.5L*prob[i][j];
      prob[i+1][j * val[i]] += 0.5L*prob[i][j];
    }
  }

  real final=1e20L;
  for (int i=0; i<k; i++) final*=prob[n][prod[i]];
  if (final>=chance){
    for (int i=0; i<n; i++) res[i]=val[i];
    chance=final;
  }
}

void run(){
  {int u; cin>>u; cout<<"Case #1:"<<endl;}

  cin>>r>>n>>m>>k;
  for (int i=0; i<r; i++){
    for (int j=0; j<k; j++){
      cin>>prod[j];
    }
    chance=-1;
    dfs(n);
    for (int i=0; i<n; i++) cout<<res[i]; cout<<endl;
    //cout<<"("<<chance<<")"<<endl;
  }
}

