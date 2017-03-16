#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define LIMIT 100

using namespace std;

map<int, map<int, map<int, int> > > used;

struct path {
  string locations;
  int x, y;
  int turn;
  int destx, desty;
};

bool operator<(const path& lhs, const path& rhs)
{
  int first = lhs.locations.length();
  int second = rhs.locations.length();

  //first += lhs.destx - lhs.x + lhs.desty - lhs.y;
  //second += rhs.destx - rhs.x + rhs.desty - rhs.y;

  return first > second;
}

typedef struct path path;

path AStar(int destx, int desty) {
  priority_queue<path> q;
  path start;
  start.x = start.y = 0;
  start.destx = destx;
  start.desty = desty;
  start.turn = 1;
  q.push(start);

  while (!q.empty()) {
    path cur = q.top();
    q.pop();

    //cout << cur.x << " " << cur.y << endl;

    if (cur.x == destx && 
	cur.y == desty) {
      return cur;
    }

    if (used.find(cur.x) == used.end() ||
	used[cur.x].find(cur.y) ==
	used[cur.x].end() ||
	used[cur.x][cur.y].find(cur.turn) ==
	used[cur.x][cur.y].end()) {

    }
    else {
      continue;
    }

    used[cur.x][cur.y][cur.turn] = 1;
    
    if (cur.x <= LIMIT &&
	cur.y <= LIMIT &&
	cur.x >= -LIMIT &&
	cur.y >= -LIMIT &&
	cur.turn <= 500) {      

      path north, east, south, west;
      north = east = south = west = cur;    

      north.y += north.turn;
      east.x += east.turn;
      south.y -= south.turn;
      west.x -= west.turn;

      north.turn++;
      south.turn++;
      east.turn++;
      west.turn++;

      north.locations += "N";
      south.locations += "S";
      east.locations += "E";
      west.locations += "W";

      q.push(north);
      q.push(south);
      q.push(east);
      q.push(west);
    } 
  }
  
  path empty;
  return empty;
}

int main(int argc, char *argv[]) {
  int n_cases;
  cin >> n_cases;

  for (int i = 0; i < n_cases; i++) {
    int destx, desty;
    
    cin >> destx >> desty;
    cout << "Case #" << (i+1) <<  ": ";

    path a = AStar(destx, desty);
    cout << a.locations << endl;
    used.clear();
  }
}
