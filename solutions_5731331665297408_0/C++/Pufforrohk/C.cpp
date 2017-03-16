#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int N,E;

bool g[50][50];

vector<pair<int,int>> vp;


inline int get(int el){
  return vp[el].second;
}

bool check(vector<int>& perm){
  stack<int> s;
  int i=1;
  s.push(0);
  while(i<N){
    while(!s.empty() && !g[get(perm[s.top()])][get(perm[i])]){
      s.pop();
    }
    if(s.empty())
      return false;
    s.push(i);
    i++;
  }
  return true;
}

void solve(){
  cin>>N>>E;
  vp.clear();
  vp.resize(N);
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      g[i][j]=false;
  for(int i=0;i<N;i++){
    int v;    
    cin>>v;
    vp[i]=make_pair(v,i);
  }
  for(int i=0;i<E;i++){
    int f,t;
    cin>>f>>t;
    f--;
    t--;
    g[f][t]=true;
    g[t][f]=true;
  }
  sort(vp.begin(),vp.end());

  vector<int> perm(N);
  for(int i=0;i<N;i++)
    perm[i]=i;
  while(!check(perm)){
    next_permutation(perm.begin(),perm.end());    
  }
  for(int i:perm)
    cout<<vp[i].first;
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
    cout<<endl;
  }
}
