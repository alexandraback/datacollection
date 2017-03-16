#include <cstdio>
#include <cassert>

int solve_problem()
{
  int d;                  // the number of non-empty plates
  int p[1000];            // the number of pancakes on the ith plate
  int ans = 0;            // the answer
  int plates[1001];       // the number of plates that have j pancakes
  int m = 0;              // the max of pancakes on any plate
  int border;             // the maximum height 
  int cost = 0;               // the sum of special minutes
  assert(scanf("%d\n", &d) != EOF);
  for (int i = 0; i < d; i++){
    assert(scanf("%d", &p[i]) != EOF);
  }
  for (int j = 0; j < 1001; j++){
    plates[j] = 0;
  }
  for (int i = 0; i < d; i++){
    plates[p[i]]++;
    if (m < p[i]){
      m = p[i];
    }
  }
  ans = m;
  for (border = 1; border <= m; border++){
    cost = 0;
    for (int j = border + 1; j <= m;  j++){
      if (j % border == 0){
        cost += (j / border - 1) * plates[j];
      } else {
        cost += (j / border) * plates[j];
      }
    }
    if (border + cost < ans){
      ans = border + cost;
    }
  }
  return ans;
}


int main()
{
  int t;                  // the number of cases
  int ans;
  assert(scanf("%d\n", &t) != EOF);
  for (int i = 0; i < t; i++){
    ans = solve_problem();
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
