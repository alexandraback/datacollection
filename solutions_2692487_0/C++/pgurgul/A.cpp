#include <cstdio>
#include <algorithm>

#define N 1001

using namespace std;
int motes[N];
int min_ops[N];
int main() {
	
	int cases;

	scanf("%d", &cases);

	for(int z = 1; z <= cases; ++ z) {
		long long size;
		int n;
		scanf("%lld%d", & size, & n);

		for(int i = 0; i < n; ++ i) {
			scanf("%d", &motes[i]);
			min_ops[i] = 0;
		}
		sort(motes, motes+n);
		int ops = n;

		for (int i = 0; i < n; ++ i) {
	//		printf("S%lld M%d\n", size, motes[i]);
			if (i > 0) min_ops[i] = min_ops[i-1];
			if (size > motes[i]) {
				size += motes[i];				
			} else if (size == 1) {
			    ++min_ops[i];
			} else {
				while (size <= motes[i]) {
					size += size - 1;
					++ min_ops[i];
				}
				size += motes[i];
			}
		}

		for (int i = 0; i < n; ++ i) {
			 if (min_ops[i] + (n - i-1) < ops) {
				ops = min_ops[i] + (n-i-1);
			 }
		}

		printf("Case #%d: %d\n", z, ops);
	}
		
		
	return 0;
}
