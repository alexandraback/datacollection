#include<iostream>
#include<queue>
#include<cstring>
#define r first
#define c second
using namespace std;
typedef pair<int,int> Data;
const double EPS = 1e-6;
const int BUF = 105, INF = 1<<30;



int row, col, H, HI[BUF][BUF], LO[BUF][BUF];

void read(){
  cin >> H >> row >> col;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> HI[i][j];

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> LO[i][j];
}



double calc(){
  bool visited[BUF][BUF];
  double cost[BUF][BUF];
  queue<Data> Q;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      visited[i][j] = false;
      cost[i][j] = INF;
    }

  // bfs
  Q.push(Data(0,0));
  
  visited[0][0] = true;
  cost[0][0] = 0;

  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();

    const int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
    for(int i=0;i<4;i++){
      int nr = cur.r+dr[i], nc = cur.c+dc[i];
      if(!(0<=nr && nr<row && 0<=nc && nc<col)) continue;
      if(min(HI[cur.r][cur.c],HI[nr][nc])-50<max(LO[cur.r][cur.c],LO[nr][nc])) continue;
      if(HI[nr][nc]-50<H) continue;
      if(visited[nr][nc]) continue;
      visited[nr][nc] = true;
      cost[nr][nc] = 0;
      Q.push(Data(nr,nc));
    }
  }

  // dijkstra
  memset(visited,0,sizeof(visited));

  while(1){
    int minR, minC;
    double minV = INF;
    for(int r=0;r<row;r++)
      for(int c=0;c<col;c++)
        if(!visited[r][c] && minV>cost[r][c]){
          minR = r;
          minC = c;
          minV = cost[r][c];
        }
      
    if(minR==row-1 && minC==col-1) 
      return minV;

    visited[minR][minC] = true;

    const int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
    for(int i=0;i<4;i++){
      int nr = minR+dr[i], nc = minC+dc[i];
      double curH = max(0.0,H-minV*10);
      if(!(0<=nr && nr<row && 0<=nc && nc<col)) continue;
      if(min(HI[minR][minC],HI[nr][nc])-50<max(LO[minR][minC],LO[nr][nc])) continue;

      double nexCost;
      double toWait; 

      if(HI[nr][nc]-50>curH)
        toWait = 0;
      else
        toWait = (curH-(HI[nr][nc]-50))/10;

      if(curH-toWait*10<LO[minR][minC]+20)
        nexCost = minV+10+toWait;
      else
        nexCost = minV+1+toWait;
      /*
      cout << curH << ' ' << HI[nr][nc] << '-' << HI[minR][minC] << ' ' << LO[nr][nc] << '-' 
           << LO[minR][minC] << ' ' << toWait << ' ' << nexCost-minV-toWait << endl;
      */
      cost[nr][nc] = min(cost[nr][nc],nexCost);
    }
  }
}


void work(int cases){
  cout << "Case #" << cases << ": ";
  cout << calc() << endl;
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
