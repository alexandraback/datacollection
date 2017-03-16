#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, T=1, n;
	char s1[22][22], s2[22][22];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%s %s", s1[i], s2[i]);
		int ans=0;
		for(int i=0; i<(1<<n); i++) {
			int v=__builtin_popcount(i), ok=1;
			if(v<=ans) continue;
			for(int j=0; j<n; j++) if((1<<j)&i) {
				int f1=0, f2=0;
				for(int k=0; k<n; k++) if(!((1<<k)&i)) {
					if(!strcmp(s1[j], s1[k])) f1=1;
					if(!strcmp(s2[j], s2[k])) f2=1;
					if(f1 && f2) break;
				}
				if(!f1 || !f2) {
					ok=0;
					break;
				}
			}
			if(ok) ans=v;
		}
		printf("Case #%d: %d\n", T++, ans);
	}
	return 0;
}
