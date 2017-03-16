#include <bits/stdc++.h>

using namespace std;

#define p_b(a,b) a.push_back(b)
#define all(a) (a.begin(),a.end())
#define m_p(a,b) make_pair(a,b)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,m;
vector<pair<string,int> > pid;
vi adj[51];
int v[51];
string ref[51];
string sol;

void dfs(int i){
  if(v[i])return;
  v[i]=1;
  sol+=ref[i];
  for(int j=0;j<adj[i].size();j++)
    dfs(adj[i][j]);
}

void solve(){
  for(int i=0;i<50;i++)
    adj[i].clear();
  cin>>n>>m;

  pid.clear();
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    p_b(pid,m_p(s,i));
  }
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--,b--;
    p_b(adj[a],b);
    p_b(adj[b],a);
  }
  for(int i=0;i<n;i++)
    sort(adj[i].begin(),adj[i].end());
  sort(pid.begin(),pid.end());
  for(int i=0;i<n;i++)
    ref[pid[i].second]=pid[i].first;
  string bsol="0";
  for(int i=0;i<n;i++){
    sol="";
    memset(v,0,sizeof(v));
    dfs(i);
    if(bsol=="0")
      bsol=sol;
    else if(sol.compare(bsol)<0)
      bsol=sol;
  }
  cout<<bsol<<endl;
}

int main(){
  int t,prob=1;
  cin>>t;
  while(t--){
    cout<<"Case #"<<prob++<<": ";
    solve();
  }
}
