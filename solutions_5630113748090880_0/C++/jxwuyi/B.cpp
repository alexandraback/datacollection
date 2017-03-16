#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

int N, L;
vector<vector<int> > A;

vector<int> adj[500];

bool cmpl(vector<int>&A, vector<int>&B){
  for(int i=0;i<N;++i)
    if(A[i]>=B[i]) return false;
  return true;
}

int mark[500];
vector<int> Q[2];

int go(int u, int c){
  mark[u] = c;
  Q[c].push_back(u);
  for(auto&v:adj[u]){
    if(mark[v]<0)
      go(v, c ^ 1);
  }
}

bool cmpA(int a, int b){
  return cmpl(A[a], A[b]);
}

vector<int>T[100];
int cnt[100];
vector<int> solve() {
  map<int,int> cnt;
  for(int i=0;i<L;++i){
    for(auto&x:A[i])
      cnt[x]++;
  }
  vector<int> res;
  for(auto&p:cnt)
    if(p.second&1)res.push_back(p.first);
  sort(res.begin(), res.end());
  return res;
}

void run() {
  scanf("%d",&N); L = 2 * N - 1;
  A.resize(L);
  for(int i=0;i<L;++i){
    A[i].clear();int x;
    for(int j=0;j<N;++j){scanf("%d",&x);A[i].push_back(x);}
  }
  vector<int> ans = solve();
  for(auto&x:ans)printf(" %d", x);
  puts("");
}

int main() {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int test;
  scanf("%d",&test);
  for(int no=1;no<=test;++no){
    printf("Case #%d:", no);
    run();
  }
}


