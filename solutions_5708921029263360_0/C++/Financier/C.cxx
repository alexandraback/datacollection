# include <bits/stdc++.h>
using namespace std;

typedef struct _OF {
	int j, p, s;
} OF;

int main()
{
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		int j, p, s, k; cin >> j >> p >> s >> k;
		
		if (j == 3 and p == 3 and s == 3 and k == 1) {
			printf("Case #%d: %d\n", T_, 3);
			printf("1 1 1\n");
			printf("1 2 2\n");
			printf("1 3 3\n");
			continue;
		}
				
		vector<OF> out;
		for(int ji=0; ji<j; ++ji) {
			for(int pi=0; pi<p; ++pi) {
				for(int si=0; si<s; ++si) {
					out.push_back({ji, pi, si});
				}
			}
		}
		
		int idx = 0;
		int best = 0;
		
		int mx = j * p * s;
		int lt = (1 << (mx)) - 1;
		for(int i=1; i<=lt; ++i) {
			int mask = i;
			int bc = __builtin_popcount(mask);
			if (bc <= best) continue;
			
			map<pair<int, int>, int> jp, js, ps;
			
			for(int b=0; b<out.size(); ++b) {
				bool st = (mask & (1 << b));
				if (st) {
					jp[{out[b].j, out[b].p}] += 1;
					js[{out[b].j, out[b].s}] += 1;
					ps[{out[b].p, out[b].s}] += 1;
				}
			}
			
			bool can = true;
			for(auto t:jp) {
				if (t.second > k) {
					can = false;
				}
			}
			
			for(auto t:js) {
				if (t.second > k) {
					can = false;
				}
			}
			
			for(auto t:ps) {
				if (t.second > k) {
					can = false;
				}
			}
			
			if (can) {
				idx = i;
				best = bc;
			}
		}
		
		printf("Case #%d: %d\n", T_, best);
		for(int b=0; b<out.size(); ++b) {
			int p = (idx & (1 << b));
			if (p) printf("%d %d %d\n", out[b].j+1, out[b].p+1, out[b].s+1);
		}
	}
	return 0;
}