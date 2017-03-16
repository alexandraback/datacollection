#include <iostream>
#include <cstring>
#include <string>
#include <deque>

using namespace std;

int from[800][800][100];

struct nd {
  int x, y, ss;
  nd(){}
  nd(int x, int y, int ss) : x(x), y(y), ss(ss) {}
};

#define OX 400
#define OY 400
int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;++t) {
    int tx, ty;
    cin>>tx>>ty;
    memset(from,-1,sizeof(from));
    from[OX][OY][1] = -1;
    deque<nd> Q;
    Q.push_back(nd(0, 0, 1));
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    char dd[] = {'W', 'N', 'E', 'S'};
    int ess;
    while (!Q.empty()) {
      nd a= Q.front();
      Q.pop_front();
      if (a.x == tx && a.y == ty) {
        ess = a.ss;
        break;
      }
      for (int i=0;i<4;++i) {
        int nx = a.x + dx[i] * a.ss;
        int ny = a.y + dy[i] * a.ss;
        if (from[OX+nx][OY+ny][a.ss+1] != 0) {
          from[OX+nx][OY+ny][a.ss+1] = i;
          Q.push_back(nd(nx, ny, a.ss+1));
        }
      }
    }

    string ans;
    while (from[OX+tx][OX+ty][ess] != -1) {
      ans = string("") + dd[from[OX+tx][OX+ty][ess]] + ans;
      int d = (from[OX+tx][OX+ty][ess]+2)%4;
      --ess;
      nd next(tx+dx[d]*ess, ty+dy[d]*ess, ess);
      tx = next.x;
      ty = next.y;
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
