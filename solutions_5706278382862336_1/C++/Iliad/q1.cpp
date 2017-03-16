#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair

template<class P, class Q> inline bool mmin(P &a, Q b) { if (a > b){ a = b; return true;} return false;}
template<class P, class Q> inline bool mmax(P &a, Q b) { if (a < b){ a = b; return true;} return false;}

typedef long long LL;
typedef pair<int, int> pii;

const int MAXn = 100*1000;
const LL k = 1ll<<(40);
int n;
LL p, q;
string imp = "impossible";

inline void solve()
{
	LL tm = __gcd(p, q);
	p /= tm; q /= tm;
	if(k%q!=0) {
		cout << imp << endl;
		return;
	}
	p *= k/q;
	for(int i=1; i<=40; ++i) {
		LL x = (1ll<<(40-i));
		if(p>=x) {
			cout << i << endl;
			return;
		}
	}

	cout << imp << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;

	for(int ii=1; ii<=nt; ++ii) {
		string s;
		cin >> s;
		int ind = 0;
		p = q = 0;
		while(s[ind]!='/')
			p = p*10 + s[ind]-'0', ++ind;
		++ind;
		while(ind<s.size())
			q = q*10 + s[ind] - '0', ++ind;
		cout << "Case #" << ii << ": ";
		solve();
	}

	return 0;
}

