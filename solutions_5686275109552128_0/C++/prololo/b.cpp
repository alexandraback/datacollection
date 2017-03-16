#include <cstdio>

// solve the problem (the number of plates that have i pancakes is p[i])
int solve(int m, int p[])
{
  int ans = m;           // the answer
  int next_m = 0;        // the second most number of pancakes on a plate
  int dummy[1000];       // p[] to give this function recursively
  int ans_n_div;         // the answer where you divide the mount of m pancakes by n 
  if (m > 1){
    for (int n = 2; n <= m; n++){
      for (int i = 0; i < m; i++){
        dummy[i] = p[i];
      }
      dummy[m / n + 1] += m % n * p[m];
      dummy[m / n] += (n - m % n) * p[m];
      for (int i = m - 1; i >= 0; i--){
        if (dummy[i] != 0){
          next_m = i;
          break;
        }
      }
      ans_n_div = solve(next_m, dummy) + (n - 1) * p[m];
      if (ans_n_div < ans){
        ans = ans_n_div;
      }
    }
  }
  return ans;
}

int solve_problem()
{
  int d;                  // the number of non-empty plates
  int p[1000];            // the number of pancakes on the ith plate
  int ans = 0;            // the answer
  int plates[1000];       // the number of plates that have j pancakes
  int m = 0;              // the max of pancakes on any plate
  if (scanf("%d\n", &d) == EOF){
    return -1;
  }
  for (int i = 0; i < d; i++){
    if (scanf("%d", &p[i]) == EOF){
      return -1;
    }
  }
  for (int j = 0; j < 1000; j++){
    plates[j] = 0;
  }
  for (int i = 0; i < d; i++){
    plates[p[i]]++;
    if (m < p[i]){
      m = p[i];
    }
  }
  ans = solve(m, plates);
  return ans;
}

int main()
{
  int t;                  // the number of cases
  int ans;
  if (scanf("%d\n", &t) == EOF){
    return -1;
  }
  for (int i = 0; i < t; i++){
    ans = solve_problem();
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
