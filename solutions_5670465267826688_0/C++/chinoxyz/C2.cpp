#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());

lint T;
lint L,X,LX;
string s;
vector<int> ve;
int p[4][4] = {
{0,1,2,3},
{1,0,3,2},
{2,3,0,1},
{3,2,1,0}
};

int b[4][4] ={
{0,0,0,0},
{0,1,0,1},
{0,1,1,0},
{0,0,1,1}
};

int pi[4][4];

const int mn = 1e5+9;

int dp[5][mn][4][2];
bool visit[5][mn][4][2];
bool f(int k, int i, int v, int w){
  
  if(i >= ve.size() ){
    if(k == 4 && v == 0 && w == 0) return 1;
    return 0;
  }
  if(visit[k][i][v][w]) return dp[k][i][v][w];
  visit[k][i][v][w] = 1;
  int nv = p[v][ve[i]];
  int nw = (w+b[v][ve[i]])%2;
  bool res = 0;
  if(k == nv && nw == 0){
    res = res || f(k+1,i+1,0,0);
    
  }
  res = res || f(k, i+1, nv, nw);
  
  return dp[k][i][v][w] = res;
}

int h(char c){
  if(c == 'i') return 1;
  if(c == 'j') return 2;
  if(c == 'k') return 3;
}

bool solve(){
  LX = L*X;
  string vs;
  ve.clear();
  for(int i = 0; i < X; i++){
    vs += s;
  }
  for(int i = 0; i < vs.size(); i++){
    ve.pb(h(vs[i]));
  }
  /*for(int i = 0; i < ve.size(); i++){
    cout << ve[i] << " ";
  }cout << endl;*/
  memset(visit,0,sizeof(visit));
  int res = f(1,0,0,0);
  //cout << res << endl;
  return res;
}

int main(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      pi[i][p[i][j]] = j+1;
    }
  }
  
  cin >> T;
  for(int t = 0; t < T; t++){
    cin >> L >> X;
    cin >> s;
    printf("Case #%d: %s\n",t+1, solve()?"YES":"NO");
  }
  return 0;
}

