#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <queue>
#include <cctype>
#include <cstring>
using namespace std;
#define LL long long
const LL l1 = 1LL;
const int Len = 30;
const int inf = (1<<30);
int c, d, v;
int val[6];
bool has[Len+5], vis[Len+5];
bool tmphas[Len+5];
int ans, ans1;
void dfs(int lv, int cur)
{
	if (lv >= d) {
		if (cur <= v) {
			has[cur] = true;
		}
		return;
	}
	dfs(lv+1, cur);
	for (int i = 0; i < d; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(lv+1, cur+val[i]);
			vis[i] = false;
		}
	}
}
void dfs1(int lv, int sum, vector<int> curtmp)
{
	if (lv >= 3) {
		memset(tmphas, 0, sizeof(tmphas));
		for (int i = 1; i <= v; ++i) tmphas[i] = has[i];
		for (int i = 1; i <= v; ++i) {
			if (!has[i]) {
				for (int i = 0; i < curtmp.size(); ++i) {
					int curid = i + curtmp[i];
					if (curid <= v) {
						tmphas[curid] = true;
					}
				}
			}
		}
		bool flag = true;
		for (int i = 1; i <= v; ++i) {
			if (!tmphas[i]) {
				flag = false;
				break;
			}
		}
		if (flag) ans1 = min(ans1, sum);
		return;
	}
	dfs1(lv+1, sum, curtmp);
	for (int i = 1; i <= v; ++i) {
		if (!vis[i]) {
			curtmp.push_back(i);
			dfs1(lv+1, sum+1, curtmp);
			curtmp.pop_back();
		}
	}
}
void solve()
{
	bool f1 = false, f2 = false;
	for (int i = 0; i < d; ++i) {
		if (val[i] == 1) {
			f1 = true;
		}
		if (val[i] == 2) {
			f2 = true;
		}
	}
	if (v == 1) {
		if (f1) puts("0");
		else puts("1");
		return;
	}
	if (v == 2) {
		if (f1 && f2) puts("0");
		else if (!f1 && !f2) puts("2");
		else puts("1");
		return;
	}
	memset(has, 0, sizeof(has));
	memset(vis, 0, sizeof(vis));
	ans = 0;
	ans1 = inf;
	dfs(0, 0);
	memset(vis, 0, sizeof(vis));
	vector<int> tmp;
	tmp.clear();
	for (int i = 0; i < d; ++i) {
		vis[val[i]] = true;
	}
	if (!vis[1]) {
		vis[1] = true;
		++ans;
		tmp.push_back(1);
	}
	if (!vis[2]) {
		vis[2] = true;
		++ans;
		tmp.push_back(2);
	}
	dfs1(0, 0, tmp);
	if (ans1 != inf) ans += ans1;
	printf("%d\n", ans);
}
int main()
{
	freopen("E:\\My Code\\GCJ\\2015\\R1C\\C-small-attempt0.in", "r", stdin);
	freopen("E:\\My Code\\GCJ\\2015\\R1C\\C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d%d%d", &c, &d, &v);
		for (int i = 0; i < d; ++i) {
			scanf("%d", &val[i]);
		}
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}