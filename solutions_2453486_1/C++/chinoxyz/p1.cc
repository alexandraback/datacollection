#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

char sol0[] = "X won";
char sol1[] = "O won";
char sol2[] = "Draw";
char sol3[] = "Game has not completed";

char tablero[6][6];


bool busqueda(char c){
  int num;
  for(int i = 0; i < 4; i++){
    num = 0;
    for(int j = 0; j < 4; j++){
      if(tablero[i][j] == c || tablero[i][j] == 'T') num++;
    }
    if(num == 4) return true;
  }
  for(int i = 0; i < 4; i++){
    num = 0;
    for(int j = 0; j < 4; j++){
      if(tablero[j][i] == c || tablero[j][i] == 'T') num++;
    }
    if(num == 4) return true;
  }
  
  num = 0;
  for(int i = 0; i < 4; i++){
    if(tablero[i][i] == c || tablero[i][i] == 'T')num++;
  }if(num == 4) return true;
  
  num = 0;
  for(int i = 0; i < 4; i++){
    if(tablero[i][4-i-1] == c || tablero[i][4-i-1] == 'T')num++;
  }if(num == 4) return true;
  
  return false;
  
}

bool punto(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(tablero[i][j] == '.') return true;
    }
  }
  return false;
}


int main(){
  int T;
  int sol;
  scanf("%d\n", &T);
  for(int t = 0; t < T; t++){
    for(int i = 0; i < 4; i ++){
      scanf("%s\n", tablero[i]);
      if(tablero[i][0] == '\n' || tablero[i][0] == 0) continue;
    }
    
    printf("Case #%d: ", t+1);
    if(busqueda('X')){
      printf("%s\n", sol0);
      continue;
    }
    if(busqueda('O')){
      printf("%s\n", sol1);
      continue;
    }
    if(!punto()){
      printf("%s\n", sol2);
      continue;
    }else{
      printf("%s\n", sol3);
      continue;
    }
    
  }
  
}
