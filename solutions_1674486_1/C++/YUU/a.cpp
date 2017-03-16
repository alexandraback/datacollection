#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define FOR(i, b, n) for(int i = b; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

const int N = 1000;
const int M = 999999;

int root[N][N], minimum[N];
vector<vector<int> > V;
bool flg[N];
int T;
int n;


int dijkstra(int start, int end){
  REP(i, n) flg[i] = 0, minimum[i] = M;

  minimum[start] = 0;

  REP(i, n){
    int mini = M, p = -1;
    REP(j, n)
      if(!flg[j] && mini > minimum[j])
	mini = minimum[j], p = j;

    if(p == -1) break;
    if(p == end) return mini;

    flg[p] = 1;
    REP(j, n)
      minimum[j] = min(minimum[j], minimum[p] + root[p][j]);
  }
  return minimum[end];
}

bool solve(int start){
  queue<int> Q;

  REP(i, n) minimum[i] = M;

  Q.push(start);
  while(!Q.empty()){
    int current = Q.front(); Q.pop();
    //cout << "current = " << current << ", size = " << V[current].size() << endl;
    REP(i, V[current].size()){
      if(minimum[V[current][i]] != M) return 1;
      minimum[V[current][i]] = 1;
      Q.push(V[current][i]);
    }
  }
  return 0;
}

int main(){
  while(cin >> T && T){
    REP(cases, T){
      V.clear();
      cin >> n;
      // REP(i, n) REP(j, n) root[i][j] = M;
      
      REP(i, n){
	vector<int> tmp;
	int m;
	cin >> m;
	
	REP(j, m){
	  int a;
	  cin >> a;
	  tmp.push_back(a - 1);
	  //root[j][a - 1] = 1;
	}
	V.push_back(tmp);
      }

      bool ans = 0;
      for(int i = 0; i < n && !ans; i++){
	//cout << "i = " << i << endl;
	ans = solve(i);
      }
      
      if(ans)
	cout << "Case #" << cases + 1 << ": Yes" << endl;
      else
	cout << "Case #" << cases + 1 << ": No" << endl;
    }
  }
  
  return 0;
}
