#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int ll;
typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

struct Move {
  int x_;
  int y_;
  int steps_;
  string direction_;
  Move (int x, int y, int s, string d) : x_(x), y_(y), steps_(s), direction_(d) {}
};

bool operator < (Move const& A, Move const& B) {
  if (A.steps_ != B.steps_)
    return A.steps_ < B.steps_;
  else {
    if (A.x_ != B.x_)
      return A.x_ < B.x_;
    else {
      if (A.y_ != B.y_)
        return A.y_ < B.y_;
      else
        return A.direction_ < B.direction_;
    }
  }
}

int main ()
{
  int dx[] = {0,0,1,-1};
  int dy[] = {1,-1,0,0};
  char d[] = {'N', 'S', 'E', 'W'};
  int T;
  cin >> T;
  REP(t, T) {
    map< pair<int,int>, pair<int, string> > M;
    cout << "Case #" << t+1 << ": ";
    int x, y;
    cin >> x >> y;
    set<Move> currSteps;
    currSteps.insert(Move(0, 0, 0, ""));
    bool found = false;
    while (!found) {
      Move f = *(currSteps.begin());
      currSteps.erase(currSteps.begin());
      //cout << "Currently at: " << f.x_ << "," << f.y_ << endl;
      REP(i, 4) {
        int X = f.x_+(f.steps_+1)*dx[i];
        int Y = f.y_+(f.steps_+1)*dy[i];
        //cout << "Visiting: " << X << "," << Y;
        char dir = d[i];
        //cout << ". dir: " << f.direction_ + dir << endl;
        if (X == x && Y == y) {
          found = true;
          cout << f.direction_ + dir << endl;
          break;
        }
        map< pair<int,int>, pair<int, string> >::iterator it = M.find(make_pair(X, Y));
        // if not found 
        if (it == M.end()) {
          M.insert(make_pair(make_pair(X, Y),make_pair(f.steps_+1, f.direction_+dir)));
          currSteps.insert(Move(X, Y, f.steps_+1, f.direction_+dir));
        }
      }
    }
  }
}
