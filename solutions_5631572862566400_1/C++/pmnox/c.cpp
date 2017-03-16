#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

#define rep(i,b) for(auto i=(0);i<(b);++i)
#define fo(i,a,b) for(auto i=(a);i<=(b);++i)
#define ford(i,a,b) for(auto i=(a);i>=(b);--i)
#define fore(a,b) for(auto a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int edge[11111];
int circle[11111];
int maxi[11111];

void solve() {
	int n;
	scanf("%d", &n);
	fo (i, 1, n) {
		scanf("%d", &edge[i]);
		circle[i] = -1;
		maxi[i] = 0;
	}
	vector<vi> ans;
	fo (i, 1, n) if (circle[i] == -1) {
		int cur = i;
		vi hmm;
		int ok = 0;
		rep (j, 2*n) {
			hmm.pb(cur);
			if (edge[cur] == i) {
				ok = 1;
				break;
			}
			cur = edge[cur];
		}
		if (ok) {
			ans.pb(hmm);
			fore (it, hmm)
				circle[*it] = hmm.size();
		}	
	}
	fo (i, 1, n) if (circle[i] == -1) {
		int cur = i;
		int len = -1;
		rep (j, n) {
			len += 1;
			if (circle[cur] != -1) {
				maxi[cur] = max(maxi[cur], len);
				break;
			}
			cur = edge[cur];
		}
	}
	int res = 0;
	int res2 = 0;
	fore (it, ans) {
		int cur_res = (*it).size();
		vi cand;
		db("");
		fore (jt, *it) {
			cand.pb(maxi[*jt]);
			db(*jt<<" "<<maxi[*jt]);
		}
		sort(all(cand));
		assert(cand.size() >= 2);
		if (cand.size() == 2) {
			cur_res += cand[cand.size() - 1] + cand[cand.size() - 2];
			res2 += cur_res;
		}

		res = max(res, cur_res);
	}
	printf("%d", max(res, res2));
}

int main(int argc, char ** argv) {
    ios::sync_with_stdio(false);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}
