#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<cstdlib>
#include<cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;

#define mp make_pair
#define pb push_back

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

ll n, a;
ll m[110];

void output(int cas, char *s){
	printf("Case #%d: %s\n", cas+1, s);
}
int solve(){
	if(a == 1) return n;
	ll ans = n;
	repp(sute, 0, n){
//cout << "sute: " << sute << endl;
		ll target = 0;
		ll tuika = 0;
		ll aa = a;
		while(target < n - sute){
//cout << "  target: " << target << endl;
			while(aa <= m[target]){
				tuika++;
				aa += aa-1;
//cout << "    tuika : a = " << a << endl;
			}
			aa += m[target];
			target++;
//cout << "   a = " << aa << endl;
		}
//cout << "  tuika+sute = " << tuika+sute << endl;
		ans = min(ans, tuika+sute);
	}
	return ans;
}

int main(){
	int casenum; cin >> casenum;
	rep(cas, casenum){
		cin >> a >> n;
		rep(i,n) cin >> m[i];
		sort(m, m+n);
//rep(i,n) cout << m[i] << ' '; cout << endl;
		printf("Case #%d: %d\n", cas+1, solve());
//		solve();
	}
	return 0;
}

