#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int ntests;
	int n, s, p, sum;
	int surprise, nosurprise;
	
	scanf("%d", &ntests);
	for (int test = 1; test <= ntests; test++) {
		scanf("%d %d %d", &n, &s, &p);
		
		nosurprise = surprise = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &sum);
			
			if (sum == 0) {
				if (p == 0) nosurprise++;
				continue;
			}
			
			if (sum / 3 >= p) {
				nosurprise++;
			} else if (sum % 3 == 0 && sum / 3 == p - 1) {
				surprise++;
			} else if (sum % 3 == 1 && sum / 3 >= p - 1) {
				nosurprise++;
			} else if (sum % 3 == 2) {
				if (sum / 3 >= p - 1) nosurprise++;
				else if (sum / 3 >= p - 2) surprise++;
			}
		}
		
		printf("Case #%d: %d\n", test, nosurprise + min(surprise, s));
	}
	return 0;
}
