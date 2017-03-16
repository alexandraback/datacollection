#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


bool judge(const int& X, const int& R, const int& C) {
  if (R * C % X != 0 || X >= 7) {
    return true;
  }
  if (6 == X) {
    return (R <= 3 || C <= 3);
  }
  if (5 == X) {
    return (R <= 2 || C <= 2 || 15 == R * C); 
  }
  if (4 == X) {
    return (R <= 2 || C <= 2);
  }
  if (3 == X) {
    return (R == 1 || C == 1);
  }
  return false;
}

int main() {
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int N = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int X = 0;
    int R = 0;
    int C = 0;
    scanf("%d %d %d", &X, &R, &C);
    
    printf("Case #%d: %s\n", i + 1, judge(X, R, C) ? "RICHARD" : "GABRIEL");
  }
  return 0;
}
