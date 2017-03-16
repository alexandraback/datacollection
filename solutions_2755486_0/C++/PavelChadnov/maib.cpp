#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0;i<n;++i)
#define forv(i,n) for(int i=0;i<n.size();++i)
#define pb push_back
#define lng long long
#define mp make_pair



bool is_vowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int solve() {
	map<int, int> wall;
	int cnt;
	cin >> cnt;
	int res=0;
	vector<int> d(cnt);
	vector<int> n(cnt);
	vector<int> w(cnt);
	vector<int> e(cnt);
	vector<int> s(cnt);
	vector<int> delta_d(cnt);
	vector<int> delta_p(cnt);
	vector<int> delta_s(cnt);
	forn(i, cnt) {
		cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
		w[i]*=2;
		e[i]*=2;
		delta_p[i]*=2;
	}
	for(;;) {
		bool ok = false;
		forn(i,cnt)if(n[i])ok=true;
		if (!ok)break;

		int cur_day = -1;
		forn(i, cnt) {
			if (n[i]) {
				if (cur_day==-1 || d[i]<cur_day) {
					cur_day = d[i];
				}
			}
		}
		vector<int> attack;
		forn(i, cnt) {
			if (n[i]) {
				if (cur_day==d[i]) {
					attack.pb(i);
				}
			}
		}
		forv(iii, attack) {
			int i = attack[iii];
			int min_h = 2000000000;
			for(int j=w[i];j<=e[i];++j) {
				min_h = min(min_h, wall[j]);
			}
			if (min_h<s[i]) {
				++res;
			}
		}

		forv(iii, attack) {
			int i = attack[iii];
			int min_h = 2000000000;
			for(int j=w[i];j<=e[i];++j) {
				min_h = min(min_h, wall[j]);
			}
			if (min_h<s[i]) {
				for(int j=w[i];j<=e[i];++j) {
					if (wall[j]<s[i])wall[j]=s[i];
				}
			}
			--n[i];
			d[i]+=delta_d[i];
			w[i]+=delta_p[i];
			e[i]+=delta_p[i];
			s[i]+=delta_s[i];
		}
	}

	return res;
}

int main() {
#ifdef __ASD__ 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	int t=0;
	while (tc--) {
		int res = solve();
		++t;
		printf("Case #%d: %d\n", t, res);
	}


	return 0;

}