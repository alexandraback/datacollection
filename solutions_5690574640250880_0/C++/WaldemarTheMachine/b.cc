#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define FORR(i,n) for(int i = n-1;i >= 0;i--)
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000000

typedef long long LL;

bool f[5][5];
int r,c,m;

bool splithor(int lft, bool isFirst, int freeCnt, int mxUse) {
  // cerr << "call " << lft << ' ' << isFirst << ' ' << freeCnt << ' ' << mxUse << endl;
  if (freeCnt == 0) {
    return true;
  } else if (lft == 0)
    return false;

  for (int i = 2; i <= mxUse;i++) {
    if (isFirst && 2*i <= freeCnt) {
      FOR(j,i)
      f[r-lft][j] = true;
      FOR(j,i)
      f[r-lft+1][j] = true;

      if (splithor(lft - 2, false, freeCnt - 2*i, i))
        return true;

      FOR(j,i)
      f[r-lft][j] = false;
      FOR(j,i)
      f[r-lft+1][j] = false;
    } else
    if (!isFirst && i <= freeCnt) {
      FOR(j,i)
      f[r-lft][j] = true;

      if (splithor(lft - 1, false, freeCnt - i, i))
        return true;

      FOR(j,i)
      f[r-lft][j] = false;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  int ttt;
  
  cin >> ttt;
  FOR(tt,ttt) {
    cin >> r >> c >> m;
    int fr = r * c - m;

    cout << "Case #" << tt + 1 << ":\n";

    if (fr == 1) {
      FOR(i,r){
        FOR(j,c) {
          if (i == 0 && j == 0)
            cout << 'c';
          else
            cout << '*';
        }
        cout << '\n';
      }

      continue;
    }

    if (r == 1 || c == 1) {
      if (r == 1) {
        cout << 'c';
        FOR(i,fr-1)
        cout << '.';
        FOR(j,m)
        cout << '*';
        cout << '\n';
      } else {
        cout << "c\n";
        FOR(i,fr-1)
        cout << ".\n";
        FOR(j,m)
        cout << "*\n";
      }

      continue;
    }

    if ((fr == 2) || (fr == 3)) {
      cout << "Impossible\n";
      continue;
    }

    CLEAR(f);

    //cerr << "A " << r << ' ' << c << ' ' << m << endl;
    
    if (splithor(r, true, fr, c)) {
      // cout << "Sol1\n";

     // cerr << "HERE " << r << ' ' << c << endl;

      FOR(i,r) {
        FOR(j,c) {
          if (i == 0 && j == 0)
            cout << 'c';
          else if (f[i][j])
            cout << '.';
          else
            cout << '*';
        }
        cout << '\n';
      }

    } else {
      swap(r,c);
      if (splithor(r, true, fr, c)) {
        
        FOR(i,c) {
          FOR(j,r) {
            if (i == 0 && j == 0)
              cout << 'c';
            else if (f[j][i])
              cout << '.';
            else
              cout << '*';
          }
          cout << '\n';
        }

        //cout << "FUCK\n";
        //exit(0);

      } else {
        cout << "Impossible\n";
      }
    }
  }

  return 0;
}
