#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

bool ok(ll m, ll r, ll t){
	double k = m;
	if(2 * r * k + 2 * (k - 1) * k + k > 2.1e18) return 0;
	return 2 * r * m + 2 * (m - 1) * m + m <= t;
}

void run(){
	ll r, t, lo = 1, hi = inf, mid;
	cin >> r >> t;
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(ok(mid, r, t)) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
}

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ": ";
		run();
	}
	return 0;
}
