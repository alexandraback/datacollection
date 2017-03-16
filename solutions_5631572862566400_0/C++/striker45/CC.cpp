#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v;
vector<int> tsort;
bool visited[1004];
int dp=0,dpi=0;

void dfs(int i,int dpth){
if(visited[i])return;
visited[i]=1;

for(int j=0; j<v[i].size(); j++)
    if(!visited[v[i][j]]){
            if((dpth+1)>dp){
                dp=dpth+1;
                 dpi=i;
            }
     dfs(v[i][j],dpth+1);}
}

int main() {
    int T;
    cin >> T;
    for(int i=1; i<= T; i++){
     v=vector<vector<int> > (1003);
         dp=0;dpi=0;
       
       int N;
       cin>>N;
       for(int j=1; j<=N; j++){
       	int d;
            cin>>d;
         v[j].push_back(d);
        v[d].push_back(j);
       }
      memset(visited,0,sizeof visited);
      for(int j=1; j<=N; j++){
        if(!visited[j])
            dfs(j,1);
      }

      memset(visited,0,sizeof visited);

	dfs(dpi,1);
	cout<<"Case #"<<i<<": "<<dp<<endl;
    }
  return 0;
}
