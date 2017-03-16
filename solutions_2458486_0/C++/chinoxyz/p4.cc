#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int N, K, num, e;
vector <int> keys[205];
int A[205];
vector<int> dep[500];
vector<int> mykey;

bool visit[500];
int ord[500];


class elem{
  public:
  int c, n;
  bool operator<(const elem &s) const {
    return (c < s.c);
  }
};


int nc;
int DFS(int k, int pred){
  int v;
  
  
  //printf("%d", k);
  
  for(int i = 0; i < dep[k].size(); i++){
    if(dep[k][i] == pred) continue;
    //printf("(%d) ", dep[k][i]);
    if(visit[dep[k][i]]){
      //ord[dep[k][i]] = nc++;
      if(ord[dep[k][i]] < nc){
        ord[dep[k][i]] = nc++;
      }
      continue;
    }
    
    ord[dep[k][i]] = nc++;
    visit[dep[k][i]] = true;
    
    
    for(int j = 0; j < keys[dep[k][i]].size(); j++){
      v = keys[dep[k][i]][j];
      
      DFS(v, k);
    }
  }
  
}

vector <elem> res;
int main(){
  int T;
  scanf("%d", &T);
  for(int t = 0; t < T; t++){
    scanf("%d %d",  &K, &N);
    
    mykey.clear();
    for(int i = 0; i < K; i++){
      scanf("%d", &e);
      mykey.push_back(e);
    }
    
    for(int i = 0; i < N; i++){
      scanf("%d %d", &A[i], &num);
      keys[i].clear();
      for(int j = 0; j < num; j++){
        scanf("%d", &e);
        keys[i].push_back(e);
      }
    }
    
    for(int i = 0; i < 500; i++){
      dep[i].clear();
    }
    for(int i = 0; i < N; i++){
      dep[A[i]].push_back(i);
    }
    
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < K; i++){
      DFS(mykey[i], -1);
    }
    bool b = true;
    nc = 0;
    elem e1;
    
    for(int i = 0; i < N && b; i++){
      
      if(!visit[i]) b = false;
    }
    res.clear();
    for(int i = 0; i < N && b; i++){
      e1.c = ord[i];
      e1.n = i;
      res.push_back(e1);
    }
    
    sort(res.begin(), res.end());
    
    printf("Case #%d:", t+1);
    if(b){
      for(int i = 0; i < N; i++){
        printf(" %d", res[i].n+1);
      }
    }else{
      printf(" IMPOSSIBLE");
    }
    printf("\n");
    
    
    
    
    
    
  }
}
