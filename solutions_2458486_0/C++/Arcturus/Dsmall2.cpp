#include <stdio.h>

struct ST{
  int key, nkey;
  int keys[210];
  bool open;
};

int keys[210];
ST t[210];
int order[210];
int modal[210][210];
int totalkey[210];
int N, K;
int icase;

bool Work(int level){
  if(level >= N) return true;
  bool res;
  bool getmodal;
  
  for(int i=0; i<N; i++){
    if((totalkey[t[i].key] > 0)&&(totalkey[t[i].key] == modal[t[i].key][t[i].key])){
      return false;
    }
  }
  
  for(int i=0; i<N; i++){
    if(t[i].open) continue;
    else if(keys[t[i].key] == 0) continue;
    
    getmodal = false;
    for(int j=0; j<t[i].nkey; j++){
      if(modal[t[i].keys[j]][t[i].key] > 0){
        getmodal = true;
        break;
      }
    }
    
    keys[t[i].key]--;
    totalkey[t[i].key]--;
    for(int j=0; j<t[i].nkey; j++){
      keys[t[i].keys[j]]++;
      modal[t[i].key][t[i].keys[j]]--;
    }
    t[i].open = true;
    order[level] = i;
    res = Work(level+1);
    
    keys[t[i].key]++;
    totalkey[t[i].key]++;
    for(int j=0; j<t[i].nkey; j++){
      keys[t[i].keys[j]]--;
      modal[t[i].key][t[i].keys[j]]++;
    }
    t[i].open = false;
    if((keys[t[i].key] > 1)||(getmodal)) return res;
    else if(res) return true;
  }
  return false;
}

int main(){
  int jcase;
  int temp;
  
  freopen("D-small-attempt1.in", "r", stdin);
  freopen("D-small-attempt1.out", "w", stdout);
  scanf("%d", &jcase);

  for(icase=0; icase<jcase; icase++){
    scanf("%d %d", &K, &N);
    for(int i=0; i<210; i++) keys[i] = 0;
    for(int i=0; i<210; i++) totalkey[i] = 0;
    for(int i=0; i<210; i++){
      for(int j=0; j<210; j++) modal[i][j] = 0;
    }
    
    for(int i=0; i<K; i++){
      scanf("%d", &temp);
      keys[temp]++;
      totalkey[temp]++;
    }
    
    for(int i=0; i<N; i++){
      t[i].open = false;
      scanf("%d %d", &t[i].key, &t[i].nkey);
      for(int j=0; j<t[i].nkey; j++){
        scanf("%d", &t[i].keys[j]);
        modal[t[i].key][t[i].keys[j]]++;
        totalkey[t[i].keys[j]]++;
      }
    }
    
    printf("Case #%d:", icase+1);
    if(Work(0)){
      for(int i=0; i<N; i++) printf(" %d", order[i]+1);
      printf("\n");
    }
    else printf(" IMPOSSIBLE\n");
  }
  return 0;
}
