#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <queue>
#define ll long long int
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;

map<pll,pll > M;

typedef struct {
  pll pos;
  ll dis;
} Point;

int x_mov[] = {1,-1,0,0};
int y_mov[] = {0,0,-1,1};
void bfs(pll fim) {
   
   queue<Point> fila;
   Point p;
   p.pos = pll(0,0);
   p.dis = 0;
   fila.push(p);
   
   int k;
   
   while (!fila.empty()) {
     p = fila.front();
     fila.pop();
     
     if (p.pos == fim)
      break;
     pll pos = p.pos;
     ll dis = p.dis + 1;
     
   //  cout<<pos.F<< " "<<pos.S<<" : "<<dis<<endl;
     for (k = 0; k < 4; k++) {
       pll npos = pos;
       npos.F += dis * x_mov[k];
       npos.S += dis * y_mov[k];
      
       if (M.find(npos) == M.end()) {
         M[npos] = pos;
         Point pp;
         pp.pos = npos;
         pp.dis = dis;
         fila.push(pp);
       }
     }     
   }
}

void doPath(pll p, pll ini) {
    
    if(p == ini)
      return; 
    
    pll parent = M[p];
    
    doPath(parent, ini);
    if(p.F < parent.F)
      printf("W");
    else if (p.F > parent.F)
      printf("E");
    else if (p.S < parent.S)
      printf("S");
    else
      printf("N");
}

int main() {
  
  int T;
  int i, j, k;
  
  cin>>T;
  map<char,bool> vog;
  
  for (k = 0; k < T; k++) {
    M.clear();
    pll fim;
    cin>>fim.F>>fim.S;
    bfs(fim);
    printf("Case #%d: ",k+1);
    doPath(fim, pll(0,0));
    printf("\n");
  }

  return 0;
}
