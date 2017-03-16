#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n,m;
int dat[128][128];
int v[128][128];
vector<pair<int, pair<int,int>>> sorted;

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		scanf("%d%d",&n,&m);
		sorted.clear();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d",&dat[i][j]);
				sorted.emplace_back(dat[i][j], make_pair(i,j));
			}
		}
		sort(sorted.begin(),sorted.end());
		memset(v,0,sizeof(v));
		for(int i = 0; i < sorted.size(); i++) {
			auto cur = sorted[i];
			int cr = cur.second.first;
			int cc = cur.second.second;
			if (v[cr][cc]) continue;
			int flg;

			flg = 0;
			for(int i = 0; i < n; i++) {
				if (v[i][cc]) continue;
				if (dat[i][cc] != dat[cr][cc]) {
					flg = 1;
					break;
				}
			}
			if (flg == 0) {
				for(int i = 0; i < n; i++) {
					v[i][cc] = 1;
				}
			}
			flg = 0;
			for(int i = 0; i < m; i++) {
				if (v[cr][i]) continue;
				if (dat[cr][i] != dat[cr][cc]) {
					flg = 1;
					break;
				}
			}
			if (flg == 0) {
				for(int i = 0; i < m; i++) {
					v[cr][i] = 1;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (v[i][j] == 0) {
					ans = 1;
				}
			}
		}
		printf("Case #%d: %s\n", testcase, ans?"NO":"YES");
	}
	return 0;
}
