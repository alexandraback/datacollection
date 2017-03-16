#include <bits/stdc++.h>

using namespace std;

int T, n;
int a[50], cnt[2510];
vector <int> res;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for(int i = 0; i < 2*n-1; i ++) {
			for(int i = 0; i < n; i ++) {
				scanf("%d", &a[i]);
				cnt[a[i]] ++;
			}
		}
		res.clear();
		for(int i = 1; i <= 2500; i ++) if(cnt[i] % 2 == 1)
			res.push_back(i);
		sort(res.begin(), res.end());
		printf("Case #%d: ", cas);
		for(unsigned i = 0; i < res.size(); i ++)
			printf("%d%c", res[i], i == res.size()-1 ? '\n' : ' ');
	}
	return 0;
}
