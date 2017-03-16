#include<iostream>

using namespace std;

int enums[1200];
int edges[1200][20];
bool used[1200];
bool dfs(int x) {
  if (used[x]) {
    return true;
  }
  used[x] = true;
  for(int i=0; i<enums[x]; ++i){
    int n = edges[x][i];
    if(dfs(n)) return true;
  }
  return false;
}
int main(){
  int cas;
  cin>>cas;
  for(int ca=1 ;ca<=cas; ++ca){
    int n;
    cin>>n;
    for(int i=0 ;i<n; ++i){
      cin>>enums[i];
      for(int j=0 ;j<enums[i]; ++j){
        cin>>edges[i][j];
        edges[i][j]--;
      }
    }

    cout<<"Case #"<<ca<<": ";
    bool found= false;
    for(int i=0; i<n; ++i){
      memset(used,0,sizeof(used));
      if (dfs(i)) {
        found = true;
        cout<<"Yes"<<endl;
        break;
      }
    }
    if (!found){
      cout<<"No"<<endl;
    }

  }
}
