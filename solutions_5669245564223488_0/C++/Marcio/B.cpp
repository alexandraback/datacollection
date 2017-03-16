#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < (b); ++i)
#define rep(i, n) fr(i,0,n)
#define _(n) rep(i, n)
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define SZ(x) int(x.size())
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long hash;
#define MOD 1000000007
vector<string> guys;
int n;

bool verify(const string& a){
	int cnt[300];
	memset(cnt, 0, sizeof cnt);
	bool dm = false;

	_(SZ(a)) ++cnt[a[i]];

	_(SZ(a)){
		if(cnt[a[i]] != 1 && (i+1 == SZ(a) || a[i+1] != a[i])) dm = true;
		else --cnt[a[i]];
	}

	return !dm;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	fr(tt, 1, 1+t){
		guys.clear();
		cin >> n;

		_(n){
			string a;
			cin >> a;
			guys.pb(a);
		}

		ll ans = 0;
		int p[10];
		_(n) p[i] = i;

		do{
			string a = "";
			_(n) a += guys[p[i]];
			ans += verify(a);
		}while(next_permutation(p, p+n));

		cout  << "Case #" << tt << ": " << ans << "\n";
	}

}

