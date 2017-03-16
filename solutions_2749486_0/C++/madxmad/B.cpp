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
#include <stack>
#include <queue>
#include <map>

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
typedef vector<lld> vlld;

const int MAXN = 105;
int mark[2*MAXN][2*MAXN];
int dir[2*MAXN][2*MAXN];

int dx[] =  { 0,  0,  1,  0, -1};
int dy[] =  { 0,  1,  0, -1,  0};
char dc[] = {' ','N','E','S','W'};

bool valid(int n){
  if(0 <= n and n < 2*MAXN) return true;
  return false;
}

int precalculate(){
  queue<pair<pii,int> > Q;
  Q.push(mp(mp(MAXN,MAXN),1));
  mark[MAXN][MAXN] = 5;

  while(!Q.empty()){
    pii pos = Q.front().first;
    int c = Q.front().second;
    Q.pop();
    //cout << pos.first << " " << pos.second << endl;
    rep(k,1,4+1){
      int x = pos.first + c*dx[k];
      int y = pos.second + c*dy[k];
      if(!valid(x) or !valid(y)) continue;
      if(mark[x][y]) continue;
      mark[x][y] = c;
      dir[x][y] = k;
      //cout << x-MAXN << " " << y-MAXN << " " << k << endl;
      Q.push(mp(mp(x,y),c+1));
    }
  }
}

string solve(int x, int y){
  string ans = "";
  x += MAXN; y += MAXN;
  while(x != MAXN or y != MAXN){
    int c = mark[x][y];
    int d = dir[x][y];
    ans += dc[d];
    switch(d){
    case 1: y-=c; break;
    case 2: x-=c; break;
    case 3: y+=c; break;
    case 4: x+=c; break;
    }
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);

  precalculate();

  int T;
  cin >> T;

  rep(ncase,1,T+1){
    int x, y;
    cin >> x >> y;
    string ans = solve(x,y);

    cout << "Case #" << ncase << ": " << ans << endl;
    
  }
  return 0;
}
