#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

void work() {
	int n;
	scanf("%d",&n);
	vector<int> g(1010, 0);
	for(int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		g[i] = t;		
	}
	vector<vector<int> > f;
	vector<bool> flag;
	vector<int> status(n+10, 0);
	for(int i=1;i<=n;i++) {
		flag = vector<bool> (n+10, 0);
		int x = i;
		while (!flag[x] && status[x] == 0) {
			flag[x] = true;
			x = g[x];
		}
		if (flag[x] && status[x] == 0) {
			vector<int> tmp;
			int y = x;
			while(true) {
				tmp.push_back(y);
				y = g[y];
				status[y] = 1;
				if (y == x) break;
			}
			f.push_back(tmp);
		}
	}
	int ans = 0;
	for(int i=0;i<f.size();i++) {
		if (ans < f[i].size()) ans = f[i].size();
		
		if (f[i].size() == 2) {
			status[f[i][0]] = 2;
			status[f[i][1]] = 2;
		}
	}
	vector<int> cnt(n+10, 0);
	for(int i=1;i<=n;i++) {
		if (status[i] == 0) {
			int x = i;
			int now = 1;
			while (status[x] != 1 && cnt[x] < now) {
				cnt[x] = now;
				if (status[x] == 2) break;
				now ++;
				x = g[x];
			}
		}
	}
	for(int i=1;i<=n;i++) {
		if (status[i] == 2) {
			if (cnt[i] < 1) cnt[i] = 1;
		}
	}
	int tt = 0;
	for(int i=0;i<f.size();i++) {
		if (f[i].size() == 2) {
			tt += cnt[f[i][0]] + cnt[f[i][1]];
		}
	}
	ans = max(ans, tt);
	printf("%d\n", ans);
}

int main() {
	// freopen("input.txt","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int t;
	scanf("%d\n", &t);
	for(int i=0;i<t;i++) {
		printf("Case #%d: ", i+1);
		work();
	}

	return 0;
}

