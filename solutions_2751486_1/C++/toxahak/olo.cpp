#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iomanip> 
#include <ctime>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second 

typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii; 
const int INF=~(1<<31);
const double eps=1e-6;
 
const long double PI = 3.1415926535;
 
ll f(string s,int n){
	ll ans = 0;
	int from, len, prev = -1;
	string now;
	set<pair<int,int> > pos;
	rep(i,s.sz){
		now.pb(s[i]);
		if(s[i]=='a' || s[i]=='e' || s[i]=='u' || s[i]=='o' || s[i]=='i' ){
			if(now.sz >= n)
				pos.insert(mp(i - now.sz + 1, now.sz - 1));			
			now.clear();
		}		
	}
	if(now.sz >= n)
		pos.insert(mp(s.sz - now.sz, now.sz));
	for(set<pair<int,int> >::iterator it = pos.begin();  it != pos.end(); it++) {
		from = it->X;
		len = it->Y;
		for(int j = 0; j <= len - n; j++) {
			ans += (from + j - (prev + 1) + 1) * (s.sz - (from + j + n) + 1);
			prev = from + j;
		}
	}
	return ans;
}
int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  int n,m;
  int q,Q;
  cin>>Q;
  FOR(q,1,Q){
	printf("Case #%d: ",q);
	string s;
	cin>>s>>n;
	cout<<f(s,n)<<'\n';
  }
  return 0;
}
