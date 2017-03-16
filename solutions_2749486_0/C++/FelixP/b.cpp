#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define PI 3.14159265

#define REP(i,n) for(int i=0, _n=n; i<_n; ++i)
#define FOR(i,a,n) for(int i=a,_n=n; i<=_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define ALL(v) (v).begin(), (v).end()

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int x, y;
bool found;
void bfs(int a, int b, int jump, string ans) {
   if ( jump == 500 ) return;
   if ( a >= 1000 || b >= 1000 ) return;
   if ( found ) return;
//   printf("%d %d\n", a, b);
//   getchar();
   if ( a == x && b == y ) {
      printf("%s\n", ans.c_str());
      found = true;
      return;
   }



   bfs(a, b+jump, jump+1, ans + "N");
   bfs(a, b-jump, jump+1, ans + "S");
   bfs(a + jump, b, jump+1, ans + "E");
   bfs(a - jump, b, jump+1, ans + "W");
}

struct tdata {
   int x, y, jump;
   string ans;
};

string ans[260][260];
int main() {
   freopen("b-small.in", "r", stdin);
   freopen("b-small.out", "w", stdout);
   REP (i, 250) {
      REP (j, 250) {
         ans[i][j] = "?";
      }
   }

   queue<tdata> q;
   q.push((tdata){100, 100, 1, ""});

   while (!q.empty()) {
      tdata front = q.front(); q.pop();

      string currAns = front.ans;
      int a = front.x;
      int b = front.y;
      int j = front.jump;
      if ( j == 500 ) continue;
      if ( abs(a) > 1000 || abs(b) > 1000 ) continue;
      int nextJ = front.jump + 1;

      if ( a >= 0 && a < 250 && b >= 0 && b < 250 ) {
         if ( ans[a][b] != "?" ) continue;
         ans[a][b] = currAns;
         q.push((tdata){a, b+j, nextJ, currAns + "N"});
         q.push((tdata){a, b-j, nextJ, currAns + "S"});
         q.push((tdata){a+j, b, nextJ, currAns + "E"});
         q.push((tdata){a-j, b, nextJ, currAns + "W"});
      }


   }

   int T; scanf("%d", &T);

   int tcase = 0;
   while (T--) {
      found = false;
      scanf("%d %d", &x, &y);
      printf("Case #%d: ", ++tcase);
      printf("%s\n", ans[x+100][y+100].c_str());
   }
   return 0;
}
