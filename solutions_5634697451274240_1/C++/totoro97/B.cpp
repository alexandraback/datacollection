#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[210];

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int t = 0,T;
	for (scanf("%d",&T), t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		memset(s,0,sizeof(s));
		scanf("%s",s + 1);
		int n = strlen(s + 1);
		int ans = 0;
		for (int i = 1; i < n; i++) 
			if (s[i] != s[i + 1]) ans++;
		if (s[n] == '-') ans++;
		printf("%d\n",ans);
	}
	return 0;
}
