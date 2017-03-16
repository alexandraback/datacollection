#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const double INF=10e10;

struct Tile {

  int fl;
  int ce;
  double mintime;

  Tile() {
    mintime=INF;
  }

  bool canMove(double h, Tile const& origin) {
    if(h<0) {
      h=0;
    }
    if(h>ce-50) {
      return false;
    }
    if(origin.fl>ce-50) {
      return false;
    }
    if(fl>ce-50) {
      return false;
    }
    if(fl>origin.ce-50) {
      return false;
    }
    return true;
  }

  bool canMove(Tile const& origin) {
    return canMove(-1000000, origin);
  }

  double minHeight() {
    return ce-50;
  }

  int speed(double h) {
    if(h<0) {
      h=0;
    }
    if(fl+20<=h) {
      return 1;
    }
    return 10;
  }

};



int H, N, M;

struct Coord {
  int x, y;

  Coord():x(0),y(0){};
  Coord(int x, int y):x(x),y(y){};

  bool move(int dir) {
    switch(dir) {
      case 0: return move(1, 0); break;
      case 1: return move(-1, 0); break;
      case 2: return move(0, 1); break;
      case 3: return move(0, -1); break;
    }
    return false;
  }

  bool move(int dx, int dy) {
    if(x+dx >= 0 && x+dx < N && y+dy >= 0 && y+dy < M) {
      x+=dx;
      y+=dy;
      return true;
    } else {
      return false;
    }
  }

  bool end() {
    return x==N-1 && y==M-1;
  }
};

vector<vector<Tile> > tiles;
Tile& getTile(Coord c) {
  return tiles[c.x][c.y];
}

//------------------
void floodfill() {
  queue<Coord> q;
  q.push(Coord(0, 0));
  while(!q.empty()) {
    Coord c = q.front();
    Tile& origin = getTile(c);
    q.pop();

    for(int i=0;i<4;++i) {
      Coord n = c;
      if(n.move(i)) {
        Tile& dest = getTile(n);
        if(dest.mintime > 0 && dest.canMove(H, origin)) {
          dest.mintime = 0;
          q.push(n);
          //cerr<<"Tile "<<n.x<<" "<<n.y<<" Time=0"<<endl;
        }
      }
    }
  }
}

bool step() {
  bool change = false;
  Coord candidateCoord;
  double candidateTime=INF;
  double _wait;
  double _speed;

  // Find all non-visited squares, compute next visit time
  for(int n=0;n<N;++n) {
    for(int m=0;m<M;++m) {
      Coord co(n, m);
      Tile& origin = getTile(co);
      if(origin.mintime == INF) {
        continue;
      }
      for(int i=0;i<4;++i) {
        Coord cd = co;
        if(! cd.move(i)) {
          continue;
        }
        Tile& dest = getTile(cd);
        if(dest.mintime != INF) {
          continue;
        }
        if(!dest.canMove(origin)) {
          continue;
        }
        double hnow = H-10*origin.mintime;
        double hmin = dest.minHeight();
        if(hmin > hnow) {
          hmin = hnow;
        }
        int speed = origin.speed(hmin);
        double arrivaltime = (H - hmin)/10. + speed;
        if(candidateTime > arrivaltime) {
          candidateTime = arrivaltime;
          change = true;
          candidateCoord = cd;
          _wait = hnow-hmin;
          _speed = speed;
        }
      }
    }
  }

  if(change) {
    getTile(candidateCoord).mintime = candidateTime;
    //cerr<<"Tile "<<candidateCoord.x<<" "<<candidateCoord.y<<" Time="<<candidateTime<<"  hdiff:"<<_wait<<" sp:"<<_speed<<endl;
  }
  return change;
}

double solve() {
  cin>>H>>N>>M;
  tiles = vector<vector<Tile> >(N, vector<Tile>(M));
  for(int n=0;n<N;++n) {
    for(int m=0;m<M;++m) {
      int cij;
      cin>>cij;
      tiles[n][m].ce = cij;
    }
  }
  for(int n=0;n<N;++n) {
    for(int m=0;m<M;++m) {
      int cij;
      cin>>cij;
      tiles[n][m].fl = cij;
    }
  }
  tiles[0][0].mintime = 0;
  floodfill();

  while(step());

  return tiles[N-1][M-1].mintime;
}

int main(int argc, char** argv) {

  int T;
  cin>>T;
  for(int t=0;t<T;++t) {
    double res = solve();
    cout<<"Case #"<<t+1<<": "<<res<<endl;
  }
  return 0;
}
