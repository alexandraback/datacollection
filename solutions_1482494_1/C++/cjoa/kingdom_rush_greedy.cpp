#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

struct Ev {
   int level, stars;
   Ev( int _lvl, int _stars )
      : level(_lvl), stars(_stars) {}
   bool operator<(const Ev& ev) const {
      if (stars != ev.stars) return stars < ev.stars;
      return level < ev.level;
   }
};


int N;
PII V[1004];

#define INF 1000000000

vector<Ev> events[2];

int solve() {
   events[0].clear();
   events[1].clear();
   for (int i = 1; i <= N; ++i) {
      events[0].push_back(Ev(i, V[i].first));
      events[1].push_back(Ev(i, V[i].second));
   }
   sort(events[0].begin(), events[0].end());
   sort(events[1].begin(), events[1].end());
   int ncompleted = 0;
   vector<int> completed(N+1, 0);
   int res = 0;
   for (int stars = 0, i = 0, j = 0, t = 1; ncompleted < N; ++t) {
   // fprintf(stderr, "%d %d %d\n", i, j, stars);
      for (; j < events[1].size() && events[1][j].stars <= stars; ++j) {
         const Ev& ev1 = events[1][j];
         if (completed[ ev1.level ] == 2) continue;
         stars += completed[ ev1.level ] == 0 ? 2 : 1;
         completed[ ev1.level ] = 2;
         ++ncompleted;
         ++res;
      }
      if (i >= events[0].size())
         return INF;
      const Ev& ev0 = events[0][i];
      if (completed[ ev0.level ] >= 1) { ++i; continue; }
      stars++;
      completed[ ev0.level ] = 1;
      ++res;
      ++i;
   }
   if (ncompleted < N) return INF;
   return res;
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d", &N);
      for (int i = 1; i <= N; ++i)
         scanf("%d %d", &V[i].first, &V[i].second);
      int res = solve();
      if (res >= INF)
         printf("Case #%d: Too Bad\n", tc);
      else
         printf("Case #%d: %d\n", tc, res);         
   }
   return 0;
}
