#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)
typedef long long ll;

class State{
public:
  int x,y;
  int cnt;
  string move;
  State(int _x, int _y , string _s){
    x = _x;
    y = _y;
    move = _s;
    cnt = 0;
  }
};
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};
string ns = "NESW";
bool closed[410][410][510];
int gx,gy;
queue<State> open;
string solve(){
  while(!open.empty())open.pop();
  memset(closed, 0 , sizeof(closed));
  open.push(State(200,200,""));
  while(!open.empty()){
    State st = open.front();open.pop();
    if(st.cnt >= 501){
      cout<<"miss"<<endl;
      return "";
    }

    if(st.x == gx && st.y == gy)return st.move;
    if(!(0 <= st.x && st.x <= 400 && 0 <= st.y && st.y <= 400))continue;
    if(closed[st.x][st.y][st.cnt])continue;
    closed[st.x][st.y][st.cnt] = true;
    rep(i,4){
      State nt = st;
      nt.x += nx[i] * (st.cnt+1);
      nt.y += ny[i] * (st.cnt+1);
      nt.cnt++;
      nt.move += ns[i];
      open.push(nt);
    }
  }
  return "";
}

int main(){
  int T;
  cin>>T;
  int C = 1;
  while(T--){
    cin>>gx>>gy;
    gx += 200;
    gy += 200;
    string res = solve();
    cout<<"Case #"<<C<<": ";
    cout<<res<<endl;
    C++;
  }
}
