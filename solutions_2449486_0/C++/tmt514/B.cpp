#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

int n, m;
int a[105][105], f[105][105];
const int INF = 200;

bool checkrow(int i, int h) {
	for(int j=0;j<m;j++) if(a[i][j] > h) return false;
	for(int j=0;j<m;j++) f[i][j] = min(f[i][j], h);
	return true;
}
bool checkcol(int j, int h) {
	for(int i=0;i<n;i++) if(a[i][j] > h) return false;
	for(int i=0;i<n;i++) f[i][j] = min(f[i][j], h);
	return true;
}
void solve() {
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &a[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) f[i][j]=INF;
	for(int h=1;h<=100;h++) {
		for(int i=0;i<n;i++) checkrow(i,h);
		for(int i=0;i<m;i++) checkcol(i,h);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]!=f[i][j]) {
				puts("NO");
				return;
			}
	puts("YES");
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int cs=1;cs<=T;cs++) {
		printf("Case #%d: ", cs);
		solve();
	}
	return 0;
}
