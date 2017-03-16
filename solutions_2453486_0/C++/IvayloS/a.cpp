#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

bool won(const vector<string>& a, char c) {
  for (int i=0;i<4;++i) {
    bool is = true;
    for (int j=0;j<4;++j) {
      if (a[i][j] != c && a[i][j] != 'T') {
        is = false;
        break;
      }
    }

    if (is) {
      return true;
    }
  }

  for (int i=0;i<4;++i) {
    bool is = true;
    for (int j=0;j<4;++j) {
      if (a[j][i] != c && a[j][i] != 'T') {
        is = false;
        break;
      }
    }

    if (is) {
      return true;
    }
  }

  bool diag = true;
  for (int i=0;i<4;++i) {
    if (a[i][i] != c && a[i][i] != 'T') {
      diag = false;
      break;
    }
  }

  if (diag) {
    return true;
  }

  diag = true;
  for (int i=0;i<4;++i) {
    if (a[i][3-i] != c && a[i][3-i] != 'T') {
      diag = false;
      break;
    }
  }

  if (diag) {
    return true;
  }

  return false;
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    vector<string> a(4);
    for(int i=0;i<4;++i){
      cin >> a[i];
    }

    string res;
    if (won(a, 'O')) {
      res = "O won";
    } else if (won(a, 'X')) {
      res = "X won";
    } else {
      bool has_dot = false;
      for (int i=0;i<4 && has_dot == false;++i) {
        for (int j=0;j<4;++j) {
          if (a[i][j] == '.') {
            has_dot = true;
            break;
          }
        }
      }

      if (has_dot) {
        res = "Game has not completed";
      } else {
        res = "Draw";
      }
    }
    cout<<"Case #"<<it<<": "<< res <<endl;
  }
  return 0;
}
