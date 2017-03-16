#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
#include <string>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL INF = 1e16;

LL flip(LL x){
  LL res = 0;
  while(x > 0){
	res = res * 10 + x % 10;
	x /= 10;
  }
  return res;
}

const int MAX = 1000010;
LL ans[MAX];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  fill(ans, ans+MAX, INF);
  ans[1] = 1;
  for(int i=1;i<1000000;++i){
	ans[i+1] = min(ans[i+1], ans[i]+1);
	LL fl = flip(i);
	ans[fl] = min(ans[fl], ans[i]+1);
  }

  int T; cin >> T;
  FOR(t,1,T+1){
	LL N; cin >> N;
	
	cout << "Case #" << t << ": " << ans[N] << endl;
  }
  
  return 0;
}
