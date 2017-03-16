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

vector<int> vexer[400];
int box[400][400];
int have[400];
int card[400];
int lock[400];
int kypes;
int n;

bool used[400];
void apply(int x,bool up=true){
  have[lock[x]]-=(up?1:-1);
  for (int i: vexer[x]) have[i]+=(up?1:-1);
  used[x]=up;
}

bool did[400];
vector<int> plan;
vector<int> positive[400];
queue<int> bfs;

void dispatch(int x){
  for (auto t: positive[x]){
    if (have[lock[t]] and not used[t]){
      apply(t); plan.push_back(t);
      for (int q: vexer[t])
        if (not did[q])
          did[q]=true, bfs.push(q);
    }
  }
}

void run(){
  int tsts; cin>>tsts; for (int tst=1; tst<=tsts; ++tst){
    for (int i=400; i--;) vexer[i].clear(), lock[i]=0;
    memset(used,0,sizeof used);
    memset(have,0,sizeof have);
    memset(card,0,sizeof card);
    memset(box,0,sizeof box);

    int k; cin>>k>>n;
    vector<int> init;
    for (int i=0; i<k; i++){
      int kx; cin>>kx; init.push_back(kx);
    }

    map<int,int> locks;
    for (int i=0; i<n; i++){
      int ki; cin>>lock[i]>>ki; locks[lock[i]];
      for (int j=0; j<ki; j++){
        int u; cin>>u; vexer[i].push_back(u);
      }
    }

    kypes=0;
    for (map<int,int>::iterator it=locks.begin(); it!=locks.end(); ++it) it->second=kypes++;
    for (auto i: init) if (locks.count(i)) have[locks[i]]++;

    for (int i=0; i<n; i++){
      for (int &j: vexer[i])
        if (locks.count(j))
          box[i][j=locks[j]]++,
          ++card[i];
        else
          j=-1;
      sort(vexer[i].rbegin(),vexer[i].rend());
      while (vexer[i].size() and vexer[i].back()==-1) vexer[i].pop_back();
      lock[i]=locks[lock[i]];
    }

    vector<int> res;
    for (int i=0; i<n and res.size()==i; i++){
      for (int j=0; j<n; j++){
        if (not used[j] and have[lock[j]]){
          apply(j,1);

          plan.clear();
          for (int i=200; i--;) positive[i].clear();
          vector<int> cardinal;
          vector<int> worthless;

          for (int q=n; q--;){
            if (used[q]) continue;
            else if (not card[q]) worthless.push_back(q);
            else if (not box[q][lock[q]]) cardinal.push_back(q);
            else positive[lock[q]].push_back(q);
          }

          memset(did,0,sizeof did);
          for (int q=kypes; q--;) if (have[q]) bfs.push(q), did[q]=true;
          while (not bfs.empty()) dispatch(bfs.front()), bfs.pop();

          for (;;){
            int will=-1;
            for (int q: cardinal)
              if (have[lock[q]] and not used[q])
                if (will==-1 or box[q][lock[q]] or not box[will][lock[will]] and card[q]>=card[will])
                  will=q;
            if (!~will) break;
            apply(will,1); plan.push_back(will);
            for (int y: vexer[will])
              if (not did[y])
                bfs.push(y);
            while (not bfs.empty()) dispatch(bfs.front()), bfs.pop();
          }

          for (int q: worthless)
            if (have[lock[q]] and not used[q])
              apply(q,1), plan.push_back(q);

          bool ok=(res.size()+plan.size()+1==n);
          for (int q: plan) apply(q,0);

          if (ok){
            res.push_back(j);
            break;
          }

          apply(j,0);
        }
      }
    }

    cout<<"Case #"<<tst<<":";
    if (res.size()<n) cout<<" IMPOSSIBLE\n"; else{
      for (int i=0; i<n; i++) cout<<" "<<res[i]+1;
      cout<<endl;
    }
  }
}

