#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int POS = 1000;
int gx, gy;

struct state{
  int y,x,d;
  state(int y=POS, int x=POS, int d=1):y(y),x(x),d(d){}
};

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int prev[POS*2][POS*2][2];

bool check(int y, int x){
  if(x < 0 || x >= POS*2) return false;
  if(y < 0 || y >= POS*2) return false;
  return true;
}

void print(){
  string str;
  int nowx = gx, nowy = gy;
  //cout << nowx-POS << ' ' << nowy-POS << endl;
  while(nowx != POS || nowy != POS){
    int prevx = prev[nowy][nowx][0];
    int prevy = prev[nowy][nowx][1];
    //cout << prevx-POS << ' ' << prevy-POS << endl;

    if(prevx < nowx) str += 'E';
    else if(prevx > nowx) str += 'W';
    else if(prevy < nowy) str += 'N';
    else if(prevy > nowy) str += 'S';
    nowy = prevy;
    nowx = prevx;
  }
  reverse(str.begin(),str.end());
  cout << str << endl;
}

void bfs(){
  queue<state> Q;
  state u,v;
  bool f[POS*2][POS*2];
  fill(f[0],f[POS*2],false);
  f[POS][POS] = true;

  for(Q.push(u); !Q.empty();){
    u = Q.front();
    Q.pop();

    if(u.y == gy && u.x == gx){
      print();
      return;
    }

    for(int i=0;i<4;i++){
      v = state(u.y+dy[i]*u.d, u.x+dx[i]*u.d, u.d+1);
      if(check(v.y,v.x) && !f[v.y][v.x]){
        f[v.y][v.x] = true;
        prev[v.y][v.x][0] = u.x;
        prev[v.y][v.x][1] = u.y;
        Q.push(v);
      }
    }
  }
}


int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    cin >> gx >> gy;
    gx += POS;
    gy += POS;
    cout << "Case #" << t << ": ";
    bfs();
  }
}
