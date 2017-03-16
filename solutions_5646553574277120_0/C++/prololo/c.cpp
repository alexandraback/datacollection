#include <cstdio>
#include <cassert>

void update(int den, int v, bool value[]){
  if (den > v) return;
  for (int i = v; i >= 1; i--){
    if (i+den > v) continue;
    if (value[i] && (i != den)){
      value[i+den] = true;
    }
  }
  value[den] = true;
  return ;
}

// only for small
int solve_problem ()
{
  int c, d, v;
  int denom[100];
  int ans = 0;
  assert(scanf("%d %d %d", &c, &d, &v)!=EOF);
  for (int i = 0; i < d; i++){
    assert(scanf("%d", &denom[i])!=EOF);
  }
  
  bool value[v+1]; // 1-indexed
  for (int i = 1; i <= v; i++){
    value[i] = false;
  }
  for (int j = 0; j < d; j++){
    int den = denom[j];
    update(den, v, value);
  }
  for (int i = 1; i <= v; i++){
    if (!value[i]){
      ans++;
      update(i, v, value);
    }
  }
  return ans;
}


int main ()
{
  int t;
  int ans;
  assert(scanf("%d", &t)!=EOF);
  for (int i = 1; i <= t; i++){
    ans = solve_problem();
    printf("Case #%d: %d\n", i, ans);
  }
}
