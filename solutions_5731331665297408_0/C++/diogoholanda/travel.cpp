#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node{
  int cid;
  int zip;
};

int T,N,M,c1,c2,raiz,min_raiz,cont,fim,anterior,proximo;
int id[100];
int tabela[100][100];
int marcado[100];
int marcado2[100];
int marcado3[100];
int ordem[100];
int temp[100];
node v[100];
int pilha[100];

int compara(node a, node b){
  return a.zip < b.zip;
}

int dfs(int a){
  marcado3[a]=1;
  for(int i=0; i<N; i++){
    if(tabela[a][i] == 1 && marcado3[i] == 0 && marcado2[i] != 2) dfs(i);
  }
}

int check(){
  memset(marcado3,0,sizeof(marcado3));
  dfs(raiz);
  
  for(int i=0; i<N; i++){
    if(marcado3[i]==0 && marcado2[i]==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    memset(tabela,0,sizeof(tabela));
    memset(marcado, 0, sizeof(marcado));
    
    scanf(" %d %d", &N, &M);
    
    raiz = -1;
    min_raiz = 2000000000;
    
    for(int i=0; i<N; i++){
      scanf(" %d", &id[i]);
      if(id[i]<min_raiz){
        min_raiz = id[i];
        raiz = i;
      }
      v[i].cid = i;
      v[i].zip = id[i];
    }
    
    sort(v,v+N,compara);
    
    for(int i=0; i<M; i++){
      scanf(" %d %d", &c1, &c2);
      c1--;
      c2--;
      tabela[c1][c2]=1;
      tabela[c2][c1]=1;
    }
    
    ordem[0] = raiz;
    cont = 1;
    pilha[0] = raiz;
    fim = 1;
    marcado[raiz] = 1;
    
    while(cont < N){
      for(int k=0; k<N; k++){
        proximo = v[k].cid;
        if(marcado[proximo] != 0) continue;
        
        anterior = -1;
        for(int pos = fim-1; pos>=0; pos--){
          if(tabela[pilha[pos]][proximo] == 1){
            anterior = pilha[pos];
            
            for(int i=0; i<N; i++) marcado2[i] = marcado[i];
            for(int i=pos+1; i<fim; i++) marcado2[pilha[i]] = 2;
            marcado2[proximo] = 1;
            
            if(check()){
              ordem[cont]=proximo;
              cont++;
              
              for(int i=pos+1; i<fim; i++) marcado[pilha[i]] = 2;
              
              fim = pos + 1;
              pilha[fim] = proximo;
              fim++;
              marcado[proximo] = 1;
              break;
            }
            else anterior = -1;
          }
        }
        
        if(anterior==-1) continue;
        else break;
      }
    }
    
    printf("Case #%d: ", u);
    for(int i=0; i<N; i++) printf("%d", id[ordem[i]]);
    printf("\n");
  }
  return 0;
}
