#include <stdio.h>
#include <string.h>

int T,R,C,M,resp,cont, linhas, sobras,vazio;
int tabela[60][60];
int num[60];

int f(int soma, int pos, int ultimo){
  if(soma==vazio){
    for(int j=0; j<num[0]+1; j++){
      tabela[0][j] = 0;
    }
    for(int i=0; i<pos; i++){
      for(int j=0; j<num[i]+1; j++){
        tabela[i+1][j] = 0;
      }
    }
    tabela[0][0]=2;
    return 1;
  }
  else if(soma > vazio){
    return 0;
  }
  else if(pos==R-1){
    return 0;
  }
  
  if(pos==0){
    for(int i=1; i<=ultimo; i++){
      if(soma+(2*i+2)==vazio){
        num[pos]=i;
        return f(soma+(2*i+2), pos+1, i);
      }
    }
    
    for(int i=1; i<=ultimo; i++){
      num[pos]=i;
      if(f(soma+(2*i+2), pos+1, i)) return 1;
    }
    return 0;
  }
  else{
    for(int i=1; i<=ultimo; i++){
      if(soma+(i+1)==vazio){
        num[pos]=i;
        return f(soma+(i+1), pos+1, i);
      }
    }
    
    for(int i=1; i<=ultimo; i++){
      num[pos]=i;
      if(f(soma+(i+1), pos+1, i)) return 1;
    }
    return 0;
  }
  
}

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    resp = 1;
    memset(tabela, 0, sizeof(tabela));
    memset(num, 0, sizeof(num));
    scanf(" %d %d %d", &R, &C, &M);
    tabela[R-1][C-1]=2;
    if(R==1){
      for(int j=0; j<M; j++){
        tabela[0][j] = 1;
      }
    }
    else if(C==1){
      for(int i=0; i<M; i++){
        tabela[i][0] = 1;
      }
    }
    else if(M==0){
      resp = 1;
    }
    else if(R*C-M==1){
      for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
          tabela[i][j] = 1;
        }
      }
      tabela[0][0] = 2;
    }
    else if(R*C-M<=3){
      resp = 0;
    }
    else if(R*C-M >= 2*R + 2*C - 4){
      for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
          tabela[i][j] = 1;
        }
      }
      resp = 1;
      vazio = R*C-M;
      for(int i=0; i<R; i++){
        tabela[i][0] = 0;
        tabela[i][1] = 0;
      }
      for(int j=0; j<C; j++){
        tabela[0][j] = 0;
        tabela[1][j] = 0;
      }
      vazio-=(2*R + 2*C - 4);
      for(int i=2; i<R; i++){
        for(int j=2; j<C; j++){
          if(vazio>0){
            tabela[i][j]=0;
            vazio--;
          }
        }
      }
      tabela[0][0] = 2;
    }
    else{
      vazio = R*C-M;
      
      for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
          tabela[i][j] = 1;
        }
      }
      
      resp = f(0,0,C-1);
      
      tabela[0][0] = 2;
    }
    
    printf("Case #%d:\n", u);
    if(resp==0){
      printf("Impossible\n");
    }
    else{
      for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
          if(tabela[i][j]==0) printf(".");
          else if(tabela[i][j]==1) printf("*");
          else printf("c");
        }
        printf("\n");
      }
    }
  }
  return 0;
}
