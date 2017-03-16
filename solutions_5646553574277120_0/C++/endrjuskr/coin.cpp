#include <iostream>

#include <vector>
using namespace std;

int main () {
	int t, c, d, v, a;

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i) {
		scanf("%d %d %d", &c ,&d ,&v);
		vector<int> plecak(v + 1, 0);
		plecak[0] = 1;
		while (d--) {
			scanf("%d", &a);
			for(int j = v; j >= 0; --j) {
				if((a + j) <= v && plecak[j] == 1) {
					plecak[a + j] = 1;
				}
			}
		}
		int res = 0;
		for(int j = 1; j <= v; ++j) {
			if(plecak[j] == 0) {
				++res;
				for(int k = v; k >= 0; --k) {
					if((j + k) <= v && plecak[k] == 1) {
						plecak[k + j] = 1;
					}
				}		
			}
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}