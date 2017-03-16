#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <limits>

struct cell
{
  int F, C;
  double tm;
  bool vis;
};


cell Cm[100][100];

int dr[] = { -1,  0, 0, 1 };
int dc[] = {  0, -1, 1, 0 };
int R, C;
int ht;


void read_map()
{
  std::cin >> ht >> R >> C;
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++ c )
      std::cin >> Cm[r][c].C;
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++ c )
      std::cin >> Cm[r][c].F;
}


bool possible(int sr, int sc, int d, int w)
{
  int nr = sr + dr[d];
  int nc = sc + dc[d];
  if ( nc < 0 or nc >= C )
    return false;
  if ( nr < 0 or nr >= R )
    return false;
  cell const &next = Cm[nr][nc];
  cell const &curr = Cm[sr][sc];
  if ( w > next.C - 50 or curr.F > next.C - 50 or
      next.F > next.C - 50 or next.F > curr.C - 50 )
    return false;
  return true;
}

void clear()
{
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
    {
      Cm[r][c].vis = false;
      Cm[r][c].tm = 0;
    }
}

struct coords
{
  int R, C;
};


double wait_possible(int sr, int sc, int d, int w)
{
  int nr = sr + dr[d];
  int nc = sc + dc[d];
  if ( nc < 0 or nc >= C )
    return -1;
  if ( nr < 0 or nr >= R )
    return -1;
  cell const &next = Cm[nr][nc];
  cell const &curr = Cm[sr][sc];
  if ( curr.F > next.C - 50 or
      next.F > next.C - 50 or next.F > curr.C - 50 )
    return -1;
  if ( w <= next.C - 50 )
    return 0;
  double t = double(w - next.C + 50)/10;
  w -= 10*t;
  if ( w >= 0 and t >= 0 )
    return t;
  return -1;
}


std::vector<coords> get_possible(int w)
{
  clear();
  coords cur;
  cur.R = cur.C = 0;
  std::deque<coords> Q;
  Q.push_back(cur);
  std::vector<coords> res;
  while ( !Q.empty() )
  {
    cur = Q[0];
    Q.pop_front();
    if ( not Cm[cur.R][cur.C].vis )
    {
      Cm[cur.R][cur.C].vis = true;
      res.push_back(cur);
      for ( int d = 0; d < 4; ++d )
        if ( possible(cur.R, cur.C, d, w) )
        {
          coords nxt;
          nxt.R = cur.R + dr[d];
          nxt.C = cur.C + dc[d];
          Q.push_back(nxt);
        }
    }
  }
  return res;
}

struct state
{
  int R, C;
  double t;
};


bool operator<(const state &s1, const state &s2)
{
  return s1.t > s2.t;
}

double simu(int sr, int sc, int H)
{
  clear();
  state cur;
  cur.R = sr;
  cur.C = sc;
  cur.t = 0;
  std::priority_queue<state> Q;
  Q.push(cur);
  while ( !Q.empty() )
  {
    cur = Q.top();
    Q.pop();
    if ( cur.R == R -1 and cur.C == C - 1 )
      return cur.t;
    if ( not Cm[cur.R][cur.C].vis or Cm[cur.R][cur.C].tm > cur.t )
    {
      Cm[cur.R][cur.C].vis = true;
      Cm[cur.R][cur.C].tm = cur.t;
      int f = Cm[cur.R][cur.C].F;
      double w = std::max(H - 10*cur.t, 0.0);
      for ( int d = 0; d < 4; ++d )
      {
        double dt = wait_possible(cur.R, cur.C, d, w);
        if ( dt >= 0 )
        {
          state nxt;
          nxt.R = cur.R + dr[d];
          nxt.C = cur.C + dc[d];
          double nw = std::max(H - 10*(cur.t + dt), 0.0);
          if ( nw >= f + 20 )
            nxt.t = cur.t + dt + 1;
          else
            nxt.t = cur.t + dt + 10;
          Q.push(nxt);
        }
      }
    }
  }
  return -1;
}


double best_time(int H)
{
  std::vector<coords> r = get_possible(H);
  double best = std::numeric_limits<double>::max();
  for ( size_t i = 0; i < r.size(); ++i )
  {
    double x = simu(r[i].R, r[i].C, H);
    best = std::min(best, x);
  }
  return best;
}


double nxt_case()
{
  read_map();
  return best_time(ht);
}


int main()
{
  int T;
  std::cin >> T;
  std::cout.precision(15);
  for ( int t = 1; t <= T; ++t )
  {
    double x = nxt_case();
    std::cout << "Case #" << t << ": " << x << std::endl;
  }
  return 0;
}
