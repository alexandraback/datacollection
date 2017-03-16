#include <cstdio>
#include <cassert>
#include <string>


using namespace std;

int solve_2(int r, int c){
  int ans;
  if (r * c % 2 == 0){
    ans = 1;
  } else {
    ans = 0;
  }
  return ans;
}

int solve_3(int r, int c){
  int ans = 0;
  if (r * c % 3 == 0){
    if (r >= 3 || c >= 3){
      if (r >= 2 && c >= 2){
        ans = 1;
      }
    }
  }
  return ans;
}

int solve_4(int r, int c){
  int ans = 0;
  if (r * c % 4 == 0){
    if (r >= 4 || c >= 4){
      if (r >= 3 && c >= 3){
        ans = 1;
      }
    }
  }
  return ans;
}

int solve_5(int r, int c){
  int ans = 0;
  if (r * c % 5 == 0){
    if (r >= 5 || c >= 5){
      if (r >= 3 && c >= 3){
        ans = 1;
      }
    }
  }
  return ans;
}

int solve_6(int r, int c){
  int ans = 0;
  if (r * c % 6 == 0){
    if (r >= 6 || c >= 6){
      if (r >= 4 && c >= 4){
        ans = 1;
      }
    }
  }
  return ans;
}

int solve_problem()
{
  int ans;            // the answer (0 or 1, 0 means there is at least one choice that ensures victory for Richard)
  int x, r, c;
  assert(scanf("%d %d %d", &x, &r, &c) != EOF);
  switch (x){
  case 1:
    ans = 1;
    break;
  case 2:
    ans = solve_2(r, c);
    break;
  case 3:
    ans = solve_3(r, c);
    break;
  case 4:
    ans = solve_4(r, c);
    break;
  case 5:
    ans = solve_5(r, c);
    break;
  case 6:
    ans = solve_6(r, c);
    break;
  default:
    ans = 0;
  }
  return ans;
}


int main()
{
  int t;                  // the number of cases
  string ans;
  assert(scanf("%d\n", &t) != EOF);
  for (int i = 0; i < t; i++){
    if (solve_problem() == 0){
      ans = "RICHARD";
    } else {
      ans = "GABRIEL";
    }
    printf("Case #%d: %s\n", i + 1, ans.c_str());
  }
  return 0;
}
