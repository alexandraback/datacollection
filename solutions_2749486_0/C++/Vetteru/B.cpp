#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<map>

using namespace std;

const int BASE = 105;
const int MAX = 210;
const int INF = (1<<25);
const int LIM = 1000000;
string ans[MAX][MAX];



struct State{
  int x, y;
  string s;
  State(){}
  State(int x, int y, string s):x(x),y(y),s(s){}
};

bool isInside(int x, int y) {return 0<=x&&x<MAX&&0<=y&&y<MAX;}
bool isGone(int x, int y){ return abs(x) > 500 && abs(y) > 500;}
void make(){
  int dx[] = {1,-1,0,0};
  int dy[] = {0,0,1,-1};
  string ds = "EWNS";
  int cnt = 0;
  queue<State> Q;
  Q.push(State(0,0,""));

  while(!Q.empty()){
    State now = Q.front(); Q.pop();
    if(now.s.length() > 500) break;
    cnt++;
    if(cnt > LIM) break;
    //cout << now.x << " " << now.y << endl;
    int move = now.s.length()+1;
    for(int i = 0; i < 4; i++){
      State nex = now;
      nex.x += dx[i]*move;
      nex.y += dy[i]*move;
      nex.s += ds[i];
      if(isGone(now.x,now.y)) continue;
      if(isInside(nex.x+BASE,nex.y+BASE) && ans[nex.x+BASE][nex.y+BASE].length() != 0) continue;
      if(isInside(nex.x+BASE,nex.y+BASE) && ans[nex.x+BASE][nex.y+BASE].length() == 0){
	ans[nex.x+BASE][nex.y+BASE] = nex.s;
      }
      
      Q.push(nex);
    }
  }
}


int main(){
  make();
  int T;
  cin >> T;
  for(int i = 0; i < T; i++){
    int gx,gy;
    cin >> gx >> gy;
    // if(ans[gx+BASE][gy+BASE] == "") assert(false);
    cout << "Case #" << i+1 << ": " << ans[gx+BASE][gy+BASE] << endl;
  }
  return 0;
}
