#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int T; cin>>T;
	for (int testCase=1; testCase<=T; testCase++) {
		vector<ll> ans;
		ll K, C, S, done=0; cin>>K>>C>>S;
		
		while (done<K) {
			ll before=0, tier=0;
			while (tier<C) {
				if (done<K) done++, before=before*K+done-1;
				else before=before*K;
				tier++;
			}
			ans.push_back(before+1);
		}
		
		printf("Case #%d:", testCase);
		if (ans.size()>S) printf(" IMPOSSIBLE");
		else for (int i=0; i<ans.size(); i++) printf(" %I64d", ans[i]);
		printf("\n");
	}
	return 0;
}
