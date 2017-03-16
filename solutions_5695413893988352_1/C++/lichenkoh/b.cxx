#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll INF=9223372036854775807LL;
ll n;
string a,b;
pair<ll,pair<ll,ll> > best;
void solve(ll x, ll y, ll k) {
	if (k==n) {
		pair<ll,pair<ll,ll> > cand=MP(abs(x-y),MP(x,y));
		best = min(best,cand);
		return;
	}
	x*=10; y*=10;
	if (x==y) {
		if (a[k]=='?'&&b[k]=='?') {
			solve(x+0,y+0,k+1);
			solve(x+0,y+1,k+1);
			solve(x+1,y+0,k+1);
		}
		else if (a[k]=='?'&&b[k]!='?') {
			ll d=b[k]-'0'; assert(0<=d&&d<10);
			ll l=max(d-1,0LL);
			ll h=min(d+1,9LL);
			for (ll z=l;z<=h;z++) {
				solve(x+z,y+d,k+1);
			}
		}
		else if (a[k]!='?'&&b[k]=='?') {
			ll d=a[k]-'0'; assert(0<=d&&d<10);
			ll l=max(d-1,0LL);
			ll h=min(d+1,9LL);
			for (ll z=l;z<=h;z++) {
				solve(x+d,y+z,k+1);
			}
		}
		else {
			solve(x+a[k]-'0',y+b[k]-'0',k+1);
		}
	}
	else if (x<y) {
		ll fst=(a[k]=='?')?9:a[k]-'0';
		ll sec=(b[k]=='?')?0:b[k]-'0';
		solve(x+fst,y+sec,k+1);
	}
	else if (x>y) {
		ll fst=(a[k]=='?')?0:a[k]-'0';
		ll sec=(b[k]=='?')?9:b[k]-'0';
		solve(x+fst,y+sec,k+1);
	}
	else assert(false);
}

int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		cin>>a>>b;
		n=a.length();
		assert(a.length()==b.length());
		best=MP(INF,MP(INF,INF));
		solve(0,0,0);
		string xans=to_string(best.second.first);
		string yans=to_string(best.second.second);
		while(xans.length()<n) {
			xans='0'+xans;
		}
		while(yans.length()<n) {
			yans='0'+yans;
		}
		cout << "Case #" << casenum << ": " << xans << " " << yans << endl;
	}
}
