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

int K_l, L_l, S; 
string K, L;
int check(const string& s){
  int res = 0;
  for(int i=0;i+L_l<=SZ(s);++i){
	int j;
	for(j=0;j<L_l;++j)
	  if(L[j] != s[i+j]) break;
	if(j == L_l) ++res;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	cin >> K_l >> L_l >> S;
	cin >> K >> L;

	map<string, int> mem[2];
	int crt = 0, nxt = 1;
	mem[crt][""] = 1;
	for(int i=0;i<S;++i){
	  mem[nxt].clear();
	  for(auto& psi: mem[crt]){
		for(int j=0;j<K_l;++j){
		  string s = psi.first; s += K[j];
		  mem[nxt][s] += psi.second;
		}
	  }
	  swap(crt, nxt);
	}

	int mx = 0;
	double ans = 0;
	vector<PII> xs;
	for(auto& psi: mem[crt]){
	  int tmp = check(psi.first);
	  mx = max(tmp, mx);
	  xs.PB(MP(tmp, psi.second));
	}

	double sz = pow(K_l, S);
	for(auto& pii: xs)
	  ans += (mx - pii.first) * 1. * pii.second / sz;
	
	cout << fixed << setprecision(10) <<  "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
