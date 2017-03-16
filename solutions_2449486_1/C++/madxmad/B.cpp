#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MAXN = 105;
int board[MAXN][MAXN];
int mark[MAXN][MAXN];
int row[MAXN];
int col[MAXN];

bool solve(int n,int m){
  memset(row,0,sizeof row);
  memset(col,0,sizeof col);
  
  REP(i,n) REP(j,m){
    row[i] = max(row[i],board[i][j]);
    col[j] = max(col[j],board[i][j]);
  }

  REP(i,n) REP(j,m)
    mark[i][j] = min(row[i], col[j]);
    
  REP(i,n) REP(j,m) if(board[i][j] != mark[i][j])
    return false;
  return true;
}

int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);

  int t;
  cin >> t;

  rep(ncase,1,t+1){
    int n, m;
    cin >> n >> m;

    REP(i,n) REP(j,m)
      cin >> board[i][j];

    bool b = solve(n,m);

    cout << "Case #" << ncase << ": ";
    if(b) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
