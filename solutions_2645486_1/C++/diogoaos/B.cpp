#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef long long lint;

const int MAXN = 10010;

pair<lint, lint> used_left[MAXN];

set<int> asc;
set<int, greater<int> > desc;

priority_queue< pair<int, int> > acts;

int main() {
	int ntests, n, v;
	lint r, e;
	lint ans;
	
	scanf("%d", &ntests);
	for (int test = 1; test <= ntests; test++) {
		printf("Case #%d: ", test);
		ans = 0;
		scanf("%I64d %I64d %d", &e, &r, &n);
		
		asc.clear();
		desc.clear();
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &v);
			acts.push(make_pair(v, i));
		}
		
		set<int>::iterator prev,nex;
		while (!acts.empty()) {
			pair<int, int> cur = acts.top(); acts.pop();
			
			prev = desc.lower_bound(cur.second);
			
			lint left = e;
			if (prev != desc.end()) {
				int pos = *prev;
				left = min(e, used_left[pos].second + (cur.second - pos) * r);
			}
			
			nex = asc.lower_bound(cur.second);
			
			lint must = 0;
			if (nex != asc.end()) {
				int pos = *nex;
				must = max(0LL, used_left[pos].second + used_left[pos].first - (pos - cur.second) * r);
			}
			
			lint used = max(left - must, 0LL);
			
			used_left[cur.second] = make_pair( used, left - used );
			
			//printf("coloquei energia %I64d na posicao (%d, %d), ans += %I64d\n", used, cur.second, cur.first, used * cur.first);
			
			ans += used * cur.first;
			
			desc.insert(cur.second);
			asc.insert(cur.second);
		}
		
		printf("%I64d\n", ans);
	}
	return 0;
}