#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 1024
using namespace std;
int m, n;
bool isp(int n) {
	vector<int> d;
	while(n > 0) {
		d.push_back(n % 10);
		n /= 10;
	}
	for(int i = 0, j = d.size() - 1; i < j; ++i, --j) {
		if(d[i] != d[j])
			return false;
	}
	return true;
}
int main() {
	int T, cnt[MAXN];
	scanf("%d", &T);
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i * i < MAXN; ++i) {
		if(isp(i) && isp(i * i)) { 
			//printf("%d\n", i * i);
			++cnt[i * i];
		}
	}
	for(int i = 1; i < MAXN; ++i)
		cnt[i] = cnt[i] + cnt[i - 1];
	for(int cs = 1; cs <= T; ++cs) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", cs, cnt[b] - cnt[a - 1]);
	}
	return 0;
}
