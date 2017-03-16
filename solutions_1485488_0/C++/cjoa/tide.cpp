#include <cstdio>
#include <cstring>
#include <cmath>

#include <queue>
#include <vector>

using namespace std;

#define SZ(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int H, nRows, nCols;

struct Pos {
   int row, col;
   Pos(int _r, int _c) : row(_r), col(_c) {}
   bool is_valid() const {
      return 0 <= row && row < nRows && 0 <= col && col < nCols;
   }
};

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

int C[104][104];
int F[104][104];

int D1[104][104];
void bfs() {
   memset(D1, -1, sizeof(D1));
   D1[0][0] = 0;
   queue<Pos> q;
   q.push(Pos(0, 0));
   while (!q.empty()) {
      Pos cur = q.front();
      q.pop();
   // fprintf(stderr, "%d %d\n", cur.row, cur.col);
      REP(k, 4) {
         Pos nxt(cur.row + dr[k], cur.col + dc[k]);
         if (!nxt.is_valid())
            continue;
      // fprintf(stderr, "OK 1\n");

         if (C[cur.row][cur.col] - F[nxt.row][nxt.col] < 50)
            continue;
      // fprintf(stderr, "OK 2\n");

         if (C[nxt.row][nxt.col] - F[nxt.row][nxt.col] < 50 ||
             C[nxt.row][nxt.col] - F[cur.row][cur.col] < 50)
            continue;
      // fprintf(stderr, "OK 3\n");

         if (C[nxt.row][nxt.col] - H < 50)
            continue;

      // fprintf(stderr, "OK 4\n");
         if (D1[nxt.row][nxt.col] < 0) {
            D1[nxt.row][nxt.col] = D1[cur.row][cur.col] + 1;
            q.push(nxt);
         }
      }
   }
}

#define INF 1e12
#define EPS 1e-9

struct State {
   int row, col;
   double t;
   State(int _row, int _col, double _t) : row(_row), col(_col), t(_t) {}
   bool is_valid() const {
      return 0 <= row && row < nRows && 0 <= col && col < nCols;
   }
   bool operator<(const State &s) const {
      if (fabs(t - s.t) > EPS) return t > s.t;
      if (row != s.row) return row > s.row;
      return col > s.col;
   }
};

double D2[104][104];
double dijkstra() {
   priority_queue<State> pq;
   REP(r, nRows) REP(c, nCols)
      if (D1[r][c] >= 0) {
         D2[r][c] = 0.0;
         pq.push(State(r, c, 0.0));
      }
      else
         D2[r][c] = INF;
   while (!pq.empty()) {
      State cur = pq.top();
      pq.pop();
      double dist = D2[cur.row][cur.col];
//      fprintf(stderr, "* (%d,%d) %.3lf\n", cur.row, cur.col, dist);
      if (cur.row == nRows-1 && cur.col == nCols-1)
         return dist;
      if (dist < cur.t-EPS) continue;
      REP(k, 4) {
         State nxt(cur.row + dr[k], cur.col + dc[k], cur.t);
         if (!nxt.is_valid())
            continue;
      // fprintf(stderr, "OK 1\n");

         if (C[cur.row][cur.col] - F[nxt.row][nxt.col] < 50)
            continue;
      // fprintf(stderr, "OK 2\n");

         if (C[nxt.row][nxt.col] - F[nxt.row][nxt.col] < 50 ||
             C[nxt.row][nxt.col] - F[cur.row][cur.col] < 50)
            continue;
      // fprintf(stderr, "OK 3\n");

         if (C[nxt.row][nxt.col] - (H - cur.t*10) < 50-EPS) {
            // must wait
            double tt = (H - cur.t*10 + 50 - C[nxt.row][nxt.col]) / 10.0;
/*
            fprintf(stderr, "Waitng %.2lf at (%d,%d) -> (%d,%d)\n", wait_time,
                    cur.row, cur.col, nxt.row, nxt.col);
*/
            nxt.t = tt;
         }
      // fprintf(stderr, "OK 4\n");
/*
         if (cur.row == 2 && cur.col == 0)
            fprintf(stderr, " **  %d - %.3lf %.3lf = %.3lf - %d\n",
                    H, cur.t, nxt.t, H - nxt.t*10, F[cur.row][cur.col]);
*/
         nxt.t += (H - nxt.t*10 - F[cur.row][cur.col] >= 20-EPS) ? 1.0 : 10.0;
/*
         if (cur.row == 2 && cur.col == 0)
            fprintf(stderr, " **  %.3lf\n", nxt.t);
*/
         if (D2[nxt.row][nxt.col] > nxt.t + EPS) {
            D2[nxt.row][nxt.col] = nxt.t;
            pq.push(nxt);
         }

      }
   }
   return INF;
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d %d", &H, &nRows, &nCols);
      REP(r, nRows) REP(c, nCols)
         scanf("%d", &C[r][c]);
      REP(r, nRows) REP(c, nCols)
         scanf("%d", &F[r][c]);

      printf("Case #%d: ", tc);
      bfs();
      if (D1[nRows-1][nCols-1] >= 0)
         printf("0.0");
      else {
         double res = dijkstra();
         printf("%.6lf", res);
      }
      putchar('\n');
   }
   return 0;
}
