#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int E,R,n;
int duty[10004];
int lefts[10004];

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++){
		vector<pair<int,int>> data;
		scanf("%d%d%d",&E,&R,&n);
		for(int i = 0; i < n; i++) {
			int v;
			scanf("%d",&v);
			duty[i] = 0;
			lefts[i] = E;
			data.emplace_back(v, i);
		}
		sort(data.begin(),data.end(),greater<pair<int,int>>());
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			long long v = data[i].first;
			int p = data[i].second;
			int left = lefts[p] - duty[p];
			if (left < 0) continue;
			ans += left * v;

			int margin = duty[p];
			for(int j = p; j < n; j++){
				lefts[j] = min(lefts[j], margin);
				margin += R;
				if (margin >= E) break;
			}

			int dv = E;
			for(int j = p; j >= 0; j--) {
				duty[j] = max(duty[j], dv);
				dv -= R;
				if (dv < 0) break;
			}
		}
		printf("Case #%d: %lld\n", testcase, ans);
	}
	return 0;
}
