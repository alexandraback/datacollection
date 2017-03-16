#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1003;
int x[N];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t, n;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
        int ans = 1;
		for(int i = 0; i < n; i++) {
			scanf("%d", x+i);
            ans = max(ans, x[i]);
        }
        for(int i = ans; i >= 1; i--) {
            int cnt = i;
            for(int j = 0; j < n; j++)
                cnt += (x[j]-1)/i;
            ans = min(ans, cnt);
        }
		printf("Case #%d: %d\n", cas, ans);
	}
}
