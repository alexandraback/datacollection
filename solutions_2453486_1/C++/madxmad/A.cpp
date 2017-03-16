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

bool iswin(vs &board, char p){
  // rows
  REP(i,4){
    bool won = true;
    REP(j,4) if(board[i][j] != p and board[i][j] != 'T')
      won = false;
    if(won) return true;
  }

  // cols
  REP(j,4){ 
    bool won = true;
    REP(i,4) if(board[i][j] != p and board[i][j] != 'T')
      won = false;
    if(won) return true;
  }

  // diag
  bool won = true;
  REP(k,4) if(board[k][k] != p and board[k][k] != 'T')
    won = false;
  if(won) return true;

  won = true;
  REP(k,4) if(board[k][3-k] != p and board[k][3-k] != 'T')
    won = false;

  if(won) return true;
  else return false;
}

bool isfull(vs &board){
  REP(i,4) REP(j,4) if(board[i][j] == '.')
    return false;
  return true;
}

int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  int t;
  cin >> t;

  rep(ncase,1,t+1){
    vs board(4);
    REP(i,4) cin >> board[i];

    cout << "Case #" << ncase << ": ";

    if(iswin(board,'X'))
      cout << "X won" << endl;
    else if(iswin(board,'O'))
      cout << "O won" << endl;
    else if(isfull(board))
      cout << "Draw" << endl;
    else
      cout << "Game has not completed" << endl;
  }

  return 0;
}
