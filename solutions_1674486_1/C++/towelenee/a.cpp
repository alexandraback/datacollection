#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
#define forn(i, n ) for(int i = 0;i < (int)(n);i++)
#define deb(x) cerr<<#x<<'='<<(x)<<endl

using namespace std;

vector< vector<int> > g;
vector<int> out;
bool fl = false;
void dfs(int v){
  out[v] = 1;
  forn(i,g[v].size()){
    if(out[g[v][i]] == 0)
      dfs(g[v][i]);
    else if(out[g[v][i]] == 2){
      fl = true;
    }
  }
  out[v] = 2;
}
int main(){
  int _;
  scanf("%d",&_);
  forn(__,_){
    printf("Case #%d: ",__ + 1);
    int n;
    scanf("%d",&n);
    g.resize(n);
    forn(i,n){
      int k;
      scanf("%d",&k);
      g[i].resize(k);
      forn(j,k){
        scanf("%d",&g[i][j]);
        g[i][j]--;
      }
    }
    fl = false;
    forn(i,n){
      out = vector<int>(n,0);
      dfs(i);
    }
    printf("%s\n",fl?"Yes":"No");
  }
}
