#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s[3010];
int T,t;

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	for (scanf("%d",&T),t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		memset(s,0,sizeof(s));
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n * 2 - 1; i++)
			for (int j = 1; j <= n; j++) {
				int a; scanf("%d",&a);
				s[a] ^= 1;
			}
		for (int i = 1; i <= 2501; i++)
			if (s[i]) printf("%d ",i);
		putchar('\n');
	}
	return 0;
}
