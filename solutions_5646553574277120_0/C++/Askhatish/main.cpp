#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i,n) for((int)(i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define inf int(2e9)
#define sz(x) int((x).size())
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()

const double eps = 1e-9;
const double pi = acos(-1.0);
typedef long long ll;

int v;
vector<int> a;
bool u[50];

int get(){
 	memset(u, 0, sizeof u);
	u[0] = true;
	
	for(int i = 0; i < sz(a); ++i) {
	 	int x = a[i];
	 	for(int j = v; j >= 0; --j)
	 		if(u[j] && j + x <= v)
	 			u[j + x] = true;
	}
	for(int i = 0; i <= v; ++i)
		if(!u[i]) return i;

	return -1;
}


int main() {
	#ifdef LOCAL
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int T;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
	 	int c, d;
	 	cin >> c >> d >> v;
	 	for(int i = 0; i < d; ++i) {
	 	 	int x;
	 	 	cin >> x;
	 	 	a.pb(x);
	 	}
	 	int x = get();
	 	int ans = 0;
	 	while(x != -1) {
	 		a.pb(x);
	 		x = get(); 	
	 		ans++;
	 	}
	 	printf("Case #%d: %d\n", cs, ans);
	 	a.clear();
	}
	
	return 0; 
}