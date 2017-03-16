#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char sol[2][100] = {"YES", "NO"};
int tablero[105][105];
int num[105];
int maxfila[105], maxcolumna[105];
int N, M;

bool verificar(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(maxfila[i] > tablero[i][j] && maxcolumna[j] > tablero[i][j]) return false;
    }
  }

  
  return true;
}

int main(){
  int T;
  
  scanf("%d", &T);
  for(int t = 0; t < T; t++){
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i< N; i++){
      for(int j = 0; j< M; j++){
        scanf("%d", &tablero[i][j]);
      }
    }

    memset(num, 0, sizeof(num));
    memset(maxfila, 0, sizeof(maxfila));
    memset(maxcolumna, 0, sizeof(maxcolumna));
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        num[tablero[i][j]]++;
        maxfila[i] = max(tablero[i][j], maxfila[i]);
        maxcolumna[j] = max(tablero[i][j], maxcolumna[j]);
      }
    }
    
    
    
    
    
    
    
    printf("Case #%d: ", t+1);
    
    printf("%s\n", sol[verificar() ? 0: 1]);
    
    
  }
}
