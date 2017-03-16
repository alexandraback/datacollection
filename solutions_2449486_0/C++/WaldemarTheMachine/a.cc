#include <string> 
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#include <vector>  
#include <string.h>  
#include <utility>  
#include <queue>
#include <stack>
#include <iostream>  
#include <iomanip>  
#include <ctype.h>  
#include <sstream>  
#include <map> 
#include <set> 
#include <stdio.h>  
#include <ctype.h>  

using namespace std;

#define INF = 2000000000
#define FOR(i,n) for(int i = 0;i < n;i++)
#define CLEAR(x) memset((x),0,sizeof(x))
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()

typedef long long LL;

int a[100][100];

void solve(int tt){
  cout << "Case #" << tt << ": ";
  int n,m;

  cin >> n >> m;
  FOR(i,n){
    FOR(j,m){
      cin >> a[i][j];
    }
  }

  while (1){
    int mx = -1,my = -1, mv = 2000000;
    FOR(i,n){
      FOR(j,m){
        if (a[i][j] > -1 && a[i][j] < mv){
          mv = a[i][j];
          mx = i;
          my = j;
        }
      }
    }

    if (mx == -1){
      break;
    }

    int cnt = 0;
    FOR (i,n){
      if (a[i][my] == a[mx][my] || a[i][my] == -1)
        cnt++;
    }

    if (cnt == n){
      FOR(i,n)
      a[i][my] = -1;
      continue;
    }

    cnt = 0;
    FOR (i,m){
      if (a[mx][i] == a[mx][my] || a[mx][i] == -1)
        cnt++;
    }

    if (cnt == m){
      FOR(i,m)
      a[mx][i] = -1;
      continue;
    }

    cout  << "NO\n";
    return;

  }
  cout  << "YES\n";
}

int main() {
  int t;
  cin >> t;
  FOR(i,t){
    solve(i+1);
  }
  return 0;
}
