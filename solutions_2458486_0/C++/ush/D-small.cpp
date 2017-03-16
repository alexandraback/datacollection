
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long ll;

int ans[210];
int keys[210];
int toOpen[210];
vector<int> have[210];
int n;
bool visited[1<<21];

bool solve(int k, int pat) {
  if(k == n)
    return true;
  if(visited[pat])
    return false;
  visited[pat] = true;
  
  REP(i, n){
    if((pat & (1 << i)) && keys[toOpen[i]] > 0){
      keys[toOpen[i]]--;
      REP(j, have[i].size())
	keys[have[i][j]]++;
      ans[k] = i;
      
      if(solve(k+1, pat ^ 1 << i))
	return true;
      
      keys[toOpen[i]]++;
      visited[i] = false;
      REP(j, have[i].size())
	keys[have[i][j]]--;
    }
  }
  return false;
}

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    memset(keys, 0, sizeof keys);

    int iniKeys;
    cin >> iniKeys >> n;
    REP(i, iniKeys){
      int v;
      cin >> v;
      keys[v-1]++;
    }
    
    REP(i, n){
      int k, nK;
      cin >> k >> nK;
      toOpen[i] = k-1;
      have[i].clear();
      REP(j, nK){
	int v;
	cin >> v;
	have[i].push_back(v-1);
      }
    }
    
    memset(visited, 0, sizeof visited);
    bool res = solve(0, (1 << n)-1);
    cout << "Case #" << (iCase+1) << ":";
    if(res){
      REP(i, n){
	cout << " " << ans[i]+1;
      }
      cout << endl;
    }else{
      cout << " IMPOSSIBLE" << endl;
    }
  }
  
  return 0;
}
