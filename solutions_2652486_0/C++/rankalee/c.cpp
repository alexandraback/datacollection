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

int r, n, m, k, p[10], cd[10];
map<vi, double> pa;

void rec(int cur, int cp){
	if(cur == n){
		vi v;
		rep(i, n) v.pb(cd[i]);
		sort(all(v));
		
		map<int, double> a;
		rep(i, 1 << n){
			int prod = 1;
			rep(j, n) if(i & 1 << j) prod *= cd[j];
			a[prod] += 1.0 / (1 << n);
		}
		double pb = 1;
		rep(i, k) pb *= a[p[i]];
		pa[v] += pb;
	}
	else for(int i = 2; i <= m; i++){
		cd[cur] = i;
		rec(cur + 1, cp * i);
	}
}
void run(){
	pa.clear();
	rep(i, k) cin >> p[i];
	rec(0, 1);
	double mx = 0;
	vi ans;
	each(i, pa) if(i->second > mx) mx = i->second, ans = i->first;
	rep(i, n) cout << ans[i] << (i == n - 1 ? "\n" : "");
}

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ": " << endl;
		cin >> r >> n >> m >> k;
		rep(i, r) run();
	}
	return 0;
}
