#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <ctime>
#include <complex>
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<int> pnt;
typedef pair<int, int> pii;

#define FOR(i,a,b) for(i=a;i<b;i++) 
#define RA(x) (x).begin(), (x).end()
#define REV(x) reverse(RA(x))
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define X first
#define Y second
#define MOD 1000000007
bool ispalin(int n){
	string s, t;
	stringstream ss; ss << n;
	ss >> s; t = s; REV(t);
	return s==t;
}
ll l, r;
vector<ll> v;
void solve(){
	int i, j;
	ll n;
	string s, t, m, x;
	FOR(i, 1, 10) if(sqrt(i)*sqrt(i) == i && ispalin(sqrt(i)))
		v.push_back(i);
	FOR(i, 1, 100){
		stringstream ss; ss << i;
		ss >> s; t = s;
		REV(t);
		x = s+t;
		ss.clear();
		ss << x; ss >> n;
		if(sqrt(n)*sqrt(n) == n && ispalin(sqrt(n)))
		v.push_back(n);
		FOR(j, 0, 100){
			ss.clear();
			ss << j; ss >> m;
			x = s+m+t;
			ss.clear();
			ss << x; ss >> n;
			if(sqrt(n)*sqrt(n) == n && ispalin(sqrt(n)))
			v.push_back(n);
		}
	}
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	solve();
	ll t=1, l, r, test, i;
	sort(RA(v));
	cin >> t;
	FOR(test, 0, t){
		cin >> l >> r;
		i =  upper_bound(RA(v), r) - lower_bound(RA(v), l);
		printf("Case #%lld: %lld\n", test+1, i);
	}
}


