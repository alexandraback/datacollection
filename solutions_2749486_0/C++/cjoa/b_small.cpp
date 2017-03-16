#include <iostream>

#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef long long llong;

struct Pos {
   llong x, y;
   Pos(llong _x=0, llong _y=0) : x(_x), y(_y) {}
   bool operator<(const Pos& p) const {
      if (x != p.x) return x < p.x;
      return y < p.y;
   }
};

string sdir = "NESW";
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

string bfs(Pos src, Pos dst) {
   map<Pos, int> D;
   D[src] = 0;
   map<Pos, Pos> P;
   P[src] = 0;
   map<Pos, char> DIR;
   queue<Pos> q;
   q.push(src);
   while (!q.empty()) {
      Pos cur = q.front();
      q.pop();
      if (cur.x == dst.x && cur.y == dst.y) {
         string res;
         for (Pos t = dst; ; t = P[t]) {
            char c = DIR[t];
            if (c == 0) break;
            res += c;
         }
         reverse(res.begin(), res.end());
         return res;
      }
      int dist = D[cur];
      if (dist >= 500) return "WTF!!!";
      for (int k = 0; k < 4; ++k) {
         Pos nxt(cur.x + dx[k] * (dist+1), cur.y + dy[k] * (dist+1));
         if (D.count(nxt) == 0) {
            D[nxt] = dist + 1;
            P[nxt] = cur;
            DIR[nxt] = sdir[k];
            q.push(nxt);
         }
      }
   }
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
/*
   for (int x = 90; x <= 100; ++x)
      for (int y = 90; y <= 100; ++y)
         cerr << x << ' ' << y << ": " << bfs(Pos(0,0), Pos(x,y)) << endl;

   return 0;
*/

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      int X, Y;
      cin >> X >> Y;
      string res = bfs(Pos(0, 0), Pos(X, Y));
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
