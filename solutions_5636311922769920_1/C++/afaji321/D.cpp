#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
	int T;
	int K,C,S;
	scanf("%d",&T);
	for (int tt = 1 ;tt <= T;tt++) {
		printf("Case #%d:",tt);

		scanf("%d%d%d",&K,&C,&S);
		int res = (K + C - 1) / C;
		if (res > S) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		int ch = 0;
		long long pos = 1;
		for (int i=1;i<=K;i++) {
			pos = (pos - 1) * K + i;
			ch++;
			if (ch == C || i == K) {
				for (int j=ch;j<C;j++){
					pos = (pos - 1) * K;
					pos += i;
				}
				printf(" %lld",pos);
				ch = 0;
				pos = 1;
			}
			
		}
		printf("\n");

	}

}
