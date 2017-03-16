#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
     
template <typename Weight, int MAX_N, Weight INF> class MaxFlow{
private:
  struct E{
    int to, rev;
    Weight lim;
    E(int x, Weight y, int z){
      to = x;
      lim = y;
      rev = z;
    }
  };
     
  vector<E> edge[MAX_N];
  int lev[MAX_N];
  int iter[MAX_N];
     
     
  Weight dfs(int s, int g, Weight f){
    if(s == g)return f;
    for(int &i = iter[s];i < edge[s].size();i++){
      E &e = edge[s][i];
      if(lev[e.to] <= lev[s] || e.lim <= 0)continue;
      Weight tmp = dfs(e.to, g, min(f, e.lim));
      if(tmp<1e-9)continue;
      e.lim -= tmp;
      edge[e.to][e.rev].lim += tmp;
      return tmp;
    }
    return 0;
  }
     
  void bfs(int x){
    queue<int> q;
    q.push(x);
    int p = 0;
    while(!q.empty()){
      for(int i = q.size();i--;){
	int tmp = q.front();q.pop();
	if(lev[tmp] != INF)continue;
	lev[tmp] = p;
	for(int j = 0;j < edge[tmp].size();j++){
	  if(edge[tmp][j].lim > 0 && lev[edge[tmp][j].to] == INF)q.push(edge[tmp][j].to);
	}
      }
      p++;
    }
  }
     
public:
  void make_edge(int a, int b, Weight l){
    edge[a].push_back(E(b, l, edge[b].size()));
    edge[b].push_back(E(a, 0, edge[a].size() - 1));
  }
     
  Weight max_flow(int s, int g){
    Weight res = 0;
    bool fin = false;
    while(!fin){
      fill(lev, lev + MAX_N, INF);
      fill(iter, iter + MAX_N, 0);
      bfs(s);
      fin = true;
      while(true){
	Weight p = dfs(s, g, INF);
	if(p < 1e-9)break;
	fin = false;
	res += p;
      }
    }	
    return res;
  }
};
     

string str1[1080], str2[1080];
void solve(){
  int n;
  vector<string> strs1, strs2;

  MaxFlow<int,2010, (1 << 30)> mf;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> str1[i] >> str2[i];

    strs1.push_back(str1[i]);
    strs2.push_back(str2[i]);
  }  
  sort(strs1.begin(), strs1.end());
  sort(strs2.begin(), strs2.end());
   
  strs1.erase(unique(strs1.begin(), strs1.end()), strs1.end());
  strs2.erase(unique(strs2.begin(), strs2.end()), strs2.end());

  for(int i = 0;i < n;i++){
    int a = lower_bound(strs1.begin(), strs1.end(), str1[i]) - strs1.begin();
    int b = lower_bound(strs2.begin(), strs2.end(), str2[i]) - strs2.begin();
        mf.make_edge(a, 1000 + b, 1);
  }
  for(int i = 0;i < strs1.size();i++){
    mf.make_edge(2000, i, 1);
  }
  for(int i = 0;i < strs2.size();i++){
    mf.make_edge(1000 + i, 2001, 1);
  }

  cout<< n - ((strs1.size() + strs2.size()) - mf.max_flow(2000, 2001));

}


int main(){
  int t;
  cin >> t;
  for(int i = 1;i <= t;i++){
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
