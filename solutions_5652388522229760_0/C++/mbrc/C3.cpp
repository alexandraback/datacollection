#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i<=(y); i++)
#define repe(i,x,y) for (int i = (x); i < (y);i++)
#define drep(i,x,y) for (int i = (x); i >= (y); i--)
#define mp make_pair
#define pb emplace_back
#define mt make_tuple
#define gcd __gcd
#define sf(n) scanf("%Lf",&n)
#define prf(n) printf("%.12Lf",n)
#define	s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define endc printf("\n")
#define psp printf(" ")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5 + 7;
const ll md = 1e9 + 7;
const int iter = 1000;
	
bool Z[20];

void addv(ll x) {

	string s = to_string(x);
	for (char c : s) {
		Z[c-'0'] = true;
	}
}

void solve(int tc) {
	ll n; cin>>n;

	//int n = tc;

	repe(j,0,20) Z[j] = false;

	ll j = 1;

	while (j <= iter) {
		addv(n*j);

		bool ok = true;

		repe(j,0,10) {
			if (!Z[j]) {
				ok = false; break;
			}
		}
		if (ok) {
			cout<<"Case #"<<tc<<": "<<n*j<<endl; return;
		}

		j++;
	}

	cout<<"Case #"<<tc<<": INSOMNIA"<<endl;
	assert(1==2);
}

int main() {
	 ios::sync_with_stdio(false); cin.tie(0);

	 int t; cin>>t;
	 rep(i,1,t) solve(i);
}
