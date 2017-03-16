#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
bool used[555][444][444];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char dc[] = "NSEW";
int gx,gy;
int main(void){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    memset(used,false,sizeof(used));
    cin >> gx >> gy;
    gx += 200;
    gy += 200;
    queue<pair<string,pair<int,int> > > que;
    que.push(make_pair("",make_pair(200,200)));
    string s;
    while(!que.empty()){
      s = que.front().first;
      if(s.size() >= 500){
	s = "hoge";
	break;
      }
      int x = que.front().second.first;
      int y = que.front().second.second;
      //cout << s << "(" << x << "," << y << ")" << endl;
      que.pop();
      if(gx == x && gy == y) break;
      for(int i = 0; i < 4; i++){
	int nx = x + dx[i]*((int)s.size()+1);
	int ny = y + dy[i]*((int)s.size()+1);
	if(nx < 0 || ny < 0 || 400 <= nx || 400 <= ny) continue;
	if(used[(int)s.size()+1][nx][ny]) continue;
	used[(int)s.size()+1][nx][ny] = true;
	que.push(make_pair(s+dc[i],make_pair(nx,ny)));
      }
    }
    cout << "Case #" << t << ": " << s << endl;
  }
}
