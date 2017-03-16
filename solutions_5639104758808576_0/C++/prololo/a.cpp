#include <cstdio>

int solve_problem()
{
  int s_max;              // the max of s
  int ses[1000];          // the data
  int ans = 0;            // the answer
  int sum = 0;            // the sum of ses[j] (j < i)
  scanf("%d ", &s_max);
  for (int i = 0; i <= s_max; i++){
    ses[i] = getchar() - 48;   // ascii digit to int
  }
  getchar();              // remove a '\n'
  for (int i = 0; i <= s_max; i++){
    if (sum < i){
      ans += i - sum;
      sum = i;
    }
    sum += ses[i];
  }
  return ans;
}

int main ()
{
  int t;                  // the number of cases
  int ans;
  scanf("%d\n", &t);
  for (int i = 0; i < t; i++){
    ans = solve_problem();
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
