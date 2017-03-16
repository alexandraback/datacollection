#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;

int T, n, m, cnt, a, b, r[10010], v[10010];
pair<int, PII> s[10000];

int main(){
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++){
		memset(r, 0, sizeof(r));
		memset(v, 0, sizeof(v));
		scanf("%d", &n);
		cnt = 0;
		for (int i = 0; i < n; i++){
			scanf("%d%d", &a, &b);
			s[cnt++] = mp(a, mp(1, i));
			s[cnt++] = mp(b, mp(2, i));
		}
		sort(s, s + cnt);
		int ans = cnt;
		for (int i = 1; i < cnt; i++) v[i] = v[i - 1] + 1;
		for (int i = cnt - 1; i >= 0; i--){
			if (s[i].first > v[i]){
				ans = -1;
				break;
			}
			r[i] = v[i] - s[i].first;
			if (s[i].second.first == 1){
				bool flag = true;
				for (int j = i + 1; j < cnt; j++){
					if (r[j] == 0){
						flag = false; break;
					}
					if (s[j].second.second == s[i].second.second) break;
				}
				if (flag){
					ans--; r[i] = cnt;
					for (int j = i + 1; j < cnt; j++){
						r[j]--;
						if (s[j].second.second == s[i].second.second) break;
					}
				}
			}
		}
		printf("Case #%d: ", ca);
		if (ans < 0) printf("Too Bad\n"); else printf("%d\n", ans);
	}
}
