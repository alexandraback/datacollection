#include<bits/stdc++.h>
using namespace std;
int n,a;
vector<int> G[1001];
int t[1001][1001];
int u[1001];
bool visited[1001];

int dfs(int pos,int prev){
  visited[pos]=true;
  int res=0;
  for(int i=0;i<(int)G[pos].size();i++){
    int to=G[pos][i];
    if(to==prev)continue;
    res=max(res,dfs(to,pos));
  }
  return res+1;
}

void init(){
  for(int i=0;i<1001;i++){
    G[i].clear();
    visited[i]=false;
    for(int j=0;j<1001;j++)t[i][j]=0;
  }
}

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>n;
    init();

    for(int i=1;i<=n;i++){
      cin>>a;
      u[i]=a;
      G[a].push_back(i);
      t[a][i]++;
      t[i][a]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(t[i][j]==2){
          ans+=dfs(i,j);
          ans+=dfs(j,i);
        }
      }
    }
    int ans2=0;
    for(int i=1;i<=n;i++){
      if(visited[i])continue;
      int pos=i,cnt=0;
      while(1){
        if(visited[pos])break;
        visited[pos]=true;
        cnt++;
        pos=u[pos];
      }
      if(pos==i)ans2=max(ans2,cnt);
    }
    cout<<"Case #"<<tc<<": "<<max(ans,ans2)<<endl;
  }
  return 0;
}
