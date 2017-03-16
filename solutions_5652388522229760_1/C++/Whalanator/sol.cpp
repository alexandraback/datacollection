#include <bits/stdc++.h>

using namespace std;

bool seen[10];

int main() {
	int n;
	int T;
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		cin >> n;
		fill(seen,seen+10,0);
		if (n) {
			for (int i=1;1;i++) {
				int j=i*n;
				while (j) {
					seen[j%10]=1;
					j/=10;
				}
				for (int j=0;j<10;j++) if (!seen[j])
					goto nex;
				printf("Case #%d: %d\n",cas,i*n);
				goto nexcase;
				nex:;
			}
		}
		else printf("Case #%d: INSOMNIA\n",cas);
nexcase:;
	}
}
