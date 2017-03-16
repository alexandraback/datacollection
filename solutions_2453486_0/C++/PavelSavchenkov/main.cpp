#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;

char a[10][10];

bool IsWin (char c) {
  int cnt = 0;

  for (int i = 0; i < 4; i++)
    if  (a[i][i] == c || a[i][i] == 'T') cnt++;
  if  (cnt == 4) return true;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    if  (a[i][3 - i] == c || a[i][3 - i] == 'T') cnt++;
  if  (cnt == 4) return true;

  for (int i = 0; i < 4; i++) {
    cnt = 0;
    for (int j = 0; j < 4; j++)
      if  (a[i][j] == c || a[i][j] == 'T') cnt++;
    if  (cnt == 4) return true;
  }

  for (int j = 0; j < 4; j++) {
    cnt = 0;
    for (int i = 0; i < 4; i++)
      if  (a[i][j] == c || a[i][j] == 'T') cnt++;
    if  (cnt == 4) return true;
  }

  return false;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t; scanf("%d\n", &t);

  for (int test = 1; test <= t; test++) {
    for (int i = 0; i < 4; i++)
      gets(a[i]);
    scanf("\n");

    int emp = 0;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if  (a[i][j] == '.') emp++;

    string ans;
    if  (IsWin('X'))
      ans = "X won";
    else if (IsWin('O'))
      ans = "O won";
    else if  (emp == 0)
      ans = "Draw";
    else
      ans = "Game has not completed";

    printf("Case #%d: %s\n", test, ans.c_str()); 
  }

  return 0;
}
