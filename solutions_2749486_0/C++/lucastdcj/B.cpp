#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

#define TAM2 1000123
#define TAM 2048

int pred[TAM][TAM];
int pilhax[TAM2],pilhay[TAM2],pilhak[TAM2];
int foi[TAM][TAM];
char ans[TAM];
int x,y;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int bfs(int xx,int yy){
  pilhax[0] = xx;
  pilhay[0] = yy;
  pilhak[0] = 1;
  int k = 1;
  int cp = 0;
  int fimp = 1;
  while(cp < fimp){
    int ax = pilhax[cp];
    int ay = pilhay[cp];
    int ak = pilhak[cp];    
    if(ak < 500){
      for(int i = 0 ; i < 4 ; i++){
	int px = ax + dx[i]*ak;
	int py = ay + dy[i]*ak;
	if(px>= 0 && py >= 0 && px<TAM && py < TAM && fimp < TAM2 && !foi[px][py]){	
	  pred[px][py] = cp;
	  foi[px][py] = 1;
	  pilhax[fimp] = px;
	  pilhay[fimp] = py;
	  pilhak[fimp] = ak + 1;
	  fimp++;
	}
      } 
    }
    cp++;
  }
}

void dfs(int xx, int yy){
  if(xx == 1000 && yy == 1000) return;
  int px = pilhax[pred[xx][yy]];
  int py = pilhay[pred[xx][yy]];
  dfs(px,py);
  if(px < xx) printf("E");
  else if(px > xx) printf("W");
  else if(py > yy) printf("S");
  else printf("N");
}


int main(){
  int nt;
  scanf(" %d",&nt);
  int t = 1;
  memset(foi,0,sizeof(foi));
  bfs(1000,1000);

  while(nt--){
    scanf(" %d %d",&x,&y);
    printf("Case #%d: ",t++);
    dfs(x + 1000,y + 1000);
    printf("\n");
  }
  return 0;
}
