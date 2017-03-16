#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <string>
#include <fstream>
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPP(k,a,b) for(int k= (a); k < (b); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;
template <class T>
void print(vector<T> v){ bool first=true; for(T x : v) { if(!first) cout << " "; first = false; cout << x; } cout << endl;}

ll reverse(ll n){
  if(n < 10) return n;
  ll ans = 0;
  while(n > 0){
    ans *= 10;
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
int main(){
  int T;
  ifstream fin("a.in");
  ofstream fout("a.out");
  fin >> T;
  vector<ll> dp(20000000, 1e15);
  dp[1] = 1;
  REPP(i, 1, 1e7){
    if(1+dp[i] < dp[i+1]){
      dp[i+1] = dp[i]+1;
    }
    ll x = reverse(i);
    if(x > 1e7) continue;
    if(dp[x] > dp[i] + 1){
      dp[x] = dp[i]+1;
    }
  }
  REP(t, T){
    ll N;
    fin >> N;
    queue<pair<ll, int>> q;
    q.push(mp(N,0));
    unordered_set<int> visited;
    visited.insert(N);
    while(!q.empty()){
      auto p = q.front();
      q.pop();
      ll x; int s;
      x = p.first;
      s = p.second;
      if(x < 1e8){
        fout << "Case #" << (t+1) << ": " << dp[x]+s <<  std::endl;
        break;
      }
      if(x % 10 != 0)
      {
        ll r = reverse(x);
        if(r < x && visited.find(r) == visited.end()){
          visited.insert(r);
          q.push(mp(r, s+1));
        }
      }
      if(visited.find(x-1) == visited.end())
        visited.insert(x-1);
        q.push(mp(x-1, s+1));
    }
  }
	return 0;
}
