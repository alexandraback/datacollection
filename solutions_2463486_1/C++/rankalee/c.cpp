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

void gen(ll n, ll &x, ll &y){
	char buf[100];
	sprintf(buf, "%lld", n);
	int m = strlen(buf);
	x = y = n;
	rep(i, m - 1) x *= 10, x += buf[m - i - 2] - '0';
	rep(i, m) y *= 10, y += buf[m - i - 1] - '0';
	x *= x; y *= y;
}
bool ok(ll n){
	char buf[100];
	sprintf(buf, "%lld", n);
	int m = strlen(buf);
	rep(i, m / 2) if(buf[i] != buf[m - i - 1]) return 0;
	return 1;
}

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ": ";
		
		int ans = 0;
		ll a, b;
		cin >> a >> b;
		for(ll i = 1; ; i++){
			ll x, y;
			gen(i, x, y);
			if(x > b) break;
			if(a <= x && x <= b && ok(x)) ans++;
			if(a <= y && y <= b && ok(y)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
