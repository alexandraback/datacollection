#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		scanf("%d", &n);

		vector<int> counts;

		for (int i=0; i<n; i++) {
			int t; 
			scanf("%d", &t);
			if (t >= (int)counts.size())
				counts.resize(t+1, 0);
			//printf("%d ", t);
			counts[t]++;
		}
		//printf("\n");

		/*printf("%d %d  ", s, n);
		for (int i=n; i<=s and i<=n+(int)counts.size(); i++) {
			printf("%d %d  ", i, (s+i-1)/i + (i-n));
		}
		printf("\n");*/

		// This is based on the following assertions:
		// 1. If one plate of a given number of pancakes is split, all plates with at least as many pancakes are also split
		// 2. When splitting, it is never worth it adding pancakes to a non-empty plate
		// 3. If we are going to split, might as well split before the first minute

		int best = counts.size()-1;
		
		for (int i = 1; i < best; i++) {
			// We will try to have i normal turns, and therefore make everything at most i
			int c = 0; // Number of special turns
			for (int j = (int)counts.size()-1; j>i; j--) {
				int t = (j+i-1) / i; // Number of parts that we need to split j in to get all parts less than i (we need t-1 moves)
				c += (t-1) * counts[j];
				if (c > best)
					break;
			}
			best = min(best, c + i);
		}

		printf("Case #%d: %d\n", iC, best);
	}
	return 0;
}