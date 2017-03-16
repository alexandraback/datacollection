#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int R, N, M, K;
double dp[5][130];
map<vector<int>, double> p;
map<vector<int>, double>::iterator itr;

double calc(vector<int> &lt, int target) {
  int v = 1;
  memset(dp, 0, sizeof(dp));
  dp[0][1] = 1.0;
  for (int i = 0 ; i < lt.size() ; ++i) {
    for (int j = 1 ; j < 130 ; ++j) {
      if (dp[i][j] == 0.0) continue;
      dp[i+1][j] += dp[i][j] * .5;
      dp[i+1][j*lt[i]] += dp[i][j] * .5;
    }
  }
  return dp[lt.size()][target];
}

void gen(int pos, int st, vector<int> &lt, int target) {
  if (pos == N) {
    double tmp = calc(lt, target);
    if (tmp == 0) tmp = -(1e100);
    else tmp = log(tmp);
    if (p.count(lt)) p[lt] += tmp;
    else p[lt] = tmp;
    return;
  }
  for (int i = st ; i <= M ; ++i) {
    lt.push_back(i);
    gen(pos+1, i, lt, target);
    lt.pop_back();
  }
}

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    printf("Case #%d:\n", ca);
    scanf("%d%d%d%d",&R,&N,&M,&K);
    for (int i = 0 ; i < R ; ++i) {
      p.clear();
      for (int j = 0 ; j < K ; ++j) {
        int target;
        scanf("%d",&target);
        vector<int> lt;
        gen(0, 2, lt, target);
      }
      double best = -(1e50);
      vector<int> best_ans;
      for (itr = p.begin() ; itr != p.end() ; ++itr) {
        //for (int i = 0 ; i < itr->first.size() ; ++i)
        //  printf("%d", itr->first[i]);
        //printf(": %f\n", itr->second); 
        if (itr->second > best) {
          best = itr->second;
          best_ans = itr->first;
        }
      }
      //printf("best_p:%f\n", best);
      for (int i = 0 ; i < best_ans.size() ; ++i)
        printf("%d",best_ans[i]);
      printf("\n");
    }
  }
  return 0;
}

