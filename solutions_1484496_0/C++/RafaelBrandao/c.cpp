#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int cn, cases;
int n;
int num[20];
map<int, int> somas;

int main() {
	scanf("%d",&cases);
	while (cn++ < cases) {
		scanf("%d",&n);
		int sum = 0;
		for (int i=0; i < n; ++i) {
			scanf("%d",&num[i]);
		}
		bool ok = false;
		somas.clear();
		printf("Case #%d:\n",cn);
		for (int mask = (1<<n)-1; mask; --mask) {
			int k = 0;
			for (int i=0; i < n; ++i) {
				if ((mask>>i)&1) {
					k += num[i];
				}
			}
			if (somas.count(k)) {
				ok = true;
				int last = somas[k], first = 1;
				for (int i=0; i < n; ++i) {
					if ((last>>i)&1) {
						if (first) first = 0;
						else printf(" ");
						printf("%d",num[i]);
					}
				}
				printf("\n");
				first = 1;
				for (int i=0; i < n; ++i) {
					if ((mask>>i)&1) {
						if (first) first = 0;
						else printf(" ");
						printf("%d",num[i]);
					}
				}
				printf("\n");
				break;
			} else somas[k] = mask;
		}
		if (!ok) printf("Impossible\n");

		
	}

	return 0;
}
