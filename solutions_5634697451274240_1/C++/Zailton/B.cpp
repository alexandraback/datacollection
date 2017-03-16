#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++) 
#define FORR(i,b) FOR(i,0,b)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define CLR(x,e) memset(x, e, sizeof x)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll gcd (ll a, ll b) { return (b ? gcd (b, a%b) : a); }
ll mmc (ll a, ll b) { return a / gcd (a, b) * b; }

string str;
int n;

int solve (int x, int t) {
	if (x<0) return 0;
	if (t==0) {
		if (str[x]=='-') return solve (x-1, t);
		return solve (x-1, t^1) + 1;
	} else {
		if (str[x]=='+') return solve (x-1, t);
		return solve (x-1, t^1) + 1;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	
	int obj = (1<<10)-1;
	int L; cin>>L;
	FORR (caso, L) {
		cin>>str;
		n = sz(str);
		cout << "Case #" << caso+1 << ": ";
		cout << solve (n-1, 1) << endl;
	}
}	
