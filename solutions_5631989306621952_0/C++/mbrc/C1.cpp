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

void solve(int tc) {
	string s; cin>>s;
	string t = " "; t[0] = s[0];
	repe(i,1,s.size()) {
		string c = " "; c[0] = s[i];
		if (c[0] < t[0]) { t += c; }
		else { t = c + t; }
	}
	cout<<"Case #"<<tc<<": "<<t<<endl;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0);

	int t; s(t); rep(i,1,t) solve(i);
}
