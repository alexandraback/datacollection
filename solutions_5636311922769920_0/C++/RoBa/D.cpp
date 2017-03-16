#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef long long LL;
LL tv[128];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int K, C, S;
		scanf("%d%d%d",&K,&C,&S);
		cout << "Case #" << ca << ":";
		if ((K + (C - 1)) / C > S) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		if (K == 1) {
			cout << " 1" << endl;
			continue;
		}
		LL tv = 0;
		vector<LL> ans;
		for (int i = 0 ; i < K ; ++i) {
			if (i && i % C == 0) {
				ans.push_back(tv);
				tv = 0;
			}
			tv = tv * K + i;
		}
		if (tv) ans.push_back(tv);
		for (int i = 0 ; i < ans.size() ; ++i) {
			cout << " " << ans[i]+1; 
		}
		cout << endl;
	}
	return 0;
}