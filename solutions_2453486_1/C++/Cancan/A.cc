#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<int> VI;


int check(int x, int y, int z, int w)
{
  int t = x+y+z+w;
  int ret;
  switch (t) {
    case 4:
    case 33:
      ret = 1;
      break;
    case 20:
    case 45:
      ret = 2;
      break;
    default:
      ret = 0;
  }
  return ret;
}

int solve()
{
  int a[4][4];
  char c;
  int fflag = 1;
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) {
      cin >> c;
      switch (c) {
        case 'X':
          a[i][j] = 1;
          break;
        case 'T':
          a[i][j] = 30;
          break;
        case 'O':
          a[i][j] = 5;
          break;
        default:
          a[i][j] = 0;
          fflag = 0;
      }
    }

  int checkret;

  for (int i=0; i<4; i++)
  {
    checkret = check(a[i][0], a[i][1], a[i][2], a[i][3]);
    if (checkret)
      return checkret;
  }
  
  for (int i=0; i<4; i++)
  {
    checkret = check(a[0][i], a[1][i], a[2][i], a[3][i]);
    if (checkret)
      return checkret;
  }


  checkret = check(a[0][0], a[1][1], a[2][2], a[3][3]);
  if (checkret)
    return checkret;
  
  checkret = check(a[3][0], a[2][1], a[1][2], a[0][3]);
  if (checkret)
    return checkret;

  if (fflag)
    return 3;
  else
    return 0;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int m = solve();
    string ans;
    switch (m) {
      case 0:
        ans = "Game has not completed";
        break;
      case 1:
        ans = "X won";
        break;
      case 2:
        ans = "O won";
        break;
      case 3:
        ans = "Draw";
        break;    
    }
    printf("Case #%d: %s\n", i, ans.c_str());
  }
  return 0;
}

