#include<bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define VI vector<int>
#define clr(a) a.clear()
#define pob pop_back
#define pub push_back
#define eps 1E-5
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define full(a,l) a,a+l
#define fread(name) freopen(name,"r",stdin)
#define fwrite(name) freopen(name,"w",stdout)
#define sz(a) (int)a.size()
#define count_one __builtin_popcount
#define count_onell __builtin_popcountll
#define fastIO ios_base::sync_with_stdio(false)
#define PI (acos(-1.0))
#define linf (1LL<<62)//>4e18
#define inf (0x7f7f7f7f)//>2e9
#define fore(x,i) for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rfore(x,i) for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define For(i,a,b) for(int i=a;i<=b;++i)
#define rFor(i,a,b) for(int i=a;i>=b;--i)


///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
int K, TL, SL;
string keys;
string tword;

pii sol(int idx, string s) {
	if (idx == SL) {
		int ans = 0;
		For(i,0,SL-TL) {
			if (!s.compare(i, TL, tword))
				ans++;
		}
// put(s," #end",ans);
		return mp(ans, ans);
	}
	pii ans = mp(0, -inf);
	For(i,0,K-1) {
		pii tmp = sol(idx + 1, s + keys[i]);
		ans.sc = max(ans.sc, tmp.sc);
		ans.fs += tmp.fs;
	}
	return ans;
}

int main() {

	int T, t = 1;
	cin >> T;
	while (T--) {

		cin >> K >> TL >> SL;
		cin >> keys;
		cin >> tword;
		pii ans = sol(0, "");
		double ok = (double) ans.sc - double(ans.fs) / double(pow(K, SL));
		cout << "Case #" << t++ << ": " << setprecision(8) << ok << endl;
	}
	return 0;
}
