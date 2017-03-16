#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, T=1, j, p, s, k, js[22][22], ps[22][22], jp[22][22];
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &j, &p, &s, &k);
		vector<pair<int, pair<int, int> > > ans;
		memset(js, 0, sizeof(js));
		memset(jp, 0, sizeof(jp));
		memset(ps, 0, sizeof(ps));
		for(int a=0; a<j; a++) for(int b=0; b<p; b++) for(int c=0; c<s; c++) if(js[a][c]<k && ps[b][c]<k && jp[a][b]<k) {
			ans.push_back(make_pair(a, make_pair(b, c)));
			js[a][c]++;
			ps[b][c]++;
			jp[a][b]++;
		}
		printf("Case #%d: %d\n", T++, (int)ans.size());
		for(int i=0; i<ans.size(); i++) printf("%d %d %d\n", ans[i].first+1, ans[i].second.first+1, ans[i].second.second+1);
	}
	return 0;
}
