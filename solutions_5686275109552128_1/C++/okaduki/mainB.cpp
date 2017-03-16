//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>
 
using namespace std;
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);


int dfs(int idx, VI& vi){
  if(vi[idx] == 0) return dfs(idx-1, vi);
  if(idx <= 3) return idx;

  int res = idx;
  for(int i=2;i<=idx/2;++i){
    vi[i] += vi[idx];
    vi[idx-i] += vi[idx];
    res = min(res, dfs(idx-1, vi) + vi[idx]);
    vi[i] -= vi[idx];
    vi[idx-i] -= vi[idx];
  }
  return res;
}

int main(){
  int T; cin >> T;
  FOR(t,1,T+1){
    int N; cin >> N;
    VI cnt(1001, 0);
    REP(i,N){ int x; cin >> x; ++cnt[x];}

    int ans = 1000;
    for(int c=1;c<=1000;++c){
      int sum = c;
      for(int i=1000;i>c;--i)
	sum += ((i + c - 1) / c - 1) * cnt[i];
      ans = min(ans, sum);
    }
    printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}
