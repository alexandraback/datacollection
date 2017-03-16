
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <cassert>
using namespace std;


int solve2(){
  int D;
  cin>>D;
  vector<int> seq(D);
  int mx= 0;
  for(int i=0;i<D;i++){
    cin>>seq[i];
    mx=max(mx,seq[i]);
  }
  int best = mx;
  for(int i=1;i<=mx;i++){
    int moves=i;
    for(int val:seq)
      moves+=((val-1)/i);
    best=min(best,moves);
  }
  return best;
}

int solve(){
  int D;
  cin>>D;
  priority_queue<int> pq;
  for(int i=0;i<D;i++){
    int el;
    cin>>el;
    pq.push(el);
  }
  int best = pq.top();
  int tot = 0;
  while(tot<best){
    int sol = tot+pq.top();
    best=min(best,sol);
    int v =pq.top();
    pq.pop();
    int l = v/2;
    int u = (v+1)/2;
    assert(l+u==v);
    pq.push(l);
    pq.push(u);
    tot++;
  }
  return best;
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve2()<<endl;
  }
  return 0;
}
