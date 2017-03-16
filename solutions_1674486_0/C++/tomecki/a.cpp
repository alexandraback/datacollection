#include<cstdio>
#include<vector>
using namespace std;

bool v[1010];
vector<int> g[1010];
int n,m,st[1010],l,s, e[1010];

bool dfs(int a, int et){
  e[a] = et;
  bool f = 0;
  for(vector<int>::iterator it=g[a].begin(); it!=g[a].end(); it++){
    if(e[*it]==e[a])
        return 1;
    e[*it]=et;
    f |= dfs(*it, et);
    
  }
  return f;
}

int main(int argc, const char *argv[]){
  scanf("%d", &m);
  for(int i = 0; i < m; i++){

    bool f = 0;
    for(int wer = 0; wer < 1010; wer++){
      g[wer].clear();
      v[wer]=0;
      st[wer]=0;
      e[wer]=0;
    }
    
    scanf("%d", &n);

    for(int j = 1; j <=n; j++){
      scanf("%d", &l);
      for(int k = 0; k < l; k++){
        scanf("%d", &s);
        g[j].push_back(s);
        st[s]++;
      }
    }

    for(int j = 1; j <= n; j++){
      if(st[j]==0){
        f |= dfs(j, j);
      }
    }


    printf("Case #%d: ", i+1);
    if(f)
      printf("Yes\n");
    else
      printf("No\n");



  }
  
  return 0;
}
