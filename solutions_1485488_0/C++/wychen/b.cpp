#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef long long ll;

#define D 0

int H, N, M;

class loc {
public:
loc() : time(0), y(0), x(0) {}
loc(int _t, int _y, int _x) : time(_t), y(_y), x(_x) {}
loc(const loc& l) : time(l.time), y(l.y), x(l.x) {}

int time;
int y, x;
};

bool operator<(const loc &a, const loc &b) {
  if( a.time < b.time )
    return true;
  if( a.time > b.time )
    return false;
  if( a.y < b.y )
    return true;
  if( a.y > b.y )
    return false;
  return a.x < b.x;
}

int canwalk(int H, int time, loc from, loc to, const vector<vector<int> > &floor, const vector<vector<int> > &ceil) {
  //cerr << "to = " << to.y << " " << to.x << endl;
  //return 0;
  if(to.y<0) return -1;
  if(to.x<0) return -1;
  if(to.y >= floor.size()) return -1;
  //if(to.y >= N) return -1;
  //cerr << "to = " << to.y << " " << to.x << endl;
  if(to.x >= floor[0].size()) return -1;
  //cerr << "to = " << to.y << " " << to.x << endl;
  if(floor[to.y][to.x] > ceil[from.y][from.x] - 50) return -1;

  int low = floor[from.y][from.x];
  low = MAX(low, floor[to.y][to.x]);
  if(low > ceil[to.y][to.x] - 50) return -1;

  if(H <= (ceil[to.y][to.x] - 50)) return time;
  if ( H - (ceil[to.y][to.x] - 50) < from.time )
    return from.time;
  return H - (ceil[to.y][to.x] - 50);
}

bool trial(int H, int time, loc l, loc to, const vector<vector<int> > &floor, const vector<vector<int> > &ceil,
  set<loc> &locs, vector<vector<int> > &early
)
{
  cerr << "trial from = " << l.y << " " << l.x << " " << l.time << endl;
  cerr << "trial to = " << to.y << " " << to.x << endl;
  int newt = canwalk(H, l.time, l, to, floor, ceil);
  if(newt>=0) {
    to.time = newt;
    int water = H-to.time - floor[l.y][l.x];
    cerr << "trial newt = " << newt << endl;
    if(to.time > 0) {
      if(water >= 20)
        to.time += 10;
      else
        to.time += 100;
    }
    if(to.time < early[to.y][to.x]) {
      early[to.y][to.x] = to.time;
      if(to.y==floor.size()-1 && to.x==floor[0].size()-1) {
        cout << double(to.time)/10;
        return true;
      }
      cerr << "found to = " << to.y << " " << to.x << " at " << to.time << endl;
      locs.insert(to);
      FOREACH(it, locs) {
        cerr << "locs = " << it->y << " " << it->x << " " << it->time << endl;
      }
    }
  }
  return false;
}

void solve(bool skip)
{
  cin >> H >> N >> M;
  vector<vector<int> > floor(N, vector<int>(M)), ceil(N, vector<int>(M));
  REP(i, N)
    REP(j, M)
      cin >> ceil[i][j];
  REP(i, N)
    REP(j, M)
      cin >> floor[i][j];
  if(skip) return;

  set<loc> locs;
  vector<vector<int> > early(N, vector<int>(M));
  REP(i, N)
    REP(j, M)
      early[i][j] = 1<<30;
  locs.insert(loc(0,0,0));
  early[0][0] = 0;
  while(1) {
    typeof(locs.begin()) it = locs.begin();
    assert(it != locs.end());
    loc l = *it;
    loc to;

    to = l;
    to.y++;
    //cerr << "try to = " << to.y << " " << to.x << endl;
    if(trial(H, l.time, l, to, floor, ceil, locs, early)) break;
    to = l;
    to.y--;
    if(trial(H, l.time, l, to, floor, ceil, locs, early)) break;
    to = l;
    to.x++;
    if(trial(H, l.time, l, to, floor, ceil, locs, early)) break;
    to = l;
    to.x--;
    if(trial(H, l.time, l, to, floor, ceil, locs, early)) break;

    locs.erase(it);
  }
}

int main(int argc, char **argv)
{
  int T;
  cin >> T;
  int pick = 0;
  if(argc==2) pick = atoi(argv[1]);
  cout.precision(10);
  for(int i=0;i<T;i++) {
    bool skip = pick && (pick!=i+1);
    if(!skip) {
      cout << "Case #" << (i+1) << ": ";
    }
    solve(skip);
    if(!skip) {
      cout << endl;
    }
  }
}
