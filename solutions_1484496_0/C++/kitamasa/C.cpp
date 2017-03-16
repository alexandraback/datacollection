#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cassert>
#include <set>

using namespace std;

typedef long long ll;

ll vs[510];

int main() {
	int T;
	cin >> T;
	for(int c = 1; c <= T; ++c) {
		printf("Case #%d:\n", c);
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> vs[i];
		random_shuffle(vs, vs + n);
		set<ll> used;
		ll ok = 0;
		for(int i = 0; i < n && !ok; i += 20) {
			for(int j = 1; j < (1 << 20); ++j) {
				ll sum = 0;
				for(int k = 0; k < 20; ++k) if((j >> k) & 1) {
					sum += vs[i + k];
				}
				if(!used.insert(sum).second) {
					ok = sum;
					break;
				}
			}
		}
		assert(ok);
		vector<ll> res1, res2;
		for(int i = 0; i < n && res1.size() == 0 && res2.size() == 0; i += 20) {
			for(int j = 1; j < (1 << 20); ++j) {
				ll sum = 0;
				vector<ll> r;
				for(int k = 0; k < 20; ++k) if((j >> k) & 1) {
					sum += vs[i + k];
					r.push_back(vs[i + k]);
				}
				if(sum == ok) {
					if(res1.size() == 0) {
						res1 = r;
					}else {
						res2 = r;
						break;
					}
				}
			}
		}
		for(int i = 0; i < res1.size(); ++i) {
			if(i) printf(" ");
			printf("%lld", res1[i]);
		}
		puts("");
		for(int i = 0; i < res2.size(); ++i) {
			if(i) printf(" ");
			printf("%lld", res2[i]);
		}
		puts("");
	}
	return 0;
}
