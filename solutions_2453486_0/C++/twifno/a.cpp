#include<cstdio>
#include<cstring>

char a[4][10];

bool ccol(char c){
  for(int i = 0; i < 4; i++){
    bool flag = true;
    for(int j = 0; j < 4; j++)
      if(a[j][i] != c && a[j][i] != 'T'){
        flag = false;
        break;
      }
    if(flag) return true;
  }
  return false;
}
bool crow(char c){
  for(int i = 0; i < 4; i++){
    bool flag = true;
    for(int j = 0; j < 4; j++)
      if(a[i][j] != c && a[i][j] != 'T'){
        flag = false;
        break;
      }
    if(flag) return true;
  }
  return false;
}
bool cdig(char c){
  bool flag = true;
  for(int i = 0; i < 4; i++){
    if(a[i][i] != c && a[i][i] != 'T'){
        flag = false;
        break;
    }
  }
  if(flag) return true;
  flag = true;
  for(int i = 0; i < 4; i++){
    if(a[i][3-i] != c && a[i][3-i] != 'T'){
        flag = false;
        break;
    }
  }
  if(flag) return true;
  return false;
}

bool checkdot(){
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      if(a[i][j] == '.')
        return true;
  return false;
}

int main(){
  int T;
  scanf("%d\n", &T);
  for(int i = 1; i <= T; i++){
    for(int j = 0; j<4; j++){
      gets(a[j]);
     //puts(a[j]);
    }
    if(i != T) scanf("\n");
    if(crow('O') || ccol('O') || cdig('O')){
      printf("Case #%d: O won\n", i);
      continue;
    }
    if(crow('X') || ccol('X') || cdig('X')){
      printf("Case #%d: X won\n", i);
      continue;
    }
    if(checkdot()){
      printf("Case #%d: Game has not completed\n", i);
      continue;
    }
    printf("Case #%d: Draw\n", i);
  }
  return 0;
}
